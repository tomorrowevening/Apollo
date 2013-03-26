#pragma once

#include "ofMain.h"
#include "DragBezier.h"

/**
 * A draggable bezier curve for timeline use of custom easing.
 */
class testApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void keyPressed  (int key);
	
	DragBezier bez;
};
