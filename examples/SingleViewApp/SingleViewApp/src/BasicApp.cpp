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
}

void BasicApp::exit() {
	ApolloApp::exit();
}

void BasicApp::update() {
}

void BasicApp::draw() {
	
}

void BasicApp::touchHandler(TouchEvent& key) {
	printf("TOUCH: %s\n", key.type.c_str());
}
