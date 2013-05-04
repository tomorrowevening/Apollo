//
//  Tween.cpp
//  Created by Colin Duffy on 5/3/13.
//

#include "Tween.h"

void Tween::setLinear() {
	curves[0] = Linear;
}

void Tween::setPenner(PennerEases ease) {
	curves[0] = Custom;
	
	switch (ease) {
			// Circ
		case EaseCircIn:
			c0.set(0.600, 0.040);	c1.set(0.980, 0.335);	break;
		case EaseCircInOut:
			c0.set(0.785, 0.135);	c1.set(0.150, 0.860);	break;
		case EaseCircOut:
			c0.set(0.075, 0.820);	c1.set(0.165, 1.000);	break;
			
			// Cubic
		case EaseCubicIn:
			c0.set(0.550, 0.055);	c1.set(0.675, 0.190);	break;
		case EaseCubicInOut:
			c0.set(0.645, 0.045);	c1.set(0.355, 1.000);	break;
		case EaseCubicOut:
			c0.set(0.215, 0.610);	c1.set(0.355, 1.000);	break;
			
			// Expo
		case EaseExpoIn:
			c0.set(0.950, 0.050);	c1.set(0.795, 0.035);	break;
		case EaseExpoInOut:
			c0.set(1.000, 0.000);	c1.set(0.000, 1.000);	break;
		case EaseExpoOut:
			c0.set(0.190, 1.000);	c1.set(0.220, 1.000);	break;
			
			// Quad
		case EaseQuadIn:
			c0.set(0.550, 0.085);	c1.set(0.680, 0.530);	break;
		case EaseQuadInOut:
			c0.set(0.455, 0.030);	c1.set(0.515, 0.955);	break;
		case EaseQuadOut:
			c0.set(0.250, 0.460);	c1.set(0.450, 0.940);	break;
			
			// Quart
		case EaseQuartIn:
			c0.set(0.895, 0.030);	c1.set(0.685, 0.220);	break;
		case EaseQuartInOut:
			c0.set(0.860, 0.000);	c1.set(0.070, 1.000);	break;
		case EaseQuartOut:
			c0.set(0.230, 1.000);	c1.set(0.320, 1.000);	break;
			
			// Quint
		case EaseQuintIn:
			c0.set(0.755, 0.050);	c1.set(0.855, 0.060);	break;
		case EaseQuintInOut:
			c0.set(0.770, 0.000);	c1.set(0.175, 1.000);	break;
		case EaseQuintOut:
			c0.set(0.165, 0.840);	c1.set(0.440, 1.000);	break;
			
			// Sine
		case EaseSineIn:
			c0.set(0.470, 0.000);	c1.set(0.745, 0.715);	break;
		case EaseSineInOut:
			c0.set(0.445, 0.050);	c1.set(0.550, 0.950);	break;
		case EaseSineOut:
			c0.set(0.390, 0.575);	c1.set(0.565, 1.000);	break;
			
			// Linear
		case EaseLinear:
		default:
			c0.set(0.333f, 0.333f);	c1.set(0.667f, 0.667f);	break;
	}
	if(ease != EaseLinear) setCurve(c0.x, c0.y, c1.x, c1.y);
}

void Tween::setStepped() {
	curves[0] = Stepped;
}

#pragma mark - Private

void Tween::setCurve(float x0, float y0, float x1, float y1) {
	float subdiv_step  = 1.f / (float)BEZIER_SEGMENTS;
	float subdiv_step2 = subdiv_step  * subdiv_step;
	float subdiv_step3 = subdiv_step2 * subdiv_step;
	float pre1 = 3.f * subdiv_step;
	float pre2 = 3.f * subdiv_step2;
	float pre4 = 6.f * subdiv_step2;
	float pre5 = 6.f * subdiv_step3;
	
	float tmp1x = -x0 * 2 + x1;
	float tmp1y = -y0 * 2 + y1;
	float tmp2x = (x0 - x1) * 3 + 1;
	float tmp2y = (y0 - y1) * 3 + 1;
	
	curves[0] = cx1 * pre1 + tmp1x * pre2 + tmp2x * subdiv_step3;
	curves[1] = cy1 * pre1 + tmp1y * pre2 + tmp2y * subdiv_step3;
	curves[2] = tmp1x * pre4 + tmp2x * pre5;
	curves[3] = tmp1y * pre4 + tmp2y * pre5;
	curves[4] = tmp2x * pre5;
	curves[5] = tmp2y * pre5;
}

float Tween::getCurvePercent(float percent) {
	float dfx = curves[curveIndex];
	if (dfx == LINEAR)	return percent;
	if (dfx == STEPPED)	return 0;
	
	float dfy = curves[curveIndex + 1];
	float ddfx = curves[curveIndex + 2];
	float ddfy = curves[curveIndex + 3];
	float dddfx = curves[curveIndex + 4];
	float dddfy = curves[curveIndex + 5];
	float x = dfx;
	float y = dfy;
	int i = BEZIER_SEGMENTS - 2;
	while (true) {
		if (x >= percent) {
			var lastX:Number = x - dfx;
			var lastY:Number = y - dfy;
			return lastY + (y - lastY) * (percent - lastX) / (x - lastX);
		}
		if (i == 0) break;
		i--;
		dfx += ddfx;
		dfy += ddfy;
		ddfx += dddfx;
		ddfy += dddfy;
		x += dfx;
		y += dfy;
	}
	return y + (1 - y) * (percent - x) / (1 - x);
}