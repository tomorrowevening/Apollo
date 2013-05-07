//
//  Tween.h
//  Created by Colin Duffy on 5/3/13.
//

#pragma once
#include "Vec.h"
#include <Poco/Timestamp.h>

typedef enum {
	EaseLinear = 0,
	
	EaseCircIn,
	EaseCircInOut,
	EaseCircOut,
	
	EaseCubicIn,
	EaseCubicInOut,
	EaseCubicOut,
	
	EaseExpoIn,
	EaseExpoInOut,
	EaseExpoOut,
	
	EaseQuadIn,
	EaseQuadInOut,
	EaseQuadOut,
	
	EaseQuartIn,
	EaseQuartInOut,
	EaseQuartOut,
	
	EaseQuintIn,
	EaseQuintInOut,
	EaseQuintOut,
	
	EaseSineIn,
	EaseSineInOut,
	EaseSineOut
	
} PennerEases;

struct CustomEase {
	vec2f c0, c1;
	void set(float x0, float y0, float x1, float y1) {
		c0.set(x0, y0); c1.set(x1, y1);
	}
};

class Tween {
protected:
	
	static const int BEZIER_SEGMENTS = 10;
	
	CustomEase points;
	float curves[6];
	
	void setCurve(float x0, float y0, float x1, float y1);
	float getCurvePercent(float percent);
	
public:
	
	float* var;
	float from, to, duration;
	Poco::Timestamp timestamp;
	
	// Generic
	void update(float percent);
	
	// Getters
	static CustomEase getEase(PennerEases ease);
	
	// Setters
	void setLinear();
	void setEase(float x0, float y0, float x1, float y1);
	void setEase(vec2f c0, vec2f c1);
	void setStepped();
	
	void setPenner(PennerEases ease);
	
	// Getters
	float range();
	
};

