//
//  Tween.cpp
//  Apollo
//  Created by Colin Duffy on 5/3/13.
//

#include "ApolloTween.h"

namespace Apollo {

	void Tween::update(float percent) {
		var[0] = points.getCurvePercent(percent) * range() + from;
	}

	//////////////////////////////////////////////////
	#pragma mark - Setters
	//////////////////////////////////////////////////

	void Tween::setLinear() {
		points.setLinear();

	}
	void Tween::setEase(float x0, float y0, float x1, float y1) {
		points.set(x0, y0, x1, y1);
	}

	void Tween::setEase(Vec2f c0, Vec2f c1) {
		points.set(c0, c1);
	}
	
	void Tween::setPenner(PennerEases ease) {
		points.copy( getEase(ease) );
	}

	void Tween::setStepped(){
		points.setStepped();
	}

	//////////////////////////////////////////////////
	#pragma mark - Getters
	//////////////////////////////////////////////////

	float Tween::range() {
		return to - from;
	}
	
	CubicEase Tween::getEase(PennerEases ease) {
		return CubicEase::getPenner(ease);
	}

}