//
//  Timer.cpp
//
//  Created by Colin Duffy on 3/28/13.
//
//

#include "Timer.h"

Timer::Timer() {
	_running = false;
}

void Timer::start(int totalMS) {
	start((float)totalMS / 1000.0f);
}

void Timer::start(float totalSeconds) {
	startTime = ofGetElapsedTimef();
	endTime = startTime + totalSeconds;
	if(!_running) ofAddListener(ofEvents().update, this, &Timer::updateHandler);
	_running = true;
}

void Timer::stop() {
	_running = false;
	ofRemoveListener(ofEvents().update, this, &Timer::updateHandler);
}

void Timer::updateHandler(ofEventArgs &data) {
	if(!_running) false;
	if(ofGetElapsedTimef() >= endTime) {
		stop();
		ofNotifyEvent(COMPLETE, endTime, this);
	}
}

float Timer::timeRemaining() {
	return endTime - ofGetElapsedTimef();
}
