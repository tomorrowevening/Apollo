//
//  Bezier.h
//
//	For retrieving keyframe eases from After Effects & Flash for custom tween easing
//	
//  Created by Colin Duffy on 3/22/13.
//
//

#pragma once
#include "Vec.h"

class Cubic {
public:
	
	vec2f c0, c1, c2, c3;
	
	void reset() {
		c0.set(0, 0);
		c1.set(0, 0);
		c2.set(0, 0);
		c3.set(0, 0);
	}
	
	void setCoef(int index, float cx, float cy) {
		switch(index) {
			case 0:
				c0.set(cx, cy);
				break;
				
			case 1:
				c1.set(cx, cy);
				break;
				
			case 2:
				c2.set(cx, cy);
				break;
				
			case 3:
				c3.set(cx, cy);
				break;
		}
	}
	
	vec2f getCoef(int index) {
		if(index == 0) return c0;
		if(index == 1) return c1;
		if(index == 2) return c2;
		return c3;
	}
	
	float getX(float percent) {
		return c0.x + percent * (c1.x + percent * (c2.x + percent * c3.x));
	}
	
	float getY(float percent) {
		return c0.y + percent * (c1.y + percent * (c2.y + percent * c3.y));
	}
};

class Bezier {
private:
	
	vec2f c0, c1, c2, c3;
	bool invalidate;
	
	void compute() {
		coef.reset();
		
		coef.setCoef(0, c0.x, c0.y);
		
		vec2f a = (c1 - c0) * 3.f;
		coef.setCoef(1, a.x, a.y);
		
		vec2f b = (c2 - c1) * 3.f - a;
		coef.setCoef(2, b.x, b.y);
		
		vec2f c = c3 - c0 - a - b;
		coef.setCoef(3, c.x, c.y);
		
		invalidate = false;
	}
	
	float root(float t, float percent) {
		return t * (coef.c1.x + t * (coef.c2.x + t * coef.c3.x)) + coef.c0.x - percent;
	}
	
	float findRoot(float _x0, float _x2, float percent) {
		const float eps = 0.0000001f;
		
		float x0 = 0;
		float x1 = 0;
		float x2 = 0;
		float y0 = 0;
		float y1 = 0;
		float y2 = 0;
		float b = 0;
		float c = 0;
		float y10 = 0;
		float y20 = 0;
		float y21 = 0;
		float xm = 0;
		float ym = 0;
		float temp = 0;
		
		float xmlast = _x0;
		y0         = root(_x0, percent);
		
		if(y0 == 0.0) {
			return _x0;
		}
		
		y2 = root(_x2, percent);
		if(y2 == 0.0) {
			return _x2;
		}
		
		if(y2*y0 > 0.0) {
			return _x0;
		}
		
		x0     = _x0;
		x2     = _x2;
		for(int i = 0; i < 50; ++i) {
			
			x1 = 0.5 * (x2 + x0);
			y1 = root(x1, percent);
			if(y1 == 0.0) return x1;
			
			if(abs(x1 - x0) < eps) {
				return x1;
			}
			
			if(y1*y0 > 0.0) {
				temp = x0;
				x0   = x2;
				x2   = temp;
				temp = y0;
				y0   = y2;
				y2   = temp;
			}
			
			y10 = y1 - y0;
			y21 = y2 - y1;
			y20 = y2 - y0;
			
			if(y2 * y20 < 2.0 * y1 * y10) {
				x2 = x1;
				y2 = y1;
			} else {
				
				b  = (x1  - x0 ) / y10;
				c  = (y10 - y21) / (y21 * y20);
				xm = x0 - b*y0*(1.0 - c*y1);
				ym = root(xm, percent);
				
				if( ym == 0.0 ) return xm;
				
				if( abs(xm - xmlast) < eps ) return xm;
				
				xmlast = xm;
				if( ym*y0 < 0.0 ) {
					x2 = xm;
					y2 = ym;
				} else {
					x0 = xm;
					y0 = ym;
					x2 = x1;
					y2 = y1;
				}
			}
		}
		return x1;
	}
	
	float getX(float percent) {
		if(invalidate) compute();
		return coef.getX(percent);
	}
	
	float getY(float percent) {
		if(invalidate) compute();
		return coef.getY(percent);
	}
	
public:
	
	Cubic coef;
	
	Bezier() { reset(); }
	
	void reset() {
		c0 = vec2f(0.000f, 0.000f);
		c1 = vec2f(0.333f, 0.333f);
		c2 = vec2f(0.667f, 0.667f);
		c3 = vec2f(1.000f, 1.000f);
		invalidate = true;
	}
	
	void setControl(int index, float x, float y) {
		switch(index) {
			case 0:
				c0.set(x, y);
				break;
			case 1:
				c1.set(x, y);
				break;
			case 2:
				c2.set(x, y);
				break;
			case 3:
				c3.set(x, y);
				break;
		}
		
		invalidate = true;
	}
	
	float getValue(float percent) {
		if(invalidate) compute();
		
		// Find one root - any root - then factor out (t-r) to get a quadratic poly. for the remaining roots
		return getY( findRoot(0, 1, percent) );
	}
	
};
