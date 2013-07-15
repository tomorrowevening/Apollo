//
//  ApolloButton.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"
#include "ApolloStrings.h"
#include "ApolloVec.h"

namespace Apollo {
	using namespace std;
	using namespace Apollo;
	
	class Button : public Rectangle {
	public:
		
		string name;
		static int buttonIndex;
		
		Button();
		virtual ~Button();
		
		virtual void setup(float _x, float _y, float _width, float _height);
		virtual void enable();
		virtual void disable();
		virtual void update();
		virtual void draw();
		virtual void drawBounds();
		virtual bool hitTest(float x, float y) { return Rectangle::inside(x, y); }
		
		// Getters
		const bool enabled() { return _enabled; }
		const bool isPressed() { return _isDown; }
		const bool isOver() { return _isOver; }
		
	protected:
		
		bool _enabled, _isOver, _isDown;
		
		void enableMouse();
		void enableTouch();
		void disableMouse();
		void disableTouch();
		
		// Generic handlers
		void mouseHandler(MouseEvent& evt);
		virtual void onMouseMoved(MouseEvent& evt);
		virtual void onMousePressed(MouseEvent& evt);
		virtual void onMouseReleased(MouseEvent& evt);
		
		void touchHandler(TouchEvent& evt);

		// Mouse events
		virtual void onRollOver(MouseEvent& evt) {}
		virtual void onRollOut(MouseEvent& evt) {}
		virtual void onPress(MouseEvent& evt) {}
		virtual void onReleased(MouseEvent& evt) {}
		virtual void onReleasedOutside(MouseEvent& evt) {}
		virtual void onScroll(MouseEvent& evt) {}

		// Touch events
		virtual void onTouchDown(TouchEvent& evt) {}
		virtual void onTouchUpInside(TouchEvent& evt) {}
		virtual void onTouchUpOutside(TouchEvent& evt) {}
		virtual void onTouchMove(TouchEvent& evt) {}
		virtual void onTouchDoubleTap(TouchEvent& evt) {}
		virtual void onTouchCancel(TouchEvent& evt) {}
		
	private:
		
		static void eventHandler(Event& evt);
		
	};
}
