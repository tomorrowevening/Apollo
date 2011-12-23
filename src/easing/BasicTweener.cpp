//
//  BasicTweener.cpp
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#include "BasicTweener.h"
#include "Ease.h"
#include "ofMain.h"

BasicTweener::BasicTweener() {
	ease = Linear::easeNone;
	value = 0;
	running = false;
	complete = false;
}

void BasicTweener::start() {
	shouldBuildUp = startValue < endValue;
	stopWatch.start();
	checkComplete();
	running = true;
}

void BasicTweener::stop() {
	running = false;
}

void BasicTweener::update() {
	if( !running || complete ) return;
	shouldBuildUp ? buildUp() : buildDown();
}

float BasicTweener::time() {
	return stopWatch.read();
}

void BasicTweener::checkComplete() {
	complete = value == endValue;
	if( complete ) destroyHandler();
}

void BasicTweener::buildUp() {
	value = ease( stopWatch.read(), startValue, endValue, duration );
	value = ceil( value * 100 ) * 0.01;
	if( value >= endValue ) value = endValue;
	checkComplete();
}

void BasicTweener::buildDown() {
	value = startValue - ease( stopWatch.read(), endValue, startValue, duration );
	value = floorf( value * 100 ) * 0.01;
	if( value <= endValue ) value = endValue;
	checkComplete();
}

void BasicTweener::destroyHandler() {
	complete = true;
	value = endValue;
	stop();
}
