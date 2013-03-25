//
//  Ease.h
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#pragma once

//#define PI			3.141592653589793
#define PI2			PI*2
#define PI_HALF		PI*0.5

#pragma mark - Back -

class Ease {
public:
	
	static float Linear( float t, float b, float c, float d ) {
		return c*t/d + b;
	}
	
	// Back
	static float BackIn( float t, float b, float c, float d, float s = 1.70158 ) {
		return c*(t/=d)*t*((s+1)*t - s) + b;
	}
	static float BackInOut( float t, float b, float c, float d, float s = 1.70158 ) {
		if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525))+1)*t - s)) + b;
		return c/2*((t-=2)*t*(((s*=(1.525))+1)*t + s) + 2) + b;
	}
	static float BackOut( float t, float b, float c, float d, float s = 1.70158 ) {
		return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
	}
	
	// Bounce
	static float BounceIn( float t, float b, float c, float d ) {
		return c - BounceOut(d-t, 0, c, d) + b;
	}
	static float BounceInOut( float t, float b, float c, float d ) {
		if (t < d/2) return BounceIn (t*2, 0, c, d) * .5 + b;
		else return BounceOut (t*2-d, 0, c, d) * .5 + c*.5 + b;
	}
	static float BounceOut( float t, float b, float c, float d ) {
		if ((t/=d) < (1/2.75)) {
			return c*(7.5625*t*t) + b;
		} else if (t < (2/2.75)) {
			return c*(7.5625*(t-=(1.5/2.75))*t + .75) + b;
		} else if (t < (2.5/2.75)) {
			return c*(7.5625*(t-=(2.25/2.75))*t + .9375) + b;
		} else {
			return c*(7.5625*(t-=(2.625/2.75))*t + .984375) + b;
		}
	}
	
	// Circ
	static float CircIn( float t, float b, float c, float d ) {
		return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
	}
	
	static float CircInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
		return c/2 * (sqrt(1 - (t-=2)*t) + 1) + b;
	}
	
	static float CircOut( float t, float b, float c, float d ) {
		return c * sqrt(1 - (t=t/d-1)*t) + b;
	}
	
	// Cubic
	static float CubicIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t + b;
	}
	
	static float CubicInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t + b;
		return c/2*((t-=2)*t*t + 2) + b;
	}
	
	static float CubicOut( float t, float b, float c, float d ) {
		return c*((t=t/d-1)*t*t + 1) + b;
	}
	
	//Elastic
	static float ElasticIn( float t, float b, float c, float d, float a, float p ) {
		float s;
		
		if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
		if (!a || a < fabsf(c)) { a=c; s = p/4; }
		else s = p/PI2 * asin (c/a);
		return -(a*pow(2,10*(t-=1)) * sin( (t*d-s)*PI2/p )) + b;
	}
	
	static float ElasticInOut( float t, float b, float c, float d, float a, float p ) {
		float s;
		if (t==0) return b;  if ((t/=d/2)==2) return b+c;  if (!p) p=d*(.3*1.5);
		if (!a || a < fabsf(c)) { a=c; s = p/4; }
		else s = p/PI2 * asin (c/a);
		if (t < 1) return -.5*(a*pow(2,10*(t-=1)) * sin( (t*d-s)*PI2/p )) + b;
		return a*pow(2,-10*(t-=1)) * sin( (t*d-s)*PI2/p )*.5 + c + b;
	}
	
	static float ElasticOut( float t, float b, float c, float d, float a, float p ) {
		float s;
		if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
		if (!a || a < fabsf(c)) { a=c; s = p/4; }
		else s = p/PI2 * asin (c/a);
		return (a*pow(2,-10*t) * sin( (t*d-s)*PI2/p ) + c + b);
	}
	
	// Expo
	static float ExpoIn( float t, float b, float c, float d ) {
		return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b - c * 0.001;
	}
	static float ExpoInOut( float t, float b, float c, float d ) {
		if (t==0) return b;
		if (t==d) return b+c;
		if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
		return c/2 * (-pow(2, -10 * --t) + 2) + b;
	}
	static float ExpoOut( float t, float b, float c, float d ) {
		return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
	}
	
	// Quad
	static float QuadIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t + b;
	}
	static float QuadInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t + b;
		return -c/2 * ((--t)*(t-2) - 1) + b;
	}
	static float QuadOut( float t, float b, float c, float d ) {
		return -c *(t/=d)*(t-2) + b;
	}
	
	// Quart
	static float QuartIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t*t + b;
	}
	static float QuartInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
		return -c/2 * ((t-=2)*t*t*t - 2) + b;
	}
	static float QuartOut( float t, float b, float c, float d ) {
		return -c * ((t=t/d-1)*t*t*t - 1) + b;
	}
	
	// Quint
	static float QuintIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t*t*t + b;
	}
	static float QuintInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
		return c/2*((t-=2)*t*t*t*t + 2) + b;
	}
	static float QuintOut( float t, float b, float c, float d ) {
		return c*((t=t/d-1)*t*t*t*t + 1) + b;
	}
	
	// Sine
	static float SineIn( float t, float b, float c, float d ) {
		return -c * cos(t/d * PI_HALF) + c + b;
	}
	static float SineInOut( float t, float b, float c, float d ) {
		return -c/2 * (cos(PI*t/d) - 1) + b;
	}
	static float SineOut( float t, float b, float c, float d ) {
		return c * sin(t/d * PI_HALF) + b;
	}
	
	// Strong
	static float StrongIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t*t*t + b;
	}
	static float StrongInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
		return c/2*((t-=2)*t*t*t*t + 2) + b;
	}
	static float StrongOut( float t, float b, float c, float d ) {
		return c*((t=t/d-1)*t*t*t*t + 1) + b;
	}
	
};
