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
	
	void ToggleButton::onPress(MouseEvent& evt) { select(); }
	void ToggleButton::onTouchUpInside(TouchEvent& evt) { toggle(); }
	
}
