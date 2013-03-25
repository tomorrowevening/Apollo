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
	ease = Ease::Linear;
	value = 0;
	running = false;
	complete = false;
}

void BasicTweener::start() {
	stopWatch.start();
	checkComplete();
	running = true;
}

void BasicTweener::start(float startValue, float endValue, float duration) {
	this->startValue = startValue;
	this->endValue = endValue;
	this->value = startValue;
	this->duration = duration * 1000.0f;
	start();
}

void BasicTweener::stop() {
	running = false;
}

void BasicTweener::bezierEase(vec2f c0, vec2f c1, vec2f c2, vec2f c3) {
	customEase.setControl(0, c0.x, c0.y);
	customEase.setControl(1, c1.x, c1.y);
	customEase.setControl(2, c2.x, c2.y);
	customEase.setControl(3, c3.x, c3.y);
	custom = true;
}

void BasicTweener::update() {
	if( !running || complete ) return;
	if(custom) {
		value = customEase.getValue(stopWatch.read() / duration) * (endValue - startValue) + startValue;
	} else {
		value = abs( ease(stopWatch.read(), startValue, endValue - startValue, duration) * 1000.0f ) * 0.001f;
		if( value >= endValue ) value = endValue;
	}
	checkComplete();
}

float BasicTweener::time() {
	return stopWatch.read();
}

void BasicTweener::checkComplete() {
	complete = stopWatch.read() / duration >= 1.0f;
	if( complete ) destroyHandler();
}

void BasicTweener::destroyHandler() {
	value = endValue;
	complete = true;
	stop();
}
