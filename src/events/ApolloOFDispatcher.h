//
//  ApolloOFDispatcher.h
//  ApolloTests
//
//  Created by Colin Duffy on 5/13/13.
//
//

#pragma once
#include "ofMain.h"
#include "ApolloCore.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"

namespace Apollo {
	
	class ApolloOFDispatcher {
	public:
		
		ApolloOFDispatcher() {}
		~ApolloOFDispatcher(){ disable(); }
		
		virtual void enable() {
			enableAppEvents();
#ifdef APOLLO_COCOA_TOUCH
			enableTouchEvents();
#else
			enableKeyEvents();
			enableMouseEvents();
#endif
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
		
		virtual void enableAppEvents() {
			ofAddListener(ofEvents().update,	this, &ApolloOFDispatcher::updateHandler);
			ofAddListener(ofEvents().draw,		this, &ApolloOFDispatcher::drawHandler);
		}
		
		virtual void enableKeyEvents() {
			ofAddListener(ofEvents().keyPressed,	this, &ApolloOFDispatcher::keyDownHandler);
			ofAddListener(ofEvents().keyReleased,	this, &ApolloOFDispatcher::keyUpHandler);
		}
		
		virtual void enableMouseEvents() {
			ofAddListener(ofEvents().mouseDragged,		this, &ApolloOFDispatcher::mouseDraggedHandler);
			ofAddListener(ofEvents().mouseMoved,		this, &ApolloOFDispatcher::mouseMovedHandler);
			ofAddListener(ofEvents().mousePressed,		this, &ApolloOFDispatcher::mousePressedHandler);
			ofAddListener(ofEvents().mouseReleased,		this, &ApolloOFDispatcher::mouseReleasedHandler);
		}
		
		virtual void enableTouchEvents() {
			ofAddListener(ofEvents().touchCancelled,	this, &ApolloOFDispatcher::touchCancelHandler);
			ofAddListener(ofEvents().touchDoubleTap,	this, &ApolloOFDispatcher::touchDownHandler);
			ofAddListener(ofEvents().touchDown,			this, &ApolloOFDispatcher::touchDoubleTapHandler);
			ofAddListener(ofEvents().touchMoved,		this, &ApolloOFDispatcher::touchMovedHandler);
			ofAddListener(ofEvents().touchUp,			this, &ApolloOFDispatcher::touchUpHandler);
		}
		
		virtual void disableAppEvents() {
			ofRemoveListener(ofEvents().update,	this, &ApolloOFDispatcher::updateHandler);
			ofRemoveListener(ofEvents().draw,		this, &ApolloOFDispatcher::drawHandler);
		}
		
		virtual void disableKeyEvents() {
			ofRemoveListener(ofEvents().keyPressed,	this, &ApolloOFDispatcher::keyDownHandler);
			ofRemoveListener(ofEvents().keyReleased,	this, &ApolloOFDispatcher::keyUpHandler);
		}
		
		virtual void disableMouseEvents() {
			ofRemoveListener(ofEvents().mouseDragged,		this, &ApolloOFDispatcher::mouseDraggedHandler);
			ofRemoveListener(ofEvents().mouseMoved,		this, &ApolloOFDispatcher::mouseMovedHandler);
			ofRemoveListener(ofEvents().mousePressed,		this, &ApolloOFDispatcher::mousePressedHandler);
			ofRemoveListener(ofEvents().mouseReleased,		this, &ApolloOFDispatcher::mouseReleasedHandler);
		}
		
		virtual void disableTouchEvents() {
			ofRemoveListener(ofEvents().touchCancelled,	this, &ApolloOFDispatcher::touchCancelHandler);
			ofRemoveListener(ofEvents().touchDoubleTap,	this, &ApolloOFDispatcher::touchDownHandler);
			ofRemoveListener(ofEvents().touchDown,			this, &ApolloOFDispatcher::touchDoubleTapHandler);
			ofRemoveListener(ofEvents().touchMoved,		this, &ApolloOFDispatcher::touchMovedHandler);
			ofRemoveListener(ofEvents().touchUp,			this, &ApolloOFDispatcher::touchUpHandler);
		}
		
	protected:
		
		// Core events
		void updateHandler(ofEventArgs& args) {	Dispatcher.dispatchEvent(new AppEvent(AppEvent::UPDATE)); }
		void drawHandler(ofEventArgs& args) {	Dispatcher.dispatchEvent(new AppEvent(AppEvent::DRAW)); }
		
		// Key events
		void keyDownHandler(ofKeyEventArgs& args) {	Dispatcher.dispatchEvent(new KeyEvent(KeyEvent::DOWN, args.key)); }
		void keyUpHandler(ofKeyEventArgs& args) {	Dispatcher.dispatchEvent(new KeyEvent(KeyEvent::UP, args.key)); }
		
		// Mouse events
		void mouseDraggedHandler(ofMouseEventArgs& args) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::DRAGGED,	args.x, args.y, args.button)); }
		void mouseMovedHandler(ofMouseEventArgs& args) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::MOVED,		args.x, args.y, args.button)); }
		void mousePressedHandler(ofMouseEventArgs& args) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::PRESSED,	args.x, args.y, args.button)); }
		void mouseReleasedHandler(ofMouseEventArgs& args) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::RELEASED,	args.x, args.y, args.button)); }
		void mouseScrolledHandler(ofMouseEventArgs& args) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::SCROLLED,	args.x, args.y, args.button)); }
		
		// Touch events
		void touchCancelHandler(ofTouchEventArgs& args) {		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::CANCEL,		args.x, args.y, args.id, args.pressure)); }
		void touchDownHandler(ofTouchEventArgs& args) {			Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::DOWN,		args.x, args.y, args.id, args.pressure)); }
		void touchDoubleTapHandler(ofTouchEventArgs& args) {	Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::DOUBLE_TAP,	args.x, args.y, args.id, args.pressure)); }
		void touchMovedHandler(ofTouchEventArgs& args) {		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::MOVE,		args.x, args.y, args.id, args.pressure)); }
		void touchUpHandler(ofTouchEventArgs& args) {			Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::UP,			args.x, args.y, args.id, args.pressure)); }
		
	};
	
}
