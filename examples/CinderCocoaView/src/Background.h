//
//  Background.h
//  CinderCocoaView
//
//  Created by colin.duffy on 5/17/13.
//
//

#pragma once
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/GlslProg.h"

using namespace ci;

class Background {
public:
	
	gl::TextureRef	mTexture;
	gl::GlslProgRef	mShader;
	
	void setup();
	void update();
	void render();
	void resize(float wid, float hei);
	
	void bindShader();
	void unbindShader();
	
};
