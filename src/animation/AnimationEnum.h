//
//  AnimationEnum.h
//  Apollo
//  Created by Colin Duffy on 5/7/13.
//
//

#pragma once

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

struct CubicEase {
	vec2f c0, c1;
	
	CubicEase(float x0 = 0.333f, float y0 = 0.333f, float x1 = 0.667f, float y1 = 0.667f) {
		set(x0, y0, x1, y1);
	}
	
	void set(float x0, float y0, float x1, float y1) {
		c0.set(x0, y0); c1.set(x1, y1);
	}
};
