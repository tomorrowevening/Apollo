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
//	CGAffineTransform mTransform;
//	mTransform.a  = matrix.a;
//	mTransform.b  = matrix.b;
//	mTransform.c  = matrix.c;
//	mTransform.d  = matrix.d;
//	mTransform.tx = matrix.tx;
//	mTransform.ty = matrix.ty;
//	self.transform = mTransform;
	[self setFrame: CGRectMake(matrix.x, matrix.y, matrix.width, matrix.height)];
}

@end
