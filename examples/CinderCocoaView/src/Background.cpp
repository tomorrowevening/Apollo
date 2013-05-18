//
//  Background.cpp
//  CinderCocoaView
//
//  Created by colin.duffy on 5/17/13.
//
//

#include "Background.h"
#include "Resources.h"

void Background::setup() {
	try {
		mTexture = gl::Texture::create(1000, 600);
	}
	catch( ... ) {
		std::cout << "unable to load the texture file!" << std::endl;
	}
	
	try {
		mShader = gl::GlslProg::create( app::loadResource( BG_VERT ), app::loadResource( BG_FRAG ) );
	}
	catch( gl::GlslProgCompileExc &exc ) {
		std::cout << "Shader compile error: " << std::endl;
		std::cout << exc.what();
	}
	catch( ... ) {
		std::cout << "Unable to load shader" << std::endl;
	}
}

void Background::update() {
	
}

void Background::bindShader() {
	float time = app::getElapsedSeconds();
	Vec2f size = Vec2f( app::getWindowWidth(), app::getWindowHeight() );
	
	mTexture->enableAndBind();
	mShader->bind();
	mShader->uniform( "time", time );
	mShader->uniform( "resolution", size );
}

void Background::unbindShader() {
	mShader->unbind();
	mTexture->unbind();
}

void Background::render() {
//	bindShader();
	gl::drawSolidRect( app::getWindowBounds() );
//	unbindShader();
}

void Background::resize(float wid, float hei) {
	mTexture = gl::Texture::create(wid, hei);
}
