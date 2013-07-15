//
//  BasicApp.cpp
//  SingleViewApp
//
//  Created by Colin Duffy on 5/16/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#include "BasicApp.h"
#include "Config.h"

void BasicApp::setup() {
	ApolloApp::setup();
	printf("basic app setup\n");
	
	view = [[[ApolloUIView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)] autorelease];
	[view setBackgroundColor:[UIColor redColor]];
	[parent.view addSubview: view];
	
#ifdef EXAMPLE_CPP_TO_OBJC
	printf("Tweener call from C++ ApolloApp::BasicApp\n");
	Tweener.addTween( view->matrix.x, 100, 1.5f, EaseQuartInOut, 1.5 );
	Tweener.addTween( view->matrix.y, 100, 1.5f, EaseQuartInOut, 2.5 );
#endif
}

void BasicApp::exit() {
	view = NULL;
	ApolloApp::exit();
	parent = NULL;
}

void BasicApp::update() {
	Tweener.update();
	[view update];
}

void BasicApp::draw() {
	
}

void BasicApp::touchHandler(TouchEvent& key) {
	printf("TOUCH: %s\n", key.type.c_str());
}
