//
//  ViewController.m
//  SingleViewApp
//
//  Created by Colin Duffy on 5/16/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#import "ViewController.h"
#import "Apollo.h"
#import "BasicApp.h"
#import "ApolloEventDispatcher.h"

@interface ViewController ()

@end

static BasicApp* MyApp;

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	
	MyApp = new BasicApp();
	MyApp->setup();
	
	// Do any additional setup after loading the view, typically from a nib.
}

-(void)dealloc {
	delete MyApp;
	[super dealloc];
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event {
	NSSet *allTouches = [event allTouches];
    for (UITouch *touch in allTouches) {
		CGPoint location = [touch locationInView: self.view];
		if(touch.tapCount == 1) {
			Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::DOWN, location.x, location.y, touch.hash));
		} else if(touch.tapCount == 2) {
			Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::DOUBLE_TAP, location.x, location.y, touch.hash));
		}
	}
}

-(void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event {
	NSSet *allTouches = [event allTouches];
    for (UITouch *touch in allTouches) {
		CGPoint location = [touch locationInView: self.view];
		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::CANCEL, location.x, location.y, touch.hash));
	}
}

-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event {
	NSSet *allTouches = [event allTouches];
    for (UITouch *touch in allTouches) {
		CGPoint location = [touch locationInView: self.view];
		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::UP, location.x, location.y, touch.hash));
	}
}

-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
	NSSet *allTouches = [event allTouches];
    for (UITouch *touch in allTouches) {
		CGPoint location = [touch locationInView: self.view];
		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::MOVE, location.x, location.y, touch.hash));
	}
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
