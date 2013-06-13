//
//  ApolloApp.cpp
//  SushiHero
//
//  Created by colin.duffy on 5/15/13.
//  Copyright (c) 2013 Design Symphony, LLC. All rights reserved.
//

#include "ApolloApp.h"

namespace Apollo {
	
	ApolloApp::ApolloApp() {}

	void ApolloApp::setup() {
		enable();
	}
	
	void ApolloApp::exit() {
		disable();
	}
	
	void ApolloApp::update() {
		
	}
	
	void ApolloApp::draw() {
		
	}
	
	void ApolloApp::enable() {
		enableEvents();
	}
	
	void ApolloApp::disable() {
		disableEvents();
	}
	
	void ApolloApp::enableEvents() {
		Dispatcher.addListener(AppEvent::UPDATE, this, appHandlers);
		Dispatcher.addListener(AppEvent::DRAW, this, appHandlers);
#ifdef APOLLO_COCOA_TOUCH
		Dispatcher.addListener(TouchEvent::CANCEL, this, appHandlers);
		Dispatcher.addListener(TouchEvent::DOUBLE_TAP, this, appHandlers);
		Dispatcher.addListener(TouchEvent::DOWN, this, appHandlers);
		Dispatcher.addListener(TouchEvent::MOVE, this, appHandlers);
		Dispatcher.addListener(TouchEvent::UP, this, appHandlers);
#else
		Dispatcher.addListener(KeyEvent::DOWN, this, appHandlers);
		Dispatcher.addListener(KeyEvent::UP, this, appHandlers);
		Dispatcher.addListener(MouseEvent::DRAGGED, this, appHandlers);
		Dispatcher.addListener(MouseEvent::MOVED, this, appHandlers);
		Dispatcher.addListener(MouseEvent::PRESSED, this, appHandlers);
		Dispatcher.addListener(MouseEvent::RELEASED, this, appHandlers);
		Dispatcher.addListener(MouseEvent::SCROLLED, this, appHandlers);
#endif
	}
	
	void ApolloApp::disableEvents() {
		Dispatcher.removeListener(AppEvent::UPDATE, this, appHandlers);
		Dispatcher.removeListener(AppEvent::DRAW, this, appHandlers);
#ifdef APOLLO_COCOA_TOUCH
		Dispatcher.removeListener(TouchEvent::CANCEL, this, appHandlers);
		Dispatcher.removeListener(TouchEvent::DOUBLE_TAP, this, appHandlers);
		Dispatcher.removeListener(TouchEvent::DOWN, this, appHandlers);
		Dispatcher.removeListener(TouchEvent::MOVE, this, appHandlers);
		Dispatcher.removeListener(TouchEvent::UP, this, appHandlers);
#else
		Dispatcher.removeListener(KeyEvent::DOWN, this, appHandlers);
		Dispatcher.removeListener(KeyEvent::UP, this, appHandlers);
		Dispatcher.removeListener(MouseEvent::DRAGGED, this, appHandlers);
		Dispatcher.removeListener(MouseEvent::MOVED, this, appHandlers);
		Dispatcher.removeListener(MouseEvent::PRESSED, this, appHandlers);
		Dispatcher.removeListener(MouseEvent::RELEASED, this, appHandlers);
		Dispatcher.removeListener(MouseEvent::SCROLLED, this, appHandlers);
#endif
	}
	
	void ApolloApp::appHandlers(Event& evt) {
		ApolloApp* app = (ApolloApp*)evt.listener;
		
		// Core
		if(evt.type == AppEvent::UPDATE) app->update();
		else if(evt.type == AppEvent::DRAW) app->draw();
		
#ifdef APOLLO_COCOA_TOUCH
		// Touch
		else if(evt.type == TouchEvent::CANCEL) app->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::DOUBLE_TAP) app->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::DOWN) app->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::MOVE) app->touchHandler( (TouchEvent&)evt );
		else if(evt.type == TouchEvent::UP) app->touchHandler( (TouchEvent&)evt );
#else
		// Key
		else if(evt.type == KeyEvent::DOWN) app->keyHandler( (KeyEvent&)evt );
		else if(evt.type == KeyEvent::UP) app->keyHandler( (KeyEvent&)evt );
		
		// Mouse
		else if(evt.type == MouseEvent::DRAGGED) app->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::MOVED) app->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::PRESSED) app->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::RELEASED) app->mouseHandler( (MouseEvent&)evt );
		else if(evt.type == MouseEvent::SCROLLED) app->mouseHandler( (MouseEvent&)evt );
#endif
	}
	
}