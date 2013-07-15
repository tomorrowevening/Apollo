//
//  ApolloSlider.h
//
//  Created by Colin Duffy on 7/6/13.
//
//

#pragma once
#include "Apollo.h"

namespace Apollo {
	using namespace std;
	using namespace Apollo;
	
	enum SliderType {
		SLIDER_HORIZONTAL = 0,
		SLIDER_VERTICAL
	};
	
	class Slider : public Button {
	private:
		void remap() {
			percent = clamp(percent, 0, 1);
			value = percent * (max - min);
		}
	public:
		
		float min, max, percent, value;
		SliderType direction;
		
		Slider() {
			min = 0;
			max = 1;
			percent = 0.5;
			direction = SLIDER_HORIZONTAL;
			remap();
		}
		
		void scrollTo(float percent) {
			this->percent = percent;
			remap();
		}
		
		void scrollTo(float tx, float ty) {
			if(direction == SLIDER_HORIZONTAL) {
				percent = (tx - x) / width;
			} else {
				percent = (height - ty - y) / height;
			}
			remap();
		}
		
		virtual void setup(float _x, float _y, float _width, float _height);
		virtual void draw();
		virtual void onPress(MouseEvent& evt);
		virtual void onTouchDown(TouchEvent& evt);
		virtual void onTouchMove(TouchEvent& evt);
		
	};
	
}
