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

class BasicTweener {
	
private:
	StopWatch		stopWatch;
	void			buildUp();
	void			buildDown();
	void			destroyHandler();
	void			checkComplete();
	bool			shouldBuildUp;
	
public:
	bool			complete;
	bool			running;
	float			duration;
	float			startValue;
	float			endValue;
	float			(*ease)(float t, float b, float c, float d);
	
	BasicTweener();
	void			update();
	void			start();
	void			stop();
	float			time();
	float			value;
};

#endif
