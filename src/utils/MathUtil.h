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

#ifndef RADIANS
#define RADIANS									0.017453292519943295f
#endif

#ifndef DEGREES
#define DEGREES									57.29577951308232f
#endif

#ifndef PI
#define PI										3.14159265359f
#endif

#ifndef TWO_PI
#define TWO_PI									PI * 2.f
#endif

#ifndef HALF_PI
#define HALF_PI									( PI * (float)0.5 )
#endif

#ifndef toRad
#define toRad(ang)								( RADIANS * ang )
#endif

#ifndef toDeg
#define toDeg(ang)								( DEGREES * ang )
#endif

#ifndef FLT_EPSILON
#define FLT_EPSILON								1.19209290E-07F
#endif

#define GET_ANGLE_RAD(x1,y1,x2,y2)				( atan2( y2-y1, x2-x1 ) )
#define GET_ANGLE_DEG(x1,y1,x2,y2)				( TO_DEGREES( GET_ANGLE_RAD(x1,y1,x2,y2) ) )
#define RANGE(min,max,per)						( (float)( min + ((max - min) * per) ) )

#define ROUND(value, ordinal)					( roundf( value * (float)ordinal ) * ( 1. / (float)ordinal ) )

#define COS_RANGE(degrees, range, min)			( (((1 + cos(degrees * RADIANS)) * 0.5) * range) + min )

#ifndef CLAMP
#define CLAMP(value, minV, maxV)					( MAX(minV, MIN(value, maxV)) )
#endif

using namespace Apollo;

enum MatrixAlign {
	ALIGN_TOP_LEFT = 0,
	ALIGN_TOP_CENTER = 1,
	ALIGN_TOP_RIGHT = 2,
	
	ALIGN_MID_LEFT = 3,
	ALIGN_MID_CENTER = 4,
	ALIGN_MID_RIGHT = 5,
	
	ALIGN_BOT_LEFT = 6,
	ALIGN_BOT_CENTER = 7,
	ALIGN_BOT_RIGHT = 8
};

class MathUtil {
public:
	
	static float align(MatrixAlign alignment, float min, float max) {
		if(alignment == ALIGN_TOP_LEFT ||
		   alignment == ALIGN_MID_LEFT ||
		   alignment == ALIGN_BOT_LEFT)		return min;
		
		if(alignment == ALIGN_TOP_CENTER ||
		   alignment == ALIGN_MID_CENTER ||
		   alignment == ALIGN_BOT_CENTER)	return RANGE(min, max, 0.5f);
		
		return max;
	}
	
	static vec2f align(MatrixAlign alignment, vec2f pos, vec2f size) {
		vec2f adjusted = pos;
		switch(alignment) {
			// Left
			case ALIGN_TOP_LEFT:
			default:
				break;
			case ALIGN_TOP_CENTER:
				adjusted.x -= size.x * 0.5f;
				break;
				
			case ALIGN_TOP_RIGHT:
				adjusted.x -= size.x;
				break;
				
			// Mid
			case ALIGN_MID_LEFT:
				adjusted.y -= size.y * 0.5f;
				break;
			case ALIGN_MID_CENTER:
				adjusted.x -= size.x * 0.5f;
				adjusted.y -= size.y * 0.5f;
				break;
			case ALIGN_MID_RIGHT:
				adjusted.x -= size.x;
				adjusted.y -= size.y * 0.5f;
				break;
				
			// Bottom
			case ALIGN_BOT_LEFT:
				adjusted.y -= size.y;
				break;
			case ALIGN_BOT_CENTER:
				adjusted.x -= size.x * 0.5f;
				adjusted.y -= size.y;
				break;
			case ALIGN_BOT_RIGHT:
				adjusted.x -= size.x;
				adjusted.y -= size.y;
				break;
		}
		
		return adjusted;
	}
	
	static float map(float value, float inputMin, float inputMax, float outputMin, float outputMax, bool clamp = false) {
		if (fabs(inputMin - inputMax) < FLT_EPSILON){
			return outputMin;
		} else {
			float outVal = ((value - inputMin) / (inputMax - inputMin) * (outputMax - outputMin) + outputMin);
			if( clamp ){
				if(outputMax < outputMin){
					if( outVal < outputMax )outVal = outputMax;
					else if( outVal > outputMin )outVal = outputMin;
				}else{
					if( outVal > outputMax )outVal = outputMax;
					else if( outVal < outputMin )outVal = outputMin;
				}
			}
			return outVal;
		}
	}
	
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
	
	static bool inRange(float value, float min, float max) {
		return value >= min && value <= max;
	}
	
	static bool overlapping(float x, float y, float width, float height, float boundsX, float boundsY, float boundsWidth, float boundsHeight) {
		return inRange(x, boundsX, boundsX+boundsWidth) || inRange(y, boundsY, boundsY+boundsHeight);
	}
	
	static float getRange(float value, float min, float max) {
		return (value - min) / (max - min);
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
	
	static vec2f difference(vec2f p1, vec2f p2) {
		return vec2f(p1.x - p2.x, p1.y - p2.y);
	}
	
	static float difference(float p1, float p2) {
		return p1 - p2;
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
