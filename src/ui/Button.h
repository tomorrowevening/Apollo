//
//  Button.h
//  Apollo
//  Created by Colin Duffy on 4/15/13.
//
//

#pragma once
#include "ofMain.h"
#include "MathUtil.h"

namespace Apollo {
	using namespace Apollo;
	class Button : public ofRectangle {
	public:
		
		// Events
		ofEvent<string> CLICK;
		
		bool enabled, showBounds, selectable, selected;
		string buttonID;
		MatrixAlign alignment;
		
		Button();
		~Button();
		
		virtual void enable();
		virtual void disable();
		virtual void render();
		virtual void drawBounds();
		
		// Events
		virtual void onDown() {}
		virtual void onUp() {}
		virtual void onOver() {}
		virtual void onOut() {}
		virtual void onDouble() {}
		
		// Getters
		bool isPressed() { return pressed; }
		bool isOver() { return over; }
		
		virtual bool hitTest(float tx, float ty) {
			const float midW = width  * 0.5f;
			const float midH = height * 0.5f;
			switch (alignment) {
				case ALIGN_TOP_LEFT:
				default:
					return inside(tx, ty);
					break;
				case ALIGN_TOP_CENTER:
					return inside(tx - midW, ty);
					break;
				case ALIGN_TOP_RIGHT:
					return inside(tx - width, ty);
					break;
					
				case ALIGN_MID_LEFT:
					return inside(tx, ty - midH);
					break;
				case ALIGN_MID_CENTER:
					return inside(tx - midW, ty - midH);
					break;
				case ALIGN_MID_RIGHT:
					return inside(tx - width, ty - midH);
					break;
					
				case ALIGN_BOT_LEFT:
					return inside(tx, ty - height);
					break;
				case ALIGN_BOT_CENTER:
					return inside(tx - midW, ty - height);
					break;
				case ALIGN_BOT_RIGHT:
					return inside(tx - width, ty - height);
					break;
			}
		}
		
		float boundsX() {
			if(alignment == ALIGN_TOP_LEFT || alignment == ALIGN_MID_LEFT || alignment == ALIGN_BOT_LEFT) {
				return x;
			} else if(alignment == ALIGN_MID_LEFT || alignment == ALIGN_MID_LEFT || alignment == ALIGN_MID_LEFT) {
				return x - (width * 0.5f);
			}
			return x-width;
		}
		
		float boundsY() {
			if(alignment == ALIGN_TOP_LEFT || alignment == ALIGN_MID_LEFT || alignment == ALIGN_BOT_LEFT) {
				return y;
			} else if(alignment == ALIGN_MID_LEFT || alignment == ALIGN_MID_LEFT || alignment == ALIGN_MID_LEFT) {
				return y - (height * 0.5f);
			}
			return y-height;
		}
		
		// Setters
		void setRect(float rx, float ry, float rw, float rh) {
			x = rx;
			y = ry;
			width  = rw;
			height = rh;
		}
		
	protected:
		
		static int btnCount;
		bool pressed, over;
		
		void enableMouse();
		void disableMouse();
		
		void enableTouch();
		void disableTouch();
		
		// Mouse events handlers
		void _mouseDown(ofMouseEventArgs &e);
		void _mouseUp(ofMouseEventArgs &e);
		void _mouseMove(ofMouseEventArgs &e);
		
		// Touch events handlers
		void _touchDown(ofTouchEventArgs &e);
		void _touchUp(ofTouchEventArgs &e);
		void _touchDouble(ofTouchEventArgs &e);
		
	};

}