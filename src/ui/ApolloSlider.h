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
	public:
		
		float min, max, percent, value;
		SliderType direction;
		
		Slider() {
			min = 0;
			max = 1;
			value = 0;
			direction = SLIDER_HORIZONTAL;
		}
		
		void scrollTo(float tx, float ty) {
			if(direction == SLIDER_HORIZONTAL) {
				percent = (tx - x) / width;
			} else {
				percent = (height - ty - y) / height;
			}
			percent = clamp(percent, 0, 1);
			value = percent * (max - min);
		}
		
		virtual void draw();
		virtual void onPress(MouseEvent& evt);
		virtual void onTouchDown(TouchEvent& evt);
		virtual void onTouchMove(TouchEvent& evt);
		
	};
	
}
