//
//  StopWatch.cpp
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#include "StopWatch.h"
#include "ofMain.h"

StopWatch::StopWatch() {
	initTime = endTime = lastLap = ms = 0;
}

float StopWatch::lap() {
	ms = now() - lastLap;
	lastLap = now();
	return ms;
}

float StopWatch::read() {
	return now() - initTime;
}

float StopWatch::start() {
	initTime = now();
	lastLap = initTime;
	return read();
}

float StopWatch::stop() {
	endTime = now();
	ms = endTime - initTime;
	return ms;
}

int StopWatch::now() {
	return ofGetElapsedTimeMillis();
}
