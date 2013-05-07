//
//  Tween.cpp
//  Created by Colin Duffy on 5/3/13.
//

#include "Tween.h"

namespace Apollo {

	void Tween::update(float percent) {
		var[0] = getCurvePercent(percent) * range() + from;
	}

	//////////////////////////////////////////////////
	#pragma mark - Setters
	//////////////////////////////////////////////////

	void Tween::setLinear() {
		curves[0] =  0;

	}
	void Tween::setEase(float x0, float y0, float x1, float y1) {
		setCurve(x0, y0, x1, y1);
	}

	void Tween::setEase(vec2f c0, vec2f c1) {
		setCurve(c0.x, c0.y, c1.x, c1.y);
	}

	void Tween::setStepped(){
		curves[0] = -1;
	}

	void Tween::setPenner(PennerEases ease) {
		points = getEase(ease);
	}

	void Tween::setCurve(float x0, float y0, float x1, float y1) {
		points.set(x0, y0, x1, y1);
		
		float subdiv_step = 1.f / (float)BEZIER_SEGMENTS;
		float subdiv_step2 = subdiv_step * subdiv_step;
		float subdiv_step3 = subdiv_step2 * subdiv_step;
		float pre1 = 3 * subdiv_step;
		float pre2 = 3 * subdiv_step2;
		float pre4 = 6 * subdiv_step2;
		float pre5 = 6 * subdiv_step3;
		float tmp1x = -x0 * 2 + x1;
		float tmp1y = -y0 * 2 + y1;
		float tmp2x = (x0 - x1) * 3 + 1;
		float tmp2y = (y0 - y1) * 3 + 1;
		
		curves[0] = x0 * pre1 + tmp1x * pre2 + tmp2x * subdiv_step3;
		curves[1] = y0 * pre1 + tmp1y * pre2 + tmp2y * subdiv_step3;
		curves[2] = tmp1x * pre4 + tmp2x * pre5;
		curves[3] = tmp1y * pre4 + tmp2y * pre5;
		curves[4] = tmp2x * pre5;
		curves[5] = tmp2y * pre5;
	}

	//////////////////////////////////////////////////
	#pragma mark - Getters
	//////////////////////////////////////////////////

	float Tween::range() {
		return to - from;
	}

	float Tween::getCurvePercent(float percent) {
		float dfx = curves[0];
		if (dfx ==  0)	return percent;
		if (dfx == -1)	return 0;
		
		float dfy   = curves[1];
		float ddfx  = curves[2];
		float ddfy  = curves[3];
		float dddfx = curves[4];
		float dddfy = curves[5];
		float x = dfx;
		float y = dfy;
		int i = BEZIER_SEGMENTS - 2;
		while (true) {
			if (x >= percent) {
				float lastX = x - dfx;
				float lastY = y - dfy;
				return lastY + (y - lastY) * (percent - lastX) / (x - lastX);
			}
			if (i == 0) break;
			i--;
			dfx  += ddfx;
			dfy  += ddfy;
			ddfx += dddfx;
			ddfy += dddfy;
			x += dfx;
			y += dfy;
		}
		return y + (1 - y) * (percent - x) / (1 - x);
	}
	
	CubicEase Tween::getEase(PennerEases ease) {
		CubicEase pts;
		
		switch (ease) {
				// Circ
			case EaseCircIn:
				pts.set(0.600, 0.040, 0.980, 0.335);		break;
			case EaseCircInOut:
				pts.set(0.785, 0.135, 0.150, 0.860);		break;
			case EaseCircOut:
				pts.set(0.075, 0.820, 0.165, 1.000);		break;
				
				// Cubic
			case EaseCubicIn:
				pts.set(0.550, 0.055, 0.675, 0.190);		break;
			case EaseCubicInOut:
				pts.set(0.645, 0.045, 0.355, 1.000);		break;
			case EaseCubicOut:
				pts.set(0.215, 0.610, 0.355, 1.000);		break;
				
				// Expo
			case EaseExpoIn:
				pts.set(0.950, 0.050, 0.795, 0.035);		break;
			case EaseExpoInOut:
				pts.set(1.000, 0.000, 0.000, 1.000);		break;
			case EaseExpoOut:
				pts.set(0.190, 1.000, 0.220, 1.000);		break;
				
				// Quad
			case EaseQuadIn:
				pts.set(0.550, 0.085, 0.680, 0.530);		break;
			case EaseQuadInOut:
				pts.set(0.455, 0.030, 0.515, 0.955);		break;
			case EaseQuadOut:
				pts.set(0.250, 0.460, 0.450, 0.940);		break;
				
				// Quart
			case EaseQuartIn:
				pts.set(0.895, 0.030, 0.685, 0.220);		break;
			case EaseQuartInOut:
				pts.set(0.860, 0.000, 0.070, 1.000);		break;
			case EaseQuartOut:
				pts.set(0.230, 1.000, 0.320, 1.000);		break;
				
				// Quint
			case EaseQuintIn:
				pts.set(0.755, 0.050, 0.855, 0.060);		break;
			case EaseQuintInOut:
				pts.set(0.770, 0.000, 0.175, 1.000);		break;
			case EaseQuintOut:
				pts.set(0.165, 0.840, 0.440, 1.000);		break;
				
				// Sine
			case EaseSineIn:
				pts.set(0.470, 0.000, 0.745, 0.715);		break;
			case EaseSineInOut:
				pts.set(0.445, 0.050, 0.550, 0.950);		break;
			case EaseSineOut:
				pts.set(0.390, 0.575, 0.565, 1.000);		break;
				
				// Linear
			case EaseLinear:
			default:
				pts.set(0.333f, 0.333f, 0.667f, 0.667f);	break;
		}
		
		return pts;
	}

}