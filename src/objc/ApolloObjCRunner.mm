//
//  ApolloObjCRunner.m
//  Test
//
//  Created by Colin Duffy on 8/2/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#import "ApolloObjCRunner.h"
#include "Apollo.h"

@implementation ApolloObjCRunner

-(void)dealloc {
	[self stop];
	[super dealloc];
}

-(void)start {
	timer = [NSTimer scheduledTimerWithTimeInterval: 1.f / 60.f target: self selector: @selector(onUpdate) userInfo: nil repeats: YES];
}

-(void)stop {
	[timer invalidate];
	timer = nil;
}

-(void)onUpdate {
	Dispatcher.dispatchEvent(new AppEvent(AppEvent::UPDATE));
	Dispatcher.dispatchEvent(new AppEvent(AppEvent::DRAW));
}

@end
