//
//  SSMovieClip.h
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

enum SpriteAlignment {
	SpriteAlign_TL = 0,
	SpriteAlign_TC = 1,
	SpriteAlign_TR = 2,
	
	SpriteAlign_CL = 3,
	SpriteAlign_CC = 4,
	SpriteAlign_CR = 5,
	
	SpriteAlign_BL = 6,
	SpriteAlign_BC = 7,
	SpriteAlign_BR = 8
};

class SSMovieClip {
public:
	
	SpriteAlignment align;
	int animationIndex;
	float x, y, z, speed, width, height;
	
	SSMovieClip();
	
	void add(string frameName, SpriteSheet* ani);
	void add(string frameName, string imagePath, int totalFrames, int columns);
	void dispose();
	void goTo(int frame);
	void gotoAndPlay(string frame);
	void stop();
	void play();
	void render();
	void setLoop(bool value, bool currentLoop = true);
	
	float getWidth();
	float getHeight();
	string currentFrameLabel();
	
	float left();
	float top();
	float centerX();
	float centerY();
	float right();
	float bottom();
	
	void center(float cx, float cy);
	int getFrame();
	
	SpriteSheet* getAnimation(string aniName);
	void copy(SSMovieClip* copyTo);
	
private:
	
	float currentFrame;
	vector<SpriteSheet*> animations;
	vector<string> frameLabels;
	
};
