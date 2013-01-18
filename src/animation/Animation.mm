//
//  Animation.mm
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#include "Animation.h"

Animation::Animation() {
	
}

void Animation::add(string frameName, string imagePath, int totalFrames, int columns) {
	frameLabels.push_back(frameName);
	SpriteSheet ani;
	ani.speed = speed;
	ani.loadImage(imagePath, totalFrames, columns);
	animations.push_back(ani);
}

void Animation::dispose() {
	int total = animations.size();
	for(int i = 0; i < total; ++i) {
		animations[i].dispose();
	}
	animations.clear();
}

void Animation::gotoAndPlay(string frame) {
	int total = animations.size();
	for(int i = 0; i < total; ++i) {
		if(frameLabels[i] == frame) {
			currentAnimation = &animations[i];
			break;
		}
	}
}

void Animation::render() {
	if(currentAnimation != NULL) {
		currentAnimation->x = x;
		currentAnimation->y = y;
		currentAnimation->render();
	}
}

void Animation::setSpeed(float value) {
	speed = value;
	int total = animations.size();
	for(int i = 0; i < total; ++i) animations[i].speed = value;
}
