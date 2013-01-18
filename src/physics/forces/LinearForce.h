//
//  LinearForce.h
//  Apollo
//
//  Created by Colin Duffy on 10/1/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#include "MathUtil.h"
#include "Vec.h"
#include "Force.h"

class LinearForce : public Force {
public:
	
	float directionStrength;
	float direction;
	
	LinearForce() {
		Force::Force();
		type = FT_Linear;
		direction = 0.0f;
		directionStrength = 1.0f;
	}
	
	void applyForce(Particle* p, vec3f distance, float length, vec3f effect) {
		float phi = MathUtil::toRadians(direction);
		p->vel.x += cos(phi) * effect.x;
		p->vel.y += sin(phi) * effect.y;
	}
	
};
