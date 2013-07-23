//
//  ApolloSlider.cpp
//
//  Created by Colin Duffy on 7/6/13.
//
//

#include "ApolloSlider.h"
#include "ApolloGL.h"

namespace Apollo {
	
	void Slider::setup(float _x, float _y, float _width, float _height) {
		Button::setup(_x, _y, _width, _height);
		remap();
	}
	
	void Slider::render() {
		if(_isDown) {
			gl::setColor(16);
		}
#ifndef APOLLO_COCOA_TOUCH
		else if(_isOver) {
			gl::setColorGL(0.8f);
		}
#endif
		else {
			gl::setColorGL(0, _enabled ? 1.f : 0.5f);
		}
		gl::drawRect(position, size);
		gl::setColorGL(0.25f);
		if(direction == SLIDER_HORIZONTAL) {
			gl::drawRect(position.x, position.y, size.x*percent, size.y);
		} else {
			float amt = size.y*percent;
			gl::drawRect(position.x, position.y + amt, size.x, amt);
		}
		
		gl::setColorGL(1.f);
		gl::drawText(name + ": " + toString(round(value)), position.x + 10, position.y + 18);
	}
	
	void Slider::onPress(MouseEvent& evt) {
		scrollTo(evt.x, evt.y);
	}
	
	void Slider::onTouchDown(TouchEvent& evt) {
		scrollTo(evt.x, evt.y);
	}
	
	void Slider::onTouchMove(TouchEvent& evt) {
		scrollTo(evt.x, evt.y);
	}
	
	
}
