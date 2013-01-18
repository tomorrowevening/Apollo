//
//  MathUtil.h
//  Apollo
//
//  Created by Colin Duffy on 10/1/12.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Vec.h"

#ifndef PI
#define RADIANS									0.017453292519943295
#endif

#ifndef PI
#define DEGREES									57.29577951308232
#endif

#ifndef PI
#define PI										3.14159265359
#endif

#ifndef HALF_PI
#define HALF_PI									( PI * (float)0.5 )
#endif

#define GET_ANGLE_RAD(x1,y1,x2,y2)				( atan2( y2-y1, x2-x1 ) )
#define GET_ANGLE_DEG(x1,y1,x2,y2)				( TO_DEGREES( GET_ANGLE_RAD(x1,y1,x2,y2) ) )
#define RANGE(min,max,per)						( (float)( min + ((max - min) * per) ) )

#define ROUND(value, ordinal)					( roundf( value * (float)ordinal ) * ( 1. / (float)ordinal ) )

#define COS_RANGE(degrees, range, min)			( (((1 + cos(TO_RADIANS(degrees))) * 0.5) * range) + min )

class MathUtil {
public:
	
	static float resolveAngle(float degrees) {
		return fmodf(degrees, 360.0f);
	}
	
	static float toDegrees(float radians) {
		return resolveAngle(radians * DEGREES);
	}
	
	static vec3f toDegrees(vec3f radians) {
		return vec3f(resolveAngle(radians.x * DEGREES), resolveAngle(radians.y * DEGREES), resolveAngle(radians.z * DEGREES));
	}
	
	static float toRadians(float degrees) {
		return resolveAngle(degrees) * RADIANS;
	}
	
	static vec3f toRadians(vec3f degrees) {
		return vec3f(resolveAngle(degrees.x) * RADIANS, resolveAngle(degrees.y) * RADIANS, resolveAngle(degrees.z) * RADIANS);
	}
	
	static float random() {
		return (float)rand()/(float)RAND_MAX;
	}
	
	static float randomRange(float min, float max) {
		return RANGE(min, max, random());
	}
	
	static vec3f randomRange(vec3f min, vec3f max) {
		return vec3f(randomRange(min.x, max.x), randomRange(min.y, max.y), randomRange(min.z, max.z));
	}

	static float distance(float a, float b) {
		return sqrtf((a-b) * (a-b));
	}
	
	static float distance2D(float x1, float y1, float x2, float y2) {
		return distance(x1, x2) + distance(y1, y2);
	}
	
	static float distance2D(vec2f p1, vec2f p2) {
		return distance2D(p1.x, p1.y, p2.x, p2.y);
	}
	
	static float distance3D(float x1, float y1, float z1, float x2, float y2, float z2) {
		return distance2D(x1, y1, x2, y2) + distance(z1, z2);
	}
	
	static float distance3D(vec3f p1, vec3f p2) {
		return distance3D(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
	}
	
	static vec3f difference(vec3f p1, vec3f p2) {
		return vec3f(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
	}
	
	static vec2f constrain(vec2f pos, vec2f bounds = vec2f::zero()) {
		vec3f newPos = constrain(vec3f(pos.x, pos.y, 0), vec3f(bounds.x, bounds.y, 0));
		
		if(newPos.x < 0) newPos.x = 0;
		if(newPos.x > bounds.x) newPos.x = bounds.x;
		
		if(newPos.y < 0) newPos.x = 0;
		if(newPos.y > bounds.y) newPos.y = bounds.y;
		
		return vec2f(newPos.x, newPos.y);
	}
	
	static vec3f constrain(vec3f pos, vec3f bounds = vec3f::zero()) {
		vec3f newPos = vec3f(pos.x, pos.y, pos.z);
		
		if(newPos.x < 0) newPos.x = 0;
		if(newPos.x > bounds.x) newPos.x = bounds.x;
		
		if(newPos.y < 0) newPos.x = 0;
		if(newPos.y > bounds.y) newPos.y = bounds.y;
		
		if(newPos.z < 0) newPos.z = 0;
		if(newPos.z > bounds.z) newPos.z = bounds.z;
		
		return newPos;
	}
	
	static vec2f wrap(vec2f pos, vec2f bounds) {
		vec3f wrapped = wrap(vec3f(pos.x, pos.y, 0), vec3f(bounds.x, bounds.y, 0));
		return vec2f(wrapped.x, wrapped.y);
	}
	
	static vec3f wrap(vec3f pos, vec3f bounds) {
		vec3f wrapped = vec3f(pos.x, pos.y, pos.z);
		
		if(wrapped.x < 0) wrapped.x += bounds.x;
		if(wrapped.x > bounds.x) wrapped.x -= bounds.x;
		
		if(wrapped.y < 0) wrapped.y += bounds.y;
		if(wrapped.y > bounds.y) wrapped.y -= bounds.y;
		
		if(wrapped.z < 0) wrapped.z += bounds.z;
		if(wrapped.z > bounds.z) wrapped.z -= bounds.z;
		
		return wrapped;
	}
	
};
