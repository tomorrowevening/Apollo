//
//  Interpolation.cpp
//
//  Created by Colin Duffy on 12/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#include "Interpolation.h"

Interpolation::Interpolation() {
	speed		= 0.2;
	spring		= 0;
	value		= 0;
	target		= 1.;
	velocity	= 0;
	complete	= false;
}

/** Updates the interpolation values. */
void Interpolation::update() {
	velocity = (( target - value ) * speed ) + ( velocity * spring );
	value += velocity;
	complete = distance(value, target) < 0.001;
	if( complete ) value = target;
}
