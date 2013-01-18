//
//  SpriteSheet.mm
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#include "SpriteSheet.h"
#include "StringUtil.h"

SpriteSheet::SpriteSheet() {
	x = y = width = height = 0;
	speed = 1.0f;
	current = totalFrames = 0;
	columns = 1;
	useTexture = true;
}

/** Clear all image data/frames. */
void SpriteSheet::dispose() {
	int total = fbos.size()-1;
	for(int i = total; i > -1; --i) delete fbos[i];
	fbos.clear();
	ref.clear();
}

/** Load the series of images / spritesheet image used for the animation. */
void SpriteSheet::load(string src, int frames, int columns) {
	this->totalFrames = frames;
	this->columns = columns;
	
	if(useTexture) {
		
		ref.loadImage(src);
		if(totalFrames < columns) {
			width  = (float)ref.getWidth()  / (float)totalFrames;
		} else {
			width  = (float)ref.getWidth()  / (float)columns;
		}
		height = ref.getHeight() / ceil((float)totalFrames / (float)columns);
		
	} else {
		
		ref.loadImage(StringUtil::formatDigits(0, 5, src, ".png"));
		width  = (int)ref.getWidth();
		height = (int)ref.getHeight();
		ref.clear(); // no longer used
		
		int i;
		// Allocate FBOs
		for(i = 0; i < frames; ++i) allocateFrame((int)width, (int)height);
		
		// Screenshot FBOs
		for(i = 0; i < frames; ++i) loadFrame(StringUtil::formatDigits(i, 5, src, ".png"), i);
	}
}

/** Allocates the frame's FBO and add it to the vector. */
void SpriteSheet::allocateFrame(int wid, int hei) {
	ofFbo* fbo = new ofFbo();
	fbo->allocate(wid, hei);
	fbos.push_back(fbo);
}

/** Load the image to be used for the frame. */
void SpriteSheet::loadFrame(string src, int frameNum) {
	ofImage img;
	img.loadImage(src);
	
	fbos[frameNum]->begin();
	img.draw(0, 0);
	fbos[frameNum]->end();
	img.clear(); // No longer used
}

/** Renders the image offset or current FBO. */
void SpriteSheet::render(float offsetX, float offsetY) {
	float xPos = x + offsetX;
	float yPos = y + offsetY;
	
	if(useTexture) {
		
		float xOffset = width  * (currentFrame() % columns);
		float yOffset = height * floor(current / (float)columns);
		ref.drawSubsection(xPos, yPos, width, height, xOffset, yOffset);
		
	} else {
		
		int cur = currentFrame();
		if(cur < fbos.size()) {
			if(fbos[cur]->isAllocated()) fbos[cur]->draw(xPos, yPos);
		}
		
	}
}

/** The current frame, out of the total frames. */
int SpriteSheet::currentFrame() {
	return floor(current);
}

/** Updates the current keyframe by the speed. */
int SpriteSheet::update() {
	current = fmod(speed+current, (float)totalFrames);
	return current;
}


