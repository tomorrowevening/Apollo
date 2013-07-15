//
//  ApolloUIView.m
//  SingleViewApp
//
//  Created by Colin Duffy on 5/27/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#import "ApolloUIView.h"

@implementation ApolloUIView
@synthesize matrix;

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
		matrix.x = frame.origin.x;
		matrix.y = frame.origin.y;
		matrix.width  = frame.size.width;
		matrix.height = frame.size.height;
        // Initialization code
    }
    return self;
}

-(void)update {
	CGAffineTransform mTransform;
	mTransform.a  = matrix.scaleX;
	mTransform.b  = matrix.skewX;
	mTransform.c  = matrix.skewY;
	mTransform.d  = matrix.scaleY;
	mTransform.tx = matrix.x;
	mTransform.ty = matrix.y;
	[self setTransform: mTransform];
}

@end
