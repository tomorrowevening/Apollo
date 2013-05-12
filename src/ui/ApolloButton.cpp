//
//  ApolloButton.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#include "ApolloButton.h"

namespace Apollo {
	
	void Button::setup(float _x, float _y, float _width, float _height) {
		x = _x;
		y = _y;
		width  = _width;
		height = _height;
	}
	
	void Button::enable() {
#ifdef APOLLO_COCOA_TOUCH
		enableTouch();
#else
		enableMouse();
#endif
	}
	
	void Button::disable() {
#ifdef APOLLO_COCOA_TOUCH
		disableTouch();
#else
		disableMouse();
#endif
	}
	
	void Button::update() {
		
	}
	
	void Button::draw() {
		
	}
	
	void Button::drawBounds() {
		
	}
	
#pragma mark - Private
	
	void Button::enableMouse() {
//		Trigger.addListener(MouseEvent::CLICK(), this, &Button::onMouseEvent);
	}
	
	void Button::enableTouch() {
		
	}
	
	void Button::disableMouse() {
		
	}
	
	void Button::disableTouch() {
		
	}
	
#pragma mark - Handlers
	
//	void Button::onMouseEvent(MouseEvent& evt) {
//		if(evt.type == MouseEvent::CLICK())					onClick(evt);
//		else if(evt.type == MouseEvent::OUT())				onRollOut(evt);
//		else if(evt.type == MouseEvent::OVER())				onRollOver(evt);
//		else if(evt.type == MouseEvent::PRESSED())			onPress(evt);
//		else if(evt.type == MouseEvent::RELEASED())			onReleased(evt);
//		else if(evt.type == MouseEvent::RELEASED_OUTSIDE())	onReleasedOutside(evt);
//		else if(evt.type == MouseEvent::SCROLL())			onScroll(evt);
//	}
	
//	void Button::onTouchEvent(TouchEvent& evt) {
//		if(evt.type == TouchEvent::CANCEL())			onTouchCancel(evt);
//		else if(evt.type == TouchEvent::DOUBLE_TAP())	onTouchDoubleTap(evt);
//		else if(evt.type == TouchEvent::DOWN())			onTouchDown(evt);
//		else if(evt.type == TouchEvent::MOVE())			onTouchMove(evt);
//		else if(evt.type == TouchEvent::UP())			onTouchUp(evt);
//	}
	
	void Button::eventHandler(Event& evt) {
		
	}
	
}
