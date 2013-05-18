//
//  AppSettings.h
//  CinderCocoaView
//
//  Created by colin.duffy on 5/17/13.
//
//

#pragma once

//#include "Apollo.h"
#include "Effectors.h"

using namespace std;
//using namespace Apollo;

struct AppSettings {
	
	int countX, countY;
	
	int xEffector, yEffector;
	Effector* effectorX;
	Effector* effectorY;
	
	float dotAlpha;
	float spaceX, spaceY;
	float paddingX, paddingY;
	
	float multiplierX;
	float multiplierY;
	float multiplierRadius;
	
	bool effectX;
	bool effectY;
	bool reverseX;
	bool reverseY;
	
	std::vector<Effector*> effectors;
	
	AppSettings() {
		effectors.push_back(new Effector());
		effectors.push_back(new CosEffector());
		effectors.push_back(new SineEffector());
		reset();
	}
	
	void reset() {
		countX = 50;
		countY = 50;
		spaceX = 15;
		spaceY = 15;
		paddingX = 25;
		paddingY = 25;
		
		multiplierX = 1.f;
		multiplierY = 1.f;
		multiplierRadius = 1.f;
		
		dotAlpha = 1.f;
		effectX = true;
		effectY = true;
		reverseX = false;
		reverseY = false;
		
		xEffector = 0;
		yEffector = 0;
		
		effectorX = effectors[xEffector];
		effectorY = effectors[yEffector];
	}
	
	void update() {
		effectorX = effectors[xEffector];
		effectorY = effectors[yEffector];
	}
	
	float getRadius(float px, float py) {
		float rad = 0;
		if(effectX) {
			if(reverseX) {
				rad += (1.f - effectorX->getSize(px)) * multiplierX;
			} else {
				rad += effectorX->getSize(px) * multiplierX;
			}
		}
		
		if(effectY) {
			if(reverseY) {
				rad += (1.f - effectorY->getSize(py)) * multiplierY;
			} else {
				rad += effectorY->getSize(py) * multiplierY;
			}
		}
		
		if(effectX && effectY) rad *= 0.5f;
		return rad * multiplierRadius;
	}
	
	vector<string> effectorNames() {
		vector<string> names;
		for(int i = 0; i < effectors.size(); ++i) names.push_back(effectors[i]->name);
		return names;
	}
	
	int totalEffectors() { return (int)effectors.size(); }
};
