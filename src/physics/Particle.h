//
//  Particle.h
//  Apollo
//
//  Created by Colin Duffy on 10/1/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#include "Vec.h"
#include "MathUtil.h"

class Particle {
public:
	
	vec3f acc, pos, prev, vel;
	
	Particle() {
		pos = prev = vec3f::zero();
		vel = vec3f::zero();
		reset();
	}
	
	Particle( const vec3f& startPos ) {
		pos = prev = startPos;
		vel = vec3f::zero();
		reset();
	}
	
	virtual void reset() {
		acc = vec3f();
	}
	
	virtual void dampen(vec3f amt = vec3f(.01, .01, .01)) {
		acc = acc - vel * amt;
	}
	
	virtual float movement() {
		return acc.length() + vel.length();
	}
	
	virtual void spring(vec3f targetPos, vec3f strength = vec3f(0.05, 0.05, 0.05), vec3f damping = vec3f(0.05, 0.05, 0.05)) {
		vec3f dir = pos - targetPos;
		float dist = dir.length();
		dir.normalize();
		
		vec3f springF = -dist * strength;
		vec3f dampenF = -damping * (dir.x*vel.x + dir.y*vel.y + dir.z*vel.z);
		
		dir *= springF + dampenF;
		acc += dir;
	}
	
	virtual void update(const vec3f& time) {
		prev = pos;
		vel += acc * time;
		acc = vec3f::zero();
		
		pos += vel * time;
	}
	
	virtual void bounceOffWalls(vec3f min = vec3f::zero(), vec3f max = vec3f::zero(), vec3f damping = vec3f(0.01, 0.01, 0.01)) {
		// X
		if(pos.x < min.x) {
			pos.x = min.x;
			vel.x *= -damping.x;
		} else if(pos.x > max.x) {
			pos.x = max.x;
			vel.x *= -damping.x;
		}
		
		// Y
		if(pos.y < min.y) {
			pos.y = min.y;
			vel.y *= -damping.y;
		} else if(pos.y > max.y) {
			pos.y = max.y;
			vel.y *= -damping.y;
		}
		
		// Z
		if(pos.z > max.z) {
			pos.z = max.z;
			vel.z *= -damping.z;
		} else if(pos.z < min.z) {
			pos.z = min.z;
			vel.z *= -damping.z;
		}
	}
	
	virtual void constrain(vec3f bounds = vec3f::zero()) {
		pos = MathUtil::constrain(pos, bounds);
	}
	
	virtual void wrap(vec3f bounds = vec3f::one()) {
		pos = MathUtil::wrap(pos, bounds);
	}
	
	virtual bool dead() {
		return false;
	}
	
};
