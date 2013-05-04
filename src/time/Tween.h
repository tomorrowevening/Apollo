//
//  Tween.h
//  Created by Colin Duffy on 5/3/13.
//

#pragma once

#define BEZIER_SEGMENTS		10

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

typedef enum {
	Linear = 0,
	Stepped = -1,
	Custom = 1
} EaseTypes;

struct Vec2f {
	float x, y;
	void set(float nx, float ny) {
		x = nx; y = ny;
	}
};

class Tween {
protected:
	Vec2f c0, c1;
	float curves[6];
	void setCurve(float x0, float y0, float x1, float y1);
	float getCurvePercent(float percent);
public:
	
	float from, to;
	float duration, delay;
	float* var;
	
	void setLinear();
	void setPenner(PennerEases ease);
	void setStepped();
	
};

