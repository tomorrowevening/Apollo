//
//  DragPoint.h
//
//  Created by Colin Duffy on 3/25/13.
//
//

#pragma once
#include "ofMain.h"
#include "ofxMSAInteractiveObject.h"

#define DRAG_POINT_SIZE		14.0f
#define DRAG_POINT_SIZE_H	DRAG_POINT_SIZE * 0.5f

class DragPoint : public ofxMSAInteractiveObject {
public:
	
	DragPoint() {
		alignment = ALIGN_MID_CENTER;
	}
	
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
		else if(isMouseOver())
			ofSetColor(255, 0, 0, 204);
		else
			ofSetColor(255, 0, 0, 102);
		
		const float halfW = width  * 0.5f;
		const float halfH = height * 0.5f;
		switch (alignment) {
			case ALIGN_TOP_LEFT:
			default:
				ofRect(x, y, width, height);
				break;
			case ALIGN_TOP_CENTER:
				ofRect(x-halfW, y, width, height);
				break;
			case ALIGN_TOP_RIGHT:
				ofRect(x-width, y, width, height);
				break;
				
			case ALIGN_MID_LEFT:
				ofRect(x, y-halfH, width, height);
				break;
			case ALIGN_MID_CENTER:
				ofRect(x-halfW, y-halfH, width, height);
				break;
			case ALIGN_MID_RIGHT:
				ofRect(x-width, y-halfH, width, height);
				break;
				
			case ALIGN_BOT_LEFT:
				ofRect(x, y-height, width, height);
				break;
			case ALIGN_BOT_CENTER:
				ofRect(x-halfW, y-height, width, height);
				break;
			case ALIGN_BOT_RIGHT:
				ofRect(x-width, y-height, width, height);
				break;
		}
	}
	
};
