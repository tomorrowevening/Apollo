//
//  Animation.h
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "SpriteSheet.h"
#include "ofMain.h"
#include <vector>

using namespace std;

class Animation {
public:
	
	float x, y, speed;
	
	Animation();
	void add(string frameName, string imagePath, int totalFrames, int columns);
	void dispose();
	void gotoAndPlay(string frame);
	void render();
	void setSpeed(float value);
	
private:
	
	SpriteSheet* currentAnimation;
	vector<SpriteSheet> animations;
	vector<string> frameLabels;
};
