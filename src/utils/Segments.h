//
//  Segments.h
//  Apollo
//
//  Created by Colin Duffy on 1/18/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#include "Vec.h"

class Segments {
public:
	
	/**
	 * Plots points between 2 numbers.
	 */
	static float* plot( float start, float end, int segments ) {
		float* pts = new float[segments];
		float dividend = (end - start) / ((float)segments-1.0f);
		for( int i = 0; i < segments; ++i )
			pts[i] = (float)i * dividend + start;
		return pts;
	}
	
	/**
	 * Plots points between 2 2D vectors.
	 */
	static vec2f* plot2D( float x1, float y1, float x2, float y2, int segments ) {
		vec2f* pts = new vec2f[segments];
		float totalOffset = (float)segments-1.0f;
		vec2f dividend;
		dividend.x = (x2 - x1) / totalOffset;
		dividend.y = (y2 - y1) / totalOffset;
		for( int i = 0; i < segments; ++i ) {
			pts[i].x = (float)i * dividend.x + x1;
			pts[i].y = (float)i * dividend.y + y1;
		}
		return pts;
	}
	
	/**
	 * Plots points between 2 2D vectors.
	 */
	static vec2f* plot2D( vec2f start, vec2f end, int segments ) {
		return plot2D( start.x, start.y, end.x, end.y, segments );
	}
	
	/**
	 * Plots points between 2 3D vectors.
	 */
	static vec3f* plot3D( float x1, float y1, float z1, float x2, float y2, float z2, int segments ) {
		vec3f* pts = new vec3f[segments];
		float totalOffset = (float)segments-1.0f;
		vec3f dividend;
		dividend.x = (x2 - x1) / totalOffset;
		dividend.y = (y2 - y1) / totalOffset;
		dividend.z = (z2 - z1) / totalOffset;
		for( int i = 0; i < segments; ++i ) {
			pts[i].x = (float)i * dividend.x + x1;
			pts[i].y = (float)i * dividend.y + y1;
			pts[i].z = (float)i * dividend.z + z1;
		}
		return pts;
	}
	
	/**
	 * Plots points between 2 3D vectors.
	 */
	static vec3f* plot3D( vec3f start, vec3f end, int segments ) {
		return plot3D( start.x, start.y, start.z, end.x, end.y, end.z, segments );
	}
};
