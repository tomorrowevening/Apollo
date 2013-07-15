//
//  ApolloSlider.cpp
//
//  Created by Colin Duffy on 7/6/13.
//
//

#include "ApolloSlider.h"
#include "ApolloGL.h"

namespace Apollo {
	
	void Slider::draw() {
		if(_isDown) {
			gl::setColor(16);
		}
#ifndef APOLLO_COCOA_TOUCH
		else if(_isOver) {
			gl::setColor(204);
		}
#endif
		else {
			gl::setColor(0, _enabled ? 255 : 102);
		}
		gl::drawRect(x, y, width, height);
		gl::setColor(64);
		if(direction == SLIDER_HORIZONTAL) {
			gl::drawRect(x, y, width*percent, height);
		} else {
			float amt = height*percent;
			gl::drawRect(x, y + amt, width, amt);
		}
		
		gl::setColor(255);
		gl::drawText(name + ": " + toString(round(value)), x + 10, y + 18);
		drawBounds();
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
