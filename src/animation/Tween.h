//
//  Tween.h
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
		
		static const int BEZIER_SEGMENTS = 12;
		
		CubicEase points;
		float curves[6];
		
		void setCurve(float x0, float y0, float x1, float y1);
		float getCurvePercent(float percent);
		
	public:
		
		float* var;
		float from, to, duration;
		Poco::Timestamp timestamp;
		
		// Generic
		void update(float percent);
		
		// Getters
		static CubicEase getEase(PennerEases ease);
		
		// Setters
		void setLinear();
		void setEase(float x0, float y0, float x1, float y1);
		void setEase(vec2f c0, vec2f c1);
		void setStepped();
		
		void setPenner(PennerEases ease);
		
		// Getters
		float range();
		
	};
}