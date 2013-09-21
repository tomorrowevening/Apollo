//
//  ApolloObjCRunner.h
//  Test
//
//  Created by Colin Duffy on 8/2/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#include "ApolloCore.h"

#ifdef APOLLO_COCOA

#import <Foundation/Foundation.h>

@interface ApolloObjCRunner : NSObject {
	NSTimer* timer;
}

-(void)start;
-(void)stop;
-(void)onUpdate;

@end

#endif
