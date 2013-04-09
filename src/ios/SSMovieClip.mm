//
//  SSMovieClip.mm
//  SpriteSheets
//
//  Created by Colin Duffy on 8/16/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#include "SSMovieClip.h"

SSMovieClip::SSMovieClip() {
	animationIndex = 0;
	currentFrame = 0.0f;
	x = y = 0;
	speed = 0.5f;
	width = height = 0;
	align = SpriteAlign_TL;
}

void SSMovieClip::add(string frameName, SpriteSheet* ani) {
	frameLabels.push_back(frameName);
	animations.push_back(ani);
}

void SSMovieClip::add(string frameName, string imagePath, int totalFrames, int columns) {
	SpriteSheet* ani = new SpriteSheet();
	ani->speed = speed;
	ani->loadImage(imagePath, totalFrames, columns);
	add(frameName, ani);
}

void SSMovieClip::dispose() {
	int total = animations.size();
	for(int i = 0; i < total; ++i) {
		delete animations[i];
	}
	animations.clear();
	animationIndex = -1;
}

void SSMovieClip::goTo(int frame) {
	currentFrame = frame;
	animations[animationIndex]->goTo(frame);
}

void SSMovieClip::stop() {
	speed = 0;
}

void SSMovieClip::play() {
	speed = 0.5f;
}

void SSMovieClip::gotoAndPlay(string frame) {
	int total = animations.size();
	for(int i = 0; i < total; ++i) {
		if(frameLabels[i] == frame) {
			animationIndex = i;
			goTo(0);
			break;
		}
	}
}

string SSMovieClip::currentFrameLabel() {
	return frameLabels[animationIndex];
}

void SSMovieClip::setLoop(bool value, bool currentLoop) {
	if(currentLoop) {
		animations[animationIndex]->loop = value;
	} else {
		int total = animations.size();
		for(int i = 0; i < total; ++i) {
			animations[i]->loop = value;
		}
	}
}

float SSMovieClip::getWidth() {
	if(animationIndex > -1) return animations[animationIndex]->width;
	return 0;
}

float SSMovieClip::getHeight() {
	if(animationIndex > -1) return animations[animationIndex]->height;
	return 0;
}

float SSMovieClip::left() {
	return x;
}

float SSMovieClip::top() {
	return y;
}

float SSMovieClip::centerX() {
	return getWidth() * 0.5 + x;
}

float SSMovieClip::centerY() {
	return getHeight() * 0.5 + y;
}

float SSMovieClip::right() {
	return x + getWidth();
}

float SSMovieClip::bottom() {
	return y + getHeight();
}

void SSMovieClip::center(float cx, float cy) {
	ofVec2f s = ofVec2f(getWidth(), getHeight()) * 0.5f;
	x = cx - s.x;
	y = cy - s.y;
}

int SSMovieClip::getFrame() {
	if(animationIndex > -1) return animations[animationIndex]->currentFrame();
	return 0;
}

SpriteSheet* SSMovieClip::getAnimation(string aniName) {
	int total = animations.size();
	for(int i = 0; i < total; ++i) {
		if(frameLabels[i] == aniName) return animations[i];
	}
	return NULL;
}

void SSMovieClip::copy(SSMovieClip* copyFrom) {
	width  = copyFrom->width;
	height = copyFrom->height;
	align  = copyFrom->align;
	
	int total = copyFrom->animations.size();
	for(int i = 0; i < total; ++i) {
		add(copyFrom->frameLabels[i], copyFrom->animations[i]);
	}
}

void SSMovieClip::render() {
	if(animationIndex > -1) {
		animations[animationIndex]->goTo(floor(currentFrame));
		
		float offX = 0;
		float offY = 0;
		
		if(align == SpriteAlign_TL || align == SpriteAlign_CL || align == SpriteAlign_BL) {
			offX = 0;
		} else if(align == SpriteAlign_TC || align == SpriteAlign_CC || align == SpriteAlign_BC) {
			offX = (animations[animationIndex]->width - width) * 0.5;
		} else { // align == SpriteAlign_TR || align == SpriteAlign_CR || align == SpriteAlign_BR
			offX = animations[animationIndex]->width - width;
		}
		
		if(align == SpriteAlign_TL || align == SpriteAlign_TC || align == SpriteAlign_TR) {
			offY = 0;
		} else if(align == SpriteAlign_CL || align == SpriteAlign_CC || align == SpriteAlign_CR) {
			offY = (animations[animationIndex]->height - height) * 0.5;
		} else { // align == SpriteAlign_TR || align == SpriteAlign_CR || align == SpriteAlign_BR
			offY = animations[animationIndex]->height - height;
		}
		
		animations[animationIndex]->render(x - offX, y - offY);
		currentFrame = fmod(currentFrame + speed, animations[animationIndex]->totalFrames);
	}
}
