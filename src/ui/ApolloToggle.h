//
//  ApolloToggle.h
//  TouchNav
//
//  Created by Colin Duffy on 7/6/13.
//
//

#pragma once
#include "ApolloButton.h"
#include "ApolloGL.h"

namespace Apollo {
	using namespace std;
	using namespace Apollo;
	
	class ToggleButton : public Button {
	public:
		
		ToggleButton() {
			_selected = false;
		}
		
		virtual void drawBounds();
		void select();
		void deselect();
		void toggle();
		
		// Getters
		bool selected() {
			return _selected;
		}
		
		// Setters
		void selected(bool value) {
			value ? select() : deselect();
		}
		
		virtual void onPress(MouseEvent& evt);
		virtual void onTouchUpInside(TouchEvent& evt);
		virtual void onReleasedOutside(MouseEvent& evt) {}
		virtual void onTouchUpOutside(TouchEvent& evt) {}
		
	protected:
		bool _selected;
	};
	
}
