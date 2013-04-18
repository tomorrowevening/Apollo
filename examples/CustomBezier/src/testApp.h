#pragma once

#include "ofMain.h"
#include "DragBezier.h"

// Uncomment this if you have the addon
#include "ofxUI.h"

class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	void reset();
	
	float duration, time;
	bool playing;
	DragBezier bez;
	
#ifdef OFXUI
	void exit();
	
	ofxUICanvas* gui;
	void reposition();
	void guiEvent(ofxUIEventArgs &e);
#endif
};
