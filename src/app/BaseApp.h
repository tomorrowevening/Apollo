//
//  BaseApp.h
//  Apollo
//  Created by Colin Duffy on 5/12/13.
//
//

#pragma once
#include "ApolloCore.h"
#include "ApolloEvent.h"

#ifdef OF_VERSION_MAJOR
#include "ofMain.h"
#include "OFDispatcher.h"
#endif

using namespace std;
using namespace Apollo;

class BaseApp {
public:
	
	virtual ~BaseApp(){}
	
	virtual void setup() {
#ifdef OF_VERSION_MAJOR
		OFDispatcher ofEventDispatcher;
		ofEventDispatcher.enable();
#endif
	}
	
	virtual void exit() {}
	virtual void update() {}
	virtual void draw() {}
	
	virtual void enable() {
		enableAppEvents();
#ifdef APOLLO_COCOA_TOUCH
		enableTouchEvents();
#else
		enableKeyEvents();
		enableMouseEvents();
#endif
	}
	
	virtual void enableAppEvents() {
		Dispatcher.addListener(AppEvent::UPDATE, this, baseEvtHandler);
		Dispatcher.addListener(AppEvent::DRAW, this, baseEvtHandler);
	}
	
	virtual void enableKeyEvents() {
		Dispatcher.addListener(KeyEvent::DOWN, this, baseEvtHandler);
		Dispatcher.addListener(KeyEvent::UP, this, baseEvtHandler);
	}
	
	virtual void enableMouseEvents() {
		Dispatcher.addListener(MouseEvent::PRESSED, this, baseEvtHandler);
		Dispatcher.addListener(MouseEvent::RELEASED, this, baseEvtHandler);
		Dispatcher.addListener(MouseEvent::MOVED, this, baseEvtHandler);
		Dispatcher.addListener(MouseEvent::DRAGGED, this, baseEvtHandler);
		Dispatcher.addListener(MouseEvent::SCROLLED, this, baseEvtHandler);
	}
	
	virtual void enableTouchEvents() {
		Dispatcher.addListener(TouchEvent::CANCEL, this, baseEvtHandler);
		Dispatcher.addListener(TouchEvent::DOUBLE_TAP, this, baseEvtHandler);
		Dispatcher.addListener(TouchEvent::DOWN, this, baseEvtHandler);
		Dispatcher.addListener(TouchEvent::MOVE, this, baseEvtHandler);
		Dispatcher.addListener(TouchEvent::UP, this, baseEvtHandler);
	}
	
	virtual void disable() {
		disableAppEvents();
#ifdef APOLLO_COCOA_TOUCH
		disableTouchEvents();
#else
		disableKeyEvents();
		disableMouseEvents();
#endif
	}
	
	virtual void disableAppEvents() {
		Dispatcher.removeListener(AppEvent::UPDATE, baseEvtHandler);
		Dispatcher.removeListener(AppEvent::DRAW, baseEvtHandler);
	}
	
	virtual void disableKeyEvents() {
		Dispatcher.removeListener(KeyEvent::DOWN, baseEvtHandler);
		Dispatcher.removeListener(KeyEvent::UP, baseEvtHandler);
	}
	
	virtual void disableMouseEvents() {
		Dispatcher.removeListener(MouseEvent::PRESSED, baseEvtHandler);
		Dispatcher.removeListener(MouseEvent::RELEASED, baseEvtHandler);
		Dispatcher.removeListener(MouseEvent::MOVED, baseEvtHandler);
		Dispatcher.removeListener(MouseEvent::DRAGGED, baseEvtHandler);
		Dispatcher.removeListener(MouseEvent::SCROLLED, baseEvtHandler);
	}
	
	virtual void disableTouchEvents() {
		Dispatcher.removeListener(TouchEvent::CANCEL, baseEvtHandler);
		Dispatcher.removeListener(TouchEvent::DOUBLE_TAP, baseEvtHandler);
		Dispatcher.removeListener(TouchEvent::DOWN, baseEvtHandler);
		Dispatcher.removeListener(TouchEvent::MOVE, baseEvtHandler);
		Dispatcher.removeListener(TouchEvent::UP, baseEvtHandler);
	}
	
	// Handler callbacks
	virtual void onMousePressed(MouseEvent& evt) {}
	virtual void onMouseReleased(MouseEvent& evt) {}
	virtual void onMouseMoved(MouseEvent& evt) {}
	virtual void onMouseDragged(MouseEvent& evt) {}
	virtual void onMouseScrolled(MouseEvent& evt) {}
	
	virtual void onKeyDown(KeyEvent& evt) {}
	virtual void onKeyUp(KeyEvent& evt) {}
	
	virtual void onTouchMove(TouchEvent& evt) {}
	virtual void onTouchDown(TouchEvent& evt) {}
	virtual void onTouchUp(TouchEvent& evt) {}
	virtual void onTouchDoubleTap(TouchEvent& evt) {}
	virtual void onTouchCancel(TouchEvent& evt) {}
	
	// Handlers
	
	
	// Getters
	static BaseApp& app() {
		static BaseApp instance;
		return instance;
	}
	const int getFrameNum() { return frameNum; }
	
	// Setters
	
private:
	
	int frameNum;
	
	BaseApp() {}
	BaseApp(BaseApp const&);
	void operator=(BaseApp const&);
	
	static void baseEvtHandler(Event& evt) {
		if(evt.type == AppEvent::UPDATE) {
			app().update();
			++app().frameNum;
		}
		else if(evt.type == AppEvent::DRAW)	app().draw();
		
		else if(evt.type == MouseEvent::DRAGGED)	app().onMouseDragged((MouseEvent&)evt);
		else if(evt.type == MouseEvent::MOVED)		app().onMouseMoved((MouseEvent&)evt);
		else if(evt.type == MouseEvent::PRESSED)	app().onMousePressed((MouseEvent&)evt);
		else if(evt.type == MouseEvent::RELEASED)	app().onMouseReleased((MouseEvent&)evt);
		else if(evt.type == MouseEvent::SCROLLED)	app().onMouseScrolled((MouseEvent&)evt);
		
		else if(evt.type == KeyEvent::DOWN)	app().onKeyDown((KeyEvent&)evt);
		else if(evt.type == KeyEvent::UP)	app().onKeyUp((KeyEvent&)evt);
		
		else if(evt.type == TouchEvent::CANCEL)		app().onTouchCancel((TouchEvent&)evt);
		else if(evt.type == TouchEvent::DOUBLE_TAP)	app().onTouchDoubleTap((TouchEvent&)evt);
		else if(evt.type == TouchEvent::DOWN)		app().onTouchDown((TouchEvent&)evt);
		else if(evt.type == TouchEvent::MOVE)		app().onTouchMove((TouchEvent&)evt);
		else if(evt.type == TouchEvent::UP)			app().onTouchUp((TouchEvent&)evt);
	}
	
};
