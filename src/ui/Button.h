//
//  Button.h
//  MultiDeviceConnect
//
//  Created by Colin Duffy on 4/15/13.
//
//

#pragma once
#include "ofMain.h"

class Button : public ofRectangle {
public:
	
	// Events
	ofEvent<string> CLICK;
	
	bool enabled, drawBounds;
	string buttonID;
	
	Button();
	~Button();
	
	virtual void enable();
	virtual void disable();
	
	virtual void setup() {}
	virtual void exit() {}
	virtual void render();
	
	// Events
	virtual void onDown() {}
	virtual void onUp() {}
	virtual void onOver() {}
	virtual void onOut() {}
	virtual void onDouble() {}
	
	// Getters
	bool isPressed() { return pressed; }
	bool isOver() { return over; }
	
	virtual bool hitTest(float tx, float ty) {
		return inside(tx, ty);
	}
	
	// Setters
	void setRect(float rx, float ry, float rw, float rh) {
		x = rx;
		y = ry;
		width  = rw;
		height = rh;
	}
	
protected:
	
	static int btnCount;
	bool pressed, over;
	
	void enableMouse();
	void disableMouse();
	
	void enableTouch();
	void disableTouch();
	
	// Mouse events handlers
	void _mouseDown(ofMouseEventArgs &e);
	void _mouseUp(ofMouseEventArgs &e);
	void _mouseMove(ofMouseEventArgs &e);
	
	// Touch events handlers
	void _touchDown(ofTouchEventArgs &e);
	void _touchUp(ofTouchEventArgs &e);
	void _touchDouble(ofTouchEventArgs &e);
	
};
