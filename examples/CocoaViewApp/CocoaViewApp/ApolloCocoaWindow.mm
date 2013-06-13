//
//  NSWindow+ApolloCocoaWindow.m
//  CocoaViewApp
//
//  Created by Colin Duffy on 5/27/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#import "ApolloCocoaWindow.h"
#include "Apollo.h"

@implementation ApolloCocoaWindow

using namespace Apollo;

- (void)keyDown:(NSEvent *)event {
	Dispatcher.dispatchEvent(new KeyEvent(KeyEvent::DOWN, [event keyCode]));
}

@end
