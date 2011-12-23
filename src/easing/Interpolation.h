//
//  Interpolation.h
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#pragma once

#import "MathUtil.h"

class Interpolation {
public:
	
	float			speed;
	float			spring;
	float			target;
	float			value;
	float			velocity;
	bool			complete;
	
	Interpolation();
	void update();
	
};
