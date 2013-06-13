//
//  AppDelegate.h
//  CocoaViewApp
//
//  Created by Colin Duffy on 5/27/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ApolloCocoaWindow.h"

@interface AppDelegate : NSObject <NSApplicationDelegate> {
	NSTimer* timer;
	NSTimeInterval fps;
}

@property (assign) IBOutlet ApolloCocoaWindow *window;

-(void)startTimer;
-(void)stopTimer;
-(void)update:(id)sender;

- (void)applicationWillResignActive:(NSNotification *)notification;
- (void)applicationWillBecomeActive:(NSNotification *)notification;
- (void)applicationWillTerminate:(NSNotification *)notification;

@end
