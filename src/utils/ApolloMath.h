//
//  ApolloMath.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include <math.h>
#include <iostream>
#include <algorithm>

#ifndef RADIANS
#define RADIANS									0.017453292519943295f
#endif

#ifndef DEGREES
#define DEGREES									57.29577951308232f
#endif

#ifndef PI
#define PI										3.14159265359f
#endif

#ifndef PI_2
#define PI_2									PI * 2.f
#endif

#ifndef PI_HALF
#define PI_HALF									( PI * (float)0.5 )
#endif

namespace Apollo {
	
	enum MatrixAlign {
		ALIGN_TOP_LEFT = 0,
		ALIGN_TOP_CENTER,
		ALIGN_TOP_RIGHT,
		
		ALIGN_MID_LEFT,
		ALIGN_MID_CENTER,
		ALIGN_MID_RIGHT,
		
		ALIGN_BOT_LEFT,
		ALIGN_BOT_CENTER,
		ALIGN_BOT_RIGHT
	};
	
	float clamp(float value, float minV, float maxV);
	float lerp(float per, float min, float max);
	float getRange(float value, float min, float max);
	
	// Bools
	
	bool inRange(float value, float min, float max);
	
	// Random
	
	float random(float max);
	float randomRange(float min, float max);
	
	// Trig
	
	float toDeg(float radians);
	float toRad(float degrees);
	float getAngleRad(float x1, float y1, float x2, float y2);
	float getAngleDeg(float x1, float y1, float x2, float y2);
	
	// Distance
	
	float distance(float a, float b);
	float distance(float x1, float y1, float x2, float y2);
	float distance(float x1, float y1, float z1, float x2, float y2, float z2);
}
