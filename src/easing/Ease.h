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

class Back {
public:
	
	static float easeIn( float t, float b, float c, float d, float s = 1.70158 ) {
		return c*(t/=d)*t*((s+1)*t - s) + b;
	}
	
	static float easeInOut( float t, float b, float c, float d, float s = 1.70158 ) {
		if ((t/=d/2) < 1) return c/2*(t*t*(((s*=(1.525))+1)*t - s)) + b;
		return c/2*((t-=2)*t*(((s*=(1.525))+1)*t + s) + 2) + b;
	}
	
	static float easeOut( float t, float b, float c, float d, float s = 1.70158 ) {
		return c*((t=t/d-1)*t*((s+1)*t + s) + 1) + b;
	}
	
};

#pragma mark - Bounce -

class Bounce {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return c - easeOut(d-t, 0, c, d) + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if (t < d/2) return easeIn (t*2, 0, c, d) * .5 + b;
		else return easeOut (t*2-d, 0, c, d) * .5 + c*.5 + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
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
	
};

#pragma mark - Circ -

class Circ {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return -c * (sqrt(1 - (t/=d)*t) - 1) + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return -c/2 * (sqrt(1 - t*t) - 1) + b;
		return c/2 * (sqrt(1 - (t-=2)*t) + 1) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return c * sqrt(1 - (t=t/d-1)*t) + b;
	}
	
};

#pragma mark - Cubic -

class Cubic {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t + b;
		return c/2*((t-=2)*t*t + 2) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return c*((t=t/d-1)*t*t + 1) + b;
	}
	
};

#pragma mark - Elastic -

class Elastic {
public:
	
	static float easeIn( float t, float b, float c, float d, float a, float p ) {
		float s;
		
		if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
		if (!a || a < fabsf(c)) { a=c; s = p/4; }
		else s = p/PI2 * asin (c/a);
		return -(a*pow(2,10*(t-=1)) * sin( (t*d-s)*PI2/p )) + b;
	}
	
	static float easeInOut( float t, float b, float c, float d, float a, float p ) {
		float s;
		if (t==0) return b;  if ((t/=d/2)==2) return b+c;  if (!p) p=d*(.3*1.5);
		if (!a || a < fabsf(c)) { a=c; s = p/4; }
		else s = p/PI2 * asin (c/a);
		if (t < 1) return -.5*(a*pow(2,10*(t-=1)) * sin( (t*d-s)*PI2/p )) + b;
		return a*pow(2,-10*(t-=1)) * sin( (t*d-s)*PI2/p )*.5 + c + b;
	}
	
	static float easeOut( float t, float b, float c, float d, float a, float p ) {
		float s;
		if (t==0) return b;  if ((t/=d)==1) return b+c;  if (!p) p=d*.3;
		if (!a || a < fabsf(c)) { a=c; s = p/4; }
		else s = p/PI2 * asin (c/a);
		return (a*pow(2,-10*t) * sin( (t*d-s)*PI2/p ) + c + b);
	}
	
};

#pragma mark - Expo -

class Expo {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b - c * 0.001;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if (t==0) return b;
		if (t==d) return b+c;
		if ((t/=d/2) < 1) return c/2 * pow(2, 10 * (t - 1)) + b;
		return c/2 * (-pow(2, -10 * --t) + 2) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
	}
	
};

#pragma mark - Linear -

class Linear {
public:
	
	static float easeNone( float t, float b, float c, float d ) {
		return c*t/d + b;
	}
	
	static float easeIn( float t, float b, float c, float d ) {
		return Linear::easeNone(t, b, c, d);
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		return Linear::easeNone(t, b, c, d);
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return Linear::easeNone(t, b, c, d);
	}
	
};

#pragma mark - Quad -

class Quad {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t + b;
		return -c/2 * ((--t)*(t-2) - 1) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return -c *(t/=d)*(t-2) + b;
	}
	
};

#pragma mark - Quart -

class Quart {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t*t + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t + b;
		return -c/2 * ((t-=2)*t*t*t - 2) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return -c * ((t=t/d-1)*t*t*t - 1) + b;
	}
	
};

#pragma mark - Quint -

class Quint {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t*t*t + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
		return c/2*((t-=2)*t*t*t*t + 2) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return c*((t=t/d-1)*t*t*t*t + 1) + b;
	}
	
};

#pragma mark - Sine -

class Sine {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return -c * cos(t/d * PI_HALF) + c + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		return -c/2 * (cos(PI*t/d) - 1) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return c * sin(t/d * PI_HALF) + b;
	}
	
};

#pragma mark - Strong -

class Strong {
public:
	
	static float easeIn( float t, float b, float c, float d ) {
		return c*(t/=d)*t*t*t*t + b;
	}
	
	static float easeInOut( float t, float b, float c, float d ) {
		if ((t/=d/2) < 1) return c/2*t*t*t*t*t + b;
		return c/2*((t-=2)*t*t*t*t + 2) + b;
	}
	
	static float easeOut( float t, float b, float c, float d ) {
		return c*((t=t/d-1)*t*t*t*t + 1) + b;
	}
	
};

