//
//  ViewController.h
//  SingleViewApp
//
//  Created by Colin Duffy on 5/16/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController {
	NSTimeInterval startDate;
	NSTimer* timer;
}

-(void)startTimer;
-(void)stopTimer;
-(void)update;

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event;
-(void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event;

@end
