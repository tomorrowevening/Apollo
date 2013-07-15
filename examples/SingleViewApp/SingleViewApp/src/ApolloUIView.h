//
//  ApolloUIView.h
//  SingleViewApp
//
//  Created by Colin Duffy on 5/27/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once

#import <UIKit/UIKit.h>
#import "ApolloMath.h"

struct ViewMatrix {
private:
	
	float _rotation;
	
public:
	
	float	scaleX, scaleY, skewX, skewY,
			x, y, width, height;
	
	ViewMatrix() {
		_rotation = 0;
		scaleX = scaleY = 1; // (matrix: a & d)
		skewX  = skewY = 0;  // (matrix: b & c)
		x = y = 0; // (matrix: tx & ty)
		width  = height = 0;
	}
	
	void rotation(float rx) {
		_rotation = rx;
		const float rad = Apollo::toRad(rx);
		scaleX *= cosf(rad);
		scaleY *= sinf(rad);
		
		skewX *= -sinf(rad);
		skewY *= cosf(rad);
	}
	
	float rotation() { return _rotation; }
	
	const float scaledWidth()  { return scaleX * width;  }
	const float scaledHeight() { return scaleY * height; }
	
};

@interface ApolloUIView : UIView {
@public
	ViewMatrix matrix;
}

@property (nonatomic, readwrite) ViewMatrix matrix;

-(void)update;

@end
