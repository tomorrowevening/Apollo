//
//  ShakeDetection.mm
//
//  Created by Colin Duffy on 4/16/13.
//
//

#include "ShakeDetection.h"
#ifdef TARGET_OPENGLES
#include "ofxAccelerometer.h"
#endif

ShakeDetection Shaker;

ShakeDetection::ShakeDetection() {
	maxShakes = 1;
	shake = 0;
	start = 0;
	trigger = 0;
	threshold = 1.3f;
	timeThreshold = 500; // in ms
}

ShakeDetection::~ShakeDetection() {
	dispose();
}

void ShakeDetection::update(ofEventArgs &data) {
	float time = ofGetElapsedTimeMillis();
	ofVec2f acc;
	
#ifdef TARGET_OPENGLES
	acc = ofxAccelerometer.getForce();
#endif
	
	if(acc.x < -threshold && trigger == 0) {
		trigger = 1;
		start = time;
	}
	
	if(acc.x >  threshold && trigger == 1) trigger = 2;
	if(acc.x < -threshold && trigger == 2) trigger = 3;
	if(acc.x >  threshold && trigger == 3) trigger = 4;
	
	if(trigger == 4) {
		++shake;
		trigger = 0;
	}
	
	if(time - start > timeThreshold) trigger = 0; // reset if shake is too long
	if(shake >= maxShakes) {
		ofNotifyEvent(ON_SHAKE, shake, this);
		shake = 0;
	}
}

void ShakeDetection::init() {
	ofAddListener(ofEvents().update, this, &ShakeDetection::update);
}

void ShakeDetection::dispose() {
	ofRemoveListener(ofEvents().update, this, &ShakeDetection::update);
}
