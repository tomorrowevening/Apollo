//
//  Tween.h
//  Apollo
//  Created by Colin Duffy on 5/3/13.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloAnimationEnum.h"
#include "ApolloVec.h"
#include <Poco/Timestamp.h>

namespace Apollo {
	
	using namespace std;
	using namespace Apollo;

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
		void setEase(Vec2f c0, Vec2f c1);
		void setPenner(PennerEases ease);
		void setStepped();
		
	};
}