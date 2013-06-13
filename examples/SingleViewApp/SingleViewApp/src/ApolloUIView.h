//
//  ApolloUIView.h
//  SingleViewApp
//
//  Created by Colin Duffy on 5/27/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once

#import <UIKit/UIKit.h>
//#include "Apollo.h"

struct ApolloMatrix {
	float x, y, width, height;
	float a, b, c, d, tx, ty;
	ApolloMatrix() {
		x = y = width = height = 0;
		a = d = 1;
		b = c = tx = ty = 0;
	}
};

@interface ApolloUIView : UIView {
@public
	ApolloMatrix matrix;
}

@property (nonatomic, readwrite) ApolloMatrix matrix;

-(void)update;

@end
