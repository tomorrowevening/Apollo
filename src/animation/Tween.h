//
//  Tween.h
//  Apollo
//  Created by Colin Duffy on 5/3/13.
//

#pragma once
#include "Apollo.h"
#include "AnimationEnum.h"
#include "Vec.h"
#include <Poco/Timestamp.h>

namespace Apollo {

	class Tween {
	protected:
		
		CubicEase points;
		
	public:
		
		float* var;
		float from, to, duration;
		Poco::Timestamp timestamp;
		void update(float percent);
		
		// Getters
		float range();
		static CubicEase getEase(PennerEases ease);
		
		// Setters
		void setLinear();
		void setEase(float x0, float y0, float x1, float y1);
		void setEase(vec2f c0, vec2f c1);
		void setPenner(PennerEases ease);
		void setStepped();
		
	};
}