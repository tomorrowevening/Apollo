//
//  ApolloButton.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#include "ApolloButton.h"
#include "ApolloGL.h"

namespace Apollo {
	
	int Button::buttonIndex = 0;
	
	Button::Button() {
		_enabled = _isOver = _isDown = false;
		name = "btn_" + Apollo::toString(Button::buttonIndex);
		++Button::buttonIndex;
	}
	
	Button::~Button() { disable(); }
	
	void Button::setup(float _x, float _y, float _width, float _height) {
		x = _x;
		y = _y;
		width  = _width;
		height = _height;
	}
	
	void Button::enable() {
		_enabled = true;
#ifdef APOLLO_COCOA_TOUCH
		enableTouch();
#else
		enableMouse();
#endif
	}
	
	void Button::disable() {
		_enabled = false;
#ifdef APOLLO_COCOA_TOUCH
		disableTouch();
#else
		disableMouse();
#endif
	}
	
	void Button::update() {
		
	}
	
	void Button::draw() {
		if(_isDown) {
			gl::setColor(255, 0, 0);
		}
#ifndef APOLLO_COCOA_TOUCH
		else if(_isOver) {
			gl::setColor(204);
		}
#endif
	else {
		gl::setColor(0, _enabled ? 255 : 102);
	}
		gl::setColor(0, _enabled ? 255 : 102);
		gl::drawRect(x, y, width, height);
		gl::setColor(255);
		gl::drawText(name, x+10, y+15);
		drawBounds();
	}
	
	void Button::drawBounds() {
		gl::noFill();
		gl::setColor(255, 0, 0);
		gl::drawRect(x, y, width, height);
		gl::fill();
	}
	
#pragma mark - Private
	
	void Button::enableMouse() {
		Dispatcher.addListener(MouseEvent::DRAGGED,		this, &Button::eventHandler);
		Dispatcher.addListener(MouseEvent::MOVED,		this, &Button::eventHandler);
		Dispatcher.addListener(MouseEvent::PRESSED,		this, &Button::eventHandler);
		Dispatcher.addListener(MouseEvent::RELEASED,	this, &Button::eventHandler);
		Dispatcher.addListener(MouseEvent::SCROLLED,	this, &Button::eventHandler);
	}
	
	void Button::enableTouch() {
		Dispatcher.addListener(TouchEvent::CANCEL,		this, &Button::eventHandler);
		Dispatcher.addListener(TouchEvent::DOUBLE_TAP,	this, &Button::eventHandler);
		Dispatcher.addListener(TouchEvent::DOWN,		this, &Button::eventHandler);
		Dispatcher.addListener(TouchEvent::MOVE,		this, &Button::eventHandler);
		Dispatcher.addListener(TouchEvent::UP,			this, &Button::eventHandler);
	}
	
	void Button::disableMouse() {
		Dispatcher.removeListener(MouseEvent::DRAGGED,	this, &Button::eventHandler);
		Dispatcher.removeListener(MouseEvent::MOVED,	this, &Button::eventHandler);
		Dispatcher.removeListener(MouseEvent::PRESSED,	this, &Button::eventHandler);
		Dispatcher.removeListener(MouseEvent::RELEASED,	this, &Button::eventHandler);
		Dispatcher.removeListener(MouseEvent::SCROLLED,	this, &Button::eventHandler);
	}
	
	void Button::disableTouch() {
		Dispatcher.removeListener(TouchEvent::CANCEL,		this, &Button::eventHandler);
		Dispatcher.removeListener(TouchEvent::DOUBLE_TAP,	this, &Button::eventHandler);
		Dispatcher.removeListener(TouchEvent::DOWN,			this, &Button::eventHandler);
		Dispatcher.removeListener(TouchEvent::MOVE,			this, &Button::eventHandler);
		Dispatcher.removeListener(TouchEvent::UP,			this, &Button::eventHandler);
	}
	
#pragma mark - Handlers
	
	void Button::onMouseMoved(MouseEvent& evt) {
		if(hitTest(evt.x, evt.y)) {
			if(!_isOver) onRollOut(evt);
			_isOver = true;
		} else if(_isOver) {
			onRollOut(evt);
			_isOver = false;
		}
	}
	
	void Button::onMousePressed(MouseEvent& evt) {
		if(hitTest(evt.x, evt.y)) {
			if(!_isDown) onPress(evt);
			_isDown = true;
		}
	}
	
	void Button::onMouseReleased(MouseEvent& evt) {
		if(_isDown) {
			if(hitTest(evt.x, evt.y)) {
				onReleased(evt);
			} else {
				onReleasedOutside(evt);
			}
		}
		
		_isDown = false;
	}
	
	void Button::mouseHandler(MouseEvent& evt) {
		if(evt.type == MouseEvent::MOVED) {
			onMouseMoved(evt);
		} else if(evt.type == MouseEvent::PRESSED) {
			onMousePressed(evt);
		} else if(evt.type == MouseEvent::RELEASED) {
			onMouseReleased(evt);
		} else if(evt.type == MouseEvent::SCROLLED) {
			onScroll(evt);
		}
	}
	
	void Button::touchHandler(TouchEvent& evt) {
		if(evt.type == TouchEvent::CANCEL) {
			_isDown = false;
			onTouchCancel(evt);
		} else if(evt.type == TouchEvent::DOUBLE_TAP) {
			if(hitTest(evt.x, evt.y)) onTouchDoubleTap(evt);
		} else if(evt.type == TouchEvent::DOWN) {
			if(hitTest(evt.x, evt.y)) {
				_isDown = true;
				onTouchDown(evt);
			}
		} else if(evt.type == TouchEvent::MOVE) {
			if(_isDown) onTouchMove(evt);
		} else if(evt.type == TouchEvent::UP) {
			if(_isDown) {
				_isDown = false;
				hitTest(evt.x, evt.y) ? onTouchUpInside(evt) : onTouchUpOutside(evt);
			}
		}
	}
	
	void Button::eventHandler(Event& evt) {
		Button* btn = (Button*)evt.listener;
		if(!btn->enabled()) return;
		
#ifdef APOLLO_COCOA_TOUCH
		// Touch
//		printf("BTN: %s, %i\n", btn->name.c_str(), btn->hitTest(((TouchEvent&)evt).x, ((TouchEvent&)evt).y));
		if(evt.type == TouchEvent::CANCEL)			btn->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::DOUBLE_TAP)	btn->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::DOWN)		btn->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::MOVE)		btn->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::UP)			btn->touchHandler( (TouchEvent&)evt );
#else
		// Mouse
		if(evt.type == MouseEvent::DRAGGED)			btn->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::MOVED)		btn->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::PRESSED)	btn->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::RELEASED)	btn->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::SCROLLED)	btn->mouseHandler( (MouseEvent&)evt );
#endif
	}
	
}
