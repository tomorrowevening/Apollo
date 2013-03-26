//
//  DragPoint.h
//
//  Created by Colin Duffy on 3/25/13.
//
//

#pragma once
#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

#define DRAG_POINT_SIZE		10.0f
#define DRAG_POINT_SIZE_H	DRAG_POINT_SIZE * 0.5f

class DragPoint : public ofxMSAInteractiveObject {
public:
	
	void setup() {
		setSize(DRAG_POINT_SIZE, DRAG_POINT_SIZE);
		enableMouseEvents();
	}
	
	void update() {
		if(isMouseDown()) {
			x = _mouseX;
			y = _mouseY;
		}
	}
	
	void draw() {
		if(isMouseDown())
			ofSetColor(255, 0, 0);
		else
			ofSetColor(255, 0, 0, 204);
		
		ofRect(x, y, width, height);
	}
	
};
