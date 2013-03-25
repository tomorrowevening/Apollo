//
//  Animation.h
//  SpriteSheets
//
//  Created by Colin Duffy on 8/16/12.
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
	void gotoAndPlay(string frame);
	void setSpeed(float value);
	
	virtual void dispose();
	virtual void render();
	
private:
	SpriteSheet* currentAnimation;
	vector<SpriteSheet> animations;
	vector<string> frameLabels;
};
