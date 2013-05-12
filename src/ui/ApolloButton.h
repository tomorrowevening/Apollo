//
//  ApolloButton.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"
#include "ApolloEvent.h"
#include "ApolloVec.h"

namespace Apollo {
	using namespace std;
	using namespace Apollo;
	
	class Button : public Rectangle {
	protected:
		
		void enableMouse();
		void enableTouch();
		void disableMouse();
		void disableTouch();
		
		// Handlers
//		void onMouseEvent(MouseEvent& evt);
//		void onTouchEvent(TouchEvent& evt);
//		
//		// Mouse events
//		virtual void onRollOver(MouseEvent& evt) {}
//		virtual void onRollOut(MouseEvent& evt) {}
//		virtual void onClick(MouseEvent& evt) {}
//		virtual void onPress(MouseEvent& evt) {}
//		virtual void onReleased(MouseEvent& evt) {}
//		virtual void onReleasedOutside(MouseEvent& evt) {}
//		virtual void onScroll(MouseEvent& evt) {}
//		
//		// Touch events
//		virtual void onTouchDown(TouchEvent& evt) {}
//		virtual void onTouchUp(TouchEvent& evt) {}
//		virtual void onTouchMove(TouchEvent& evt) {}
//		virtual void onTouchDoubleTap(TouchEvent& evt) {}
//		virtual void onTouchCancel(TouchEvent& evt) {}
		
	public:
		
		virtual void setup(float _x, float _y, float _width, float _height);
		virtual void enable();
		virtual void disable();
		virtual void update();
		virtual void draw();
		virtual void drawBounds();
		
	private:
		void eventHandler(Event& evt);
		
	};
}
