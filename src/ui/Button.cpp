//
//  Button.cpp
//  Apollo
//  Created by Colin Duffy on 4/15/13.
//
//

#include "Button.h"

namespace Apollo {

	int Button::btnCount = 0;

	//////////////////////////////////////////////////
	// Generic

	Button::Button() {
		buttonID = "btn_" + ofToString(btnCount);
		showBounds = false;
		pressed = over = false;
		enabled = true;
		draggable = false;
		alignment = ALIGN_TOP_LEFT;
		selectable = false;
		selected = false;
		++btnCount;
	}

	Button::~Button() {
		disable();
	}
	
	void Button::update() {
		if(!draggable) return;
		
		if(isPressed()) {
			x = ofGetMouseX();
			y = ofGetMouseY();
		}
	}

	void Button::render() {
		ofPushMatrix();
		ofTranslate(boundsX(), boundsY());
		
		if(pressed || selected) {
			ofSetColor(204, 0, 0);
		} else if(over) {
			ofSetColor(102, 0, 0);
		} else {
			ofSetColor(0);
		}
		ofRect(0, 0, width, height);
		
		ofPopMatrix();
		ofSetColor(255);
		
		if(showBounds) drawBounds();
	}

	void Button::drawBounds() {
		ofPushMatrix();
		ofTranslate(boundsX(), boundsY());
		
		ofSetColor(255, 0, 0);
		ofNoFill();
		ofRect(0, 0, width, height);
		ofSetColor(255);
		ofFill();
		ofDrawBitmapString(buttonID, 5, 15);
		
		ofPopMatrix();
	}

	void Button::enable() {
	#ifdef TARGET_OPENGLES
		enableTouch();
	#else
		enableMouse();
	#endif
	}

	void Button::disable() {
	#ifdef TARGET_OPENGLES
		disableTouch();
	#else
		disableMouse();
	#endif
	}
	
	//////////////////////////////////////////////////
	// App
	
	void Button::enableAutoUpdate() {
		ofAddListener(ofEvents().update, this, &Button::_updateHandler);
		ofAddListener(ofEvents().draw, this, &Button::_drawHandler);
	}
	
	void Button::disableAutoUpdate() {
		ofRemoveListener(ofEvents().update, this, &Button::_updateHandler);
		ofRemoveListener(ofEvents().draw, this, &Button::_drawHandler);
	}
	
	void Button::_updateHandler(ofEventArgs& e) { update(); }
	void Button::_drawHandler(ofEventArgs& e) { render(); }

	//////////////////////////////////////////////////
	// Mouse

	void Button::enableMouse() {
		ofAddListener(ofEvents().mousePressed, this, &Button::_mouseDown);
		ofAddListener(ofEvents().mouseReleased, this, &Button::_mouseUp);
		ofAddListener(ofEvents().mouseMoved, this, &Button::_mouseMove);
	}

	void Button::disableMouse() {
		ofRemoveListener(ofEvents().mousePressed, this, &Button::_mouseDown);
		ofRemoveListener(ofEvents().mouseReleased, this, &Button::_mouseUp);
		ofRemoveListener(ofEvents().mouseMoved, this, &Button::_mouseMove);
	}

	//////////////////////////////////////////////////
	// Touch

	void Button::enableTouch() {
		ofAddListener(ofEvents().touchDoubleTap, this, &Button::_touchDouble);
		ofAddListener(ofEvents().touchDown, this, &Button::_touchDown);
		ofAddListener(ofEvents().touchUp, this, &Button::_touchUp);
	}

	void Button::disableTouch() {
		ofRemoveListener(ofEvents().touchDoubleTap, this, &Button::_touchDouble);
		ofRemoveListener(ofEvents().touchDown, this, &Button::_touchDown);
		ofRemoveListener(ofEvents().touchUp, this, &Button::_touchUp);
	}

	//////////////////////////////////////////////////
	#pragma mark - Mouse handlers

	void Button::_mouseDown(ofMouseEventArgs &e) {
		if(!enabled || !hitTest(e.x, e.y)) return;
		pressed = true;
		if(selectable) selected = !selected;
		
		ofNotifyEvent(CLICK, buttonID, this);
		onDown();
	}

	void Button::_mouseUp(ofMouseEventArgs &e) {
		if(!enabled) return;
		selected = false;
		if(pressed) onUp();
		pressed = false;
	}

	void Button::_mouseMove(ofMouseEventArgs &e) {
		if(!enabled) return;
		
		if(hitTest(e.x, e.y)) {
			if(!over) onOver();
			over = true;
		} else {
			if(over) onOut();
			over = false;
		}
	}


	//////////////////////////////////////////////////
	#pragma mark - Touch handlers

	void Button::_touchDown(ofTouchEventArgs &e) {
		if(!enabled || !hitTest(e.x, e.y)) return;
		pressed = true;
		if(selectable) selected = true;
		
		ofNotifyEvent(CLICK, buttonID, this);
		onDown();
	}

	void Button::_touchUp(ofTouchEventArgs &e) {
		if(!enabled) return;
		selected = false;
		if(pressed) onUp();
		pressed = false;
	}

	void Button::_touchDouble(ofTouchEventArgs &e) {
		if(!enabled) return;
		
		if(hitTest(e.x, e.y)) onDouble();
	}

}
