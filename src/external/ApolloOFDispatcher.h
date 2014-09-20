//
//  ApolloOFDispatcher.h
//  Apollo
//
//  Created by Colin Duffy on 8/12/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ofMain.h"
#include "ApolloCore.h"
#include "ApolloEvent.h"
#include "ApolloEventDispatcher.h"

namespace Apollo {
	
	class OFDispatcher {
	public:
		
		OFDispatcher() {
			enable();
		}
		
		~OFDispatcher() {
			disable();
		}
		
		void enable();
		void disable();
		
		// Handlers
		void evtUpdateHandler(ofEventArgs& evt) {				Dispatcher.dispatchEvent(new Event(Event::UPDATE)); }
		void evtDrawHandler(ofEventArgs& evt) {					Dispatcher.dispatchEvent(new Event(Event::DRAW)); }
		
		void evtKeyDownHandler(ofKeyEventArgs& evt) {			Dispatcher.dispatchEvent(new KeyEvent(KeyEvent::DOWN, evt.key)); }
		void evtKeyUpHandler(ofKeyEventArgs& evt) {				Dispatcher.dispatchEvent(new KeyEvent(KeyEvent::UP, evt.key)); }
		
		void evtMouseDraggedHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::DRAGGED, evt.x, evt.y, evt.button)); }
		void evtMouseMovedHandler(ofMouseEventArgs& evt) {		Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::MOVE, evt.x, evt.y, evt.button)); }
		void evtMousePressedHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::DOWN, evt.x, evt.y, evt.button)); }
		void evtMouseReleasedHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::UP, evt.x, evt.y, evt.button)); }
		void evtMouseScrolledHandler(ofMouseEventArgs& evt) {	Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::SCROLLED, evt.x, evt.y, evt.button)); }
		
		void evtTouchCancelHandler(ofTouchEventArgs& evt) {}
		void evtTouchDoubleTapHandler(ofTouchEventArgs& evt) {	Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::DOUBLE_TAP, evt.x, evt.y, evt.id, evt.pressure)); }
		void evtTouchDownHandler(ofTouchEventArgs& evt) {		Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::DOWN, evt.x, evt.y, evt.id, evt.pressure)); }
		void evtTouchMoveHandler(ofTouchEventArgs& evt) {		Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::MOVE, evt.x, evt.y, evt.id, evt.pressure)); }
		void evtTouchUpHandler(ofTouchEventArgs& evt) {			Dispatcher.dispatchEvent(new ActionEvent(ActionEvent::UP, evt.x, evt.y, evt.id, evt.pressure)); }
		
	};
	
}
