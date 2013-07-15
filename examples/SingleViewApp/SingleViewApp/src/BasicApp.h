//
//  BasicApp.h
//  SingleViewApp
//
//  Created by Colin Duffy on 5/16/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "Apollo.h"
#include "ApolloUIView.h"

using namespace Apollo;

class BasicApp : public ApolloApp {
public:
	
	ApolloUIView* view;
	UIViewController* parent;
	BasicApp() {}
	virtual void setup();
	virtual void exit();
	virtual void update();
	virtual void draw();
	
	virtual void touchHandler(TouchEvent& key);
	
};
