//
//  ApolloMath.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#include "ApolloMath.h"

namespace Apollo {
	
	float clamp(float value, float minV, float maxV) {
		return std::max(minV, std::min(value, maxV));
	}
	
	float lerp(float per, float min, float max) {
		return (max - min) * per + min;
	}
	
	float getRange(float value, float min, float max) {
		return (value - min) / (max - min);
	}
	
	float cosRange(float degrees, float range, float min) {
		return (((1 + cos(degrees * RADIANS)) * 0.5) * range) + min;
	}
	
	// Bools
	
	bool inRange(float value, float min, float max) {
		return value >= min && value <= max;
	}
	
	// Random
	
	float random(float max) {
		return ((float)rand()/(float)RAND_MAX) * max;
	}
	
	float randomRange(float min, float max) {
		return random(max-min) + min;
	}
	
	// Trig
	
	float toDeg(float radians) {
		return radians * DEGREES;
	}
	
	float toRad(float degrees) {
		return degrees * RADIANS;
	}
	
	float getAngleRad(float x1, float y1, float x2, float y2) {
		return atan2( y2-y1, x2-x1 );
	}
	
	float getAngleDeg(float x1, float y1, float x2, float y2) {
		return toDeg(getAngleRad(x1, y1, x2, y2));
	}
	
	// Distance
	
	float distance(float a, float b) {
		return sqrtf((a-b) * (a-b));
	}
	
	float distance(float x1, float y1, float x2, float y2) {
		return distance(x1, x2) + distance(y1, y2);
	}
	
	float distance(float x1, float y1, float z1, float x2, float y2, float z2) {
		return distance(x1, x2, y1, y2) + distance(z1, z2);
	}
	
	
}
