//
//  Interpolation.h
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#pragma once

#import "MathUtil.h"
#include "Vec.h"

class Interpolation {
public:
	
	float			speed;
	float			spring;
	float			target;
	float			value;
	float			velocity;
	bool			complete;
	
	Interpolation() {
		speed		= 0.2;
		spring		= 0;
		value		= 0;
		target		= 1.;
		velocity	= 0;
		complete	= false;
	}
	
	void update() {
		velocity = (( target - value ) * speed ) + ( velocity * spring );
		value += velocity;
		complete = MathUtil::distance(value, target) < 0.001;
		if( complete ) value = target;
	}
	
};

class Interpolation2 {
public:
	
	float			speed;
	float			spring;
	vec2f			target;
	vec2f			value;
	vec2f			velocity;
	bool			complete;
	
	Interpolation2() {
		speed		= 0.2;
		spring		= 0;
		value		= vec2f(0, 0);
		target		= vec2f(1, 1);
		velocity	= vec2f(0, 0);
		complete	= false;
	}
	
	void update() {
		velocity = (( target - value ) * speed ) + ( velocity * spring );
		value += velocity;
		complete = MathUtil::distance2D(value, target) < 0.001;
		if( complete ) value = target;
	}
	
};


class Interpolation3 {
public:
	
	float			speed;
	float			spring;
	vec3f			target;
	vec3f			value;
	vec3f			velocity;
	bool			complete;
	
	Interpolation3() {
		speed		= 0.2;
		spring		= 0;
		value		= vec3f(0, 0, 0);
		target		= vec3f(1, 1, 1);
		velocity	= vec3f(0, 0, 0);
		complete	= false;
	}
	
	void update() {
		velocity = (( target - value ) * speed ) + ( velocity * spring );
		value += velocity;
		complete = MathUtil::distance3D(value, target) < 0.001;
		if( complete ) value = target;
	}
	
};
