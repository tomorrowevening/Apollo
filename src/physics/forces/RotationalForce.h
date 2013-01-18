//
//  RotationalForce.h
//  Apollo
//
//  Created by Colin Duffy on 10/1/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#include "MathUtil.h"
#include "Vec.h"
#include "Force.h"

class RotationalForce : public Force {
public:
	
	float rotationStrength;
	
	RotationalForce() {
		Force::Force();
		type = FT_Rotational;
		
		// Associate with degrees
		rotationStrength = MathUtil::toRadians(150.0f);
		
		float strengthAmt = 0.1;
		strength = vec3f(strengthAmt, strengthAmt, strengthAmt);
	}
	
	void applyForce(Particle* p, vec3f distance, float length, vec3f effect) {
		float phi = GET_ANGLE_RAD(distance.x, distance.y, 0, 0) + rotationStrength;
		p->vel.x += cos(phi) * effect.x;
		p->vel.y += sin(phi) * effect.y;
	}
	
};
