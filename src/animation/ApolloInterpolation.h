//
//  ApolloInterpolation.h
//
//  Created by Colin Duffy on 9/8/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloMath.h"

namespace Apollo {
	
	using namespace Apollo;
	
	class Interpolation {
	public:
		
		float value, target, speed, spring, velocity;
		
		Interpolation(float value = 0, float target = 0, float speed = 0.1f, float spring = 0) {
			this->value  = value;
			this->target = target;
			this->speed  = speed;
			this->spring = spring;
			this->velocity = 0;
		}
		
		void update() {
			velocity = (( target - value ) * speed ) + ( velocity * spring );
			value = roundTo(value + velocity, 1000);
		}
		
		const bool complete() { return value == target; }
		
	};
	
}
