//
//  ShakeDetection.h
//  Referenced from http://forum.openframeworks.cc/index.php?topic=3929.0
//
//  Created by Colin Duffy on 4/16/13.
//
//

#pragma once

#include "ofMain.h"

class ShakeDetection {
private:
	
	float start;
	int shake, trigger;
	
	void update(ofEventArgs &data);
	
public:
	
	int timeThreshold, maxShakes;
	float threshold;
	
	ofEvent<int> ON_SHAKE;
	
	ShakeDetection();
	~ShakeDetection();
	
	void init();
	void dispose();
	
};

extern ShakeDetection Shaker; // identify through Shaker
