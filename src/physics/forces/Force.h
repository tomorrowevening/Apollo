//
//  Force.h
//  Apollo
//
//  Created by Colin Duffy on 10/1/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#include "MathUtil.h"
#include "Particle.h"
#include "Vec.h"
#include <vector>

// Force-inherited classes
enum ForceType {
	FT_Gravity = 0,
	FT_Linear = 1,
	FT_Rotational = 2
};

class Force {
public:
	
	ForceType type;
	float size;
	vec3f pos, strength;
	
	Force() {
		pos = vec3f::zero();
		size = 100.0f;
		strength = vec3f(0.1, 0.1, 0.1);
		type = FT_Gravity;
	}
	
	virtual void applyForce(Particle* p, vec3f distance, float length, vec3f effect) {
		distance /= length;
		p->acc += distance * effect;
	}
	
	virtual void update(std::vector<Particle> *nodes) {
		int total = nodes->size();
		if(total > 0) {
			vec3f distance, effect;
			float length;
			Particle* p;
			for(int i = 0; i < total; ++i) {
				p = &nodes->at(i);
				distance = MathUtil::difference(pos, p->pos);
				length = distance.length();
				if(length > 0 && length < size) {
					length = sqrtf(length);
					applyForce(p, distance, length, (1.0f - (length / size)) * strength);
				}
			}
		}
	}
	
};
