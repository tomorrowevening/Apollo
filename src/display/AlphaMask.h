//
//  AlphaMask.h
//
//  Created by Colin Duffy on 2/27/13.
//
//

#pragma once

#include "ofMain.h"

class AlphaMask {
public:
	
	ofTexture mask;
	ofTexture content;
	ofShader shader;
	
	bool useMask;
	
	void setup(int wid, int hei);
	void dispose();
	void render(float x = 0, float y = 0);
	
};