#pragma once

#include "ofMain.h"
#include "Apollo.h"
#include "DragBezier.h"
#include "Button.h"

using namespace Apollo;

class testApp : public ofBaseApp{
public:
	void setup();
	void exit();
	void update();
	void draw();

	void keyPressed  (int key);
	
	DragBezier bezier;
	
	ofPoint target;
	Apollo::Button btn;
	void btnHandler(string& btnID);
};
