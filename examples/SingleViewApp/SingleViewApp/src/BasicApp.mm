//
//  BasicApp.cpp
//  SingleViewApp
//
//  Created by Colin Duffy on 5/16/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#include "BasicApp.h"

void BasicApp::setup() {
	ApolloApp::setup();
	printf("basic app setup\n");
	
	v = [[[ApolloUIView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)] autorelease];
	[v setBackgroundColor:[UIColor redColor]];
	[parent.view addSubview:v];
	Tweener.addTween(v->matrix.x, 100, 1.5f, EaseExpoInOut, 1.5);
}

void BasicApp::exit() {
	v = NULL;
	ApolloApp::exit();
	parent = NULL;
}

void BasicApp::update() {
	Tweener.update();
	[v update];
}

void BasicApp::draw() {
	
}

void BasicApp::touchHandler(TouchEvent& key) {
	printf("TOUCH: %s\n", key.type.c_str());
}
