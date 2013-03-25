//
//  SpriteSheet.h
//  SpriteSheets
//
//  Created by Colin Duffy on 8/5/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once
#include <vector>
#include "ofMain.h"
#include "StringUtil.h"

using namespace std;

class SpriteSheet {
public:
	
	bool loop, useTexture;
	float x, y, width, height, speed;
	int totalFrames;
	ofImage* img;
	
	SpriteSheet() {
		x = y = 0;
		_currentFrame = 0;
		totalFrames = 0;
		speed = 1.0f;
		loop = true;
		useTexture = true;
	}
	
	void setImage(ofImage* img) {
		if(useTexture) {
			this->img = img;
			setSize();
		} else {
			float xPos, yPos;
			ofFbo* fbo;
			for(int i = 0; i < totalFrames; ++i) {
				xPos = width  * (i % columns);
				yPos = height * floor((float)i / (float)columns);
				
				fbo = new ofFbo();
				fbo->allocate(width, height);
				
				// draw to fbo once
				fbo->begin();
//				img->drawSubsection(0, 0, width, height, xPos, yPos);
				fbo->end();
				
				fbos.push_back(fbo);
			}
		}
	}
	
	void setSize(float wid = 0, float hei = 0) {
		if(useTexture) {
			if(totalFrames < columns) {
				this->width  = img->getWidth()  / (float)totalFrames;
			} else {
				this->width  = img->getWidth()  / (float)columns;
			}
			this->height = img->getHeight() / ceil((float)totalFrames / (float)columns);
		} else {
			this->width  = wid;
			this->height = hei;
		}
	}
	
	void loadImage(string imagePath, int totalFrames, int columns) {
		this->totalFrames = totalFrames;
		this->columns = columns;
		
		if(useTexture) {
			img = new ofImage();
			img->loadImage(imagePath);
			setImage(img);
		} else {
			ofFbo* fbo;
			int i;
			int total = totalFrames;
			
			for(i = 0; i < total; ++i) {
				fbo = new ofFbo();
				fbo->allocate(width, height);
				fbos.push_back(fbo);
				fbo = NULL;
			}
			
			for(i = 0; i < total; ++i) {
				fbo = fbos[i];
				ofImage img; // ".png"
				img.loadImage( StringUtil::formatDigits(i, 5, imagePath, ".png") );

				width  = img.getWidth();
				height = img.getHeight();
				
				fbo->begin();
				img.draw(0, 0);
				fbo->end();
				
				fbo = NULL;
				img.clear();
			}
			
		}
	}
	
	int currentFrame() {
		return (int)floor(_currentFrame);
	}
	
	bool lastFrame() {
		return currentFrame() == totalFrames-1;
	}
	
	void goTo(float frame) {
		if(loop) {
			_currentFrame = fmod(frame, totalFrames);
		} else {
			_currentFrame = frame < totalFrames ? frame : totalFrames;
		}
		
	}
	
	void next() {
		goTo(_currentFrame + speed);
	}
	
	void dispose() {
		delete img;
		int total = fbos.size();
		for(int i = total; i > -1; --i) delete fbos[i];
		fbos.clear();
	}
	
	void render() {
		if(totalFrames == 0) return;
		if(useTexture) {
			float xPos = width  * (currentFrame() % columns);
			float yPos = height * floor(_currentFrame / (float)columns);
			if(width == 0) setSize();
//			img->drawSubsection(round(x), round(y), width, height, xPos, yPos);
		} else {
			fbos[currentFrame()]->draw(round(x), round(y));
		}
	}
	
private:
	
	float _currentFrame;
	int columns;
	vector<ofFbo*> fbos;
	
};
