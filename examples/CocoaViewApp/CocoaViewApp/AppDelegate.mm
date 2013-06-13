//
//  AppDelegate.m
//  CocoaViewApp
//
//  Created by Colin Duffy on 5/27/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#import "AppDelegate.h"
#include "Apollo.h"

using namespace Apollo;

static ApolloApp* MyApp;

@implementation AppDelegate

-(id)init {
	self = [super init];
	if(self) {
		fps = 1.f / 60.f;
		MyApp = new ApolloApp();
		MyApp->setup();
	}
	return self;
}

- (void)dealloc {
	[self stopTimer];
    [super dealloc];
}

-(void)startTimer {
	timer = [NSTimer scheduledTimerWithTimeInterval: fps target: self selector: @selector(update:) userInfo: nil repeats: YES];
}

-(void)stopTimer {
	[timer invalidate];
	timer = nil;
}

-(void)update:(id)sender {
	Dispatcher.dispatchEvent(new AppEvent(AppEvent::UPDATE));
	Dispatcher.dispatchEvent(new AppEvent(AppEvent::DRAW));
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
	
}
- (void)applicationWillResignActive:(NSNotification *)notification {
	[self stopTimer];
	MyApp->disable();
}
- (void)applicationWillBecomeActive:(NSNotification *)notification {
	MyApp->enable();
	[self startTimer];
}
- (void)applicationWillTerminate:(NSNotification *)notification {}

@end
