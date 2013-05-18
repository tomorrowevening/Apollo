//
//  ApolloOFDispatcher.h
//  ApolloTests
//
//  Created by Colin Duffy on 5/13/13.
//
//

#pragma once
#ifdef OF_VERSION_MAJOR
#include "ofMain.h"
#include "ApolloCore.h"
#include "ApolloEvent.h"

namespace Apollo {
	
	class OFDispatcher {
	public:
		
		~OFDispatcher() { disable(); }
		
		void enable() {
			ofAddListener(ofEvents().update, this, &OFDispatcher::evtUpdateHandler);
			ofAddListener(ofEvents().draw, this, &OFDispatcher::evtDrawHandler);
			
#ifdef APOLLO_COCOA_TOUCH
			ofAddListener(ofEvents().touchCancelled, this, &OFDispatcher::evtTouchCancelHandler);
			ofAddListener(ofEvents().touchDoubleTap, this, &OFDispatcher::evtTouchDoubleTapHandler);
			ofAddListener(ofEvents().touchDown, this, &OFDispatcher::evtTouchDownHandler);
			ofAddListener(ofEvents().touchMoved, this, &OFDispatcher::evtTouchMoveHandler);
			ofAddListener(ofEvents().touchUp, this, &OFDispatcher::evtTouchUpHandler);
#else
			ofAddListener(ofEvents().keyPressed, this, &OFDispatcher::evtKeyDownHandler);
			ofAddListener(ofEvents().keyReleased, this, &OFDispatcher::evtKeyUpHandler);
			
			ofAddListener(ofEvents().mouseDragged, this, &OFDispatcher::evtMouseDraggedHandler);
			ofAddListener(ofEvents().mouseMoved, this, &OFDispatcher::evtMouseMovedHandler);
			ofAddListener(ofEvents().mousePressed, this, &OFDispatcher::evtMousePressedHandler);
			ofAddListener(ofEvents().mouseReleased, this, &OFDispatcher::evtMouseReleasedHandler);
#endif
		}
		
		void disable() {
			ofRemoveListener(ofEvents().update, this, &OFDispatcher::evtUpdateHandler);
			ofRemoveListener(ofEvents().draw, this, &OFDispatcher::evtDrawHandler);
			
#ifdef APOLLO_COCOA_TOUCH
			ofRemoveListener(ofEvents().touchCancelled, this, &OFDispatcher::evtTouchCancelHandler);
			ofRemoveListener(ofEvents().touchDoubleTap, this, &OFDispatcher::evtTouchDoubleTapHandler);
			ofRemoveListener(ofEvents().touchDown, this, &OFDispatcher::evtTouchDownHandler);
			ofRemoveListener(ofEvents().touchMoved, this, &OFDispatcher::evtTouchMoveHandler);
			ofRemoveListener(ofEvents().touchUp, this, &OFDispatcher::evtTouchUpHandler);
#else
			ofRemoveListener(ofEvents().keyPressed, this, &OFDispatcher::evtKeyDownHandler);
			ofRemoveListener(ofEvents().keyReleased, this, &OFDispatcher::evtKeyUpHandler);
			
			ofRemoveListener(ofEvents().mouseDragged, this, &OFDispatcher::evtMouseDraggedHandler);
			ofRemoveListener(ofEvents().mouseMoved, this, &OFDispatcher::evtMouseMovedHandler);
			ofRemoveListener(ofEvents().mousePressed, this, &OFDispatcher::evtMousePressedHandler);
			ofRemoveListener(ofEvents().mouseReleased, this, &OFDispatcher::evtMouseReleasedHandler);
#endif
		}
		
		// Handlers
		void evtUpdateHandler(ofEventArgs& evt) {	Dispatcher.dispatchEvent(new AppEvent(AppEvent::UPDATE)); }
		void evtDrawHandler(ofEventArgs& evt) {		Dispatcher.dispatchEvent(new AppEvent(AppEvent::DRAW)); }
		
		void evtKeyDownHandler(ofKeyEventArgs& evt) {	Dispatcher.dispatchEvent(new KeyEvent(KeyEvent::DOWN, evt.key)); }
		void evtKeyUpHandler(ofKeyEventArgs& evt) {		Dispatcher.dispatchEvent(new KeyEvent(KeyEvent::UP, evt.key)); }
		
		void evtMouseDraggedHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::DRAGGED, evt.x, evt.y, evt.button)); }
		void evtMouseMovedHandler(ofMouseEventArgs& evt) {		Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::MOVED, evt.x, evt.y, evt.button)); }
		void evtMousePressedHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::PRESSED, evt.x, evt.y, evt.button)); }
		void evtMouseReleasedHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::RELEASED, evt.x, evt.y, evt.button)); }
		void evtMouseScrolledHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new MouseEvent(MouseEvent::SCROLLED, evt.x, evt.y, evt.button)); }
		
		void evtTouchCancelHandler(ofTouchEventArgs& evt) {		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::CANCEL, evt.x, evt.y, evt.id, evt.pressure)); }
		void evtTouchDoubleTapHandler(ofTouchEventArgs& evt) {	Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::DOUBLE_TAP, evt.x, evt.y, evt.id, evt.pressure)); }
		void evtTouchDownHandler(ofTouchEventArgs& evt) {		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::DOWN, evt.x, evt.y, evt.id, evt.pressure)); }
		void evtTouchMoveHandler(ofTouchEventArgs& evt) {		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::MOVE, evt.x, evt.y, evt.id, evt.pressure)); }
		void evtTouchUpHandler(ofTouchEventArgs& evt) {			Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::UP, evt.x, evt.y, evt.id, evt.pressure)); }
	};
	
}

#endif