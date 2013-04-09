//
//  Timer.h
//
//  Created by Colin Duffy on 3/28/13.
//
//

#pragma once
#include "ofMain.h"

class Timer {
public:
	
	int totalMS;
	ofEvent<float> COMPLETE;
	
	Timer();
	void start(float totalSeconds = 1.0);
	void start(int totalMS = 1000);
	void stop();
	
	float timeRemaining();
	bool running() { return _running; }
	
private:
	
	bool _running;
	float startTime, endTime;
	void updateHandler(ofEventArgs &data);
	
};
