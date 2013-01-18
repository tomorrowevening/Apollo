//
//  SpriteSheet.h
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#include "ofMain.h"

/**
 It's recommended to use the texture to render for smaller images.
 */
using namespace std;
class SpriteSheet {
public:
	
	bool loop, useTexture;
	float x, y, width, height, speed;
	int columns, totalFrames;
	
	SpriteSheet();
	int currentFrame();
	int update();
	void dispose();
	void load(string src, int frames, int columns = 1);
	void render(float offsetX = 0, float offsetY = 0);
	
private:
	
	float current;
	ofImage ref;
	vector<ofFbo*> fbos;
	void allocateFrame(int wid, int hei);
	void loadFrame(string src, int frameNum);
	
};
