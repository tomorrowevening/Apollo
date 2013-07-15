//
//  ApolloToggle.cpp
//  TouchNav
//
//  Created by Colin Duffy on 7/6/13.
//
//

#include "ApolloToggle.h"
#include "ApolloGL.h"

namespace Apollo {
	
	void ToggleButton::select() {
		_selected = true;
	}
	
	void ToggleButton::deselect() {
		_selected = false;
	}
	
	void ToggleButton::toggle() {
		_selected ? deselect() : select();
	}
	
	void ToggleButton::drawBounds() {
		gl::noFill();
		gl::setColor(255, _selected ? 255 : 0, 0);
		gl::drawRect(x, y, width, height);
		gl::fill();
	}
	
	void ToggleButton::onPress(MouseEvent& evt) { select(); }
	void ToggleButton::onTouchUpInside(TouchEvent& evt) { toggle(); }
	
}
