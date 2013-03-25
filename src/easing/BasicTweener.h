//
//  BasicTweener.h
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#ifndef TE_TIME_Basic_Tweener
#define TE_TIME_Basic_Tweener

#include <iostream.h>
#include "StopWatch.h"
#include "ofMain.h"
#include "Ease.h"
#include "Bezier.h"
#include "Vec.h"

class BasicTweener {
	
public:
	
	bool			complete;
	bool			running;
	bool			custom;
	float			duration;
	float			startValue;
	float			endValue;
	float			delay;
	float			(*ease)(float t, float b, float c, float d);
	
	BasicTweener();
	void			update();
	void			start();
	void			start(float startValue, float endValue, float duration);
	void			bezierEase(	vec2f c0 = vec2f(0.000f, 0.000f),
								vec2f c1 = vec2f(0.333f, 0.333f),
								vec2f c2 = vec2f(0.667f, 0.667f),
								vec2f c3 = vec2f(1.000f, 1.000f));
	void			stop();
	float			time();
	float			value;
	
private:
	StopWatch		stopWatch;
	void			destroyHandler();
	void			checkComplete();
	Bezier			customEase;
};

#endif
