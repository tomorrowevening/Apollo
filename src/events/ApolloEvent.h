//
//  Event.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"

namespace Apollo {
	
	class EventDispatcher;
	class Event{
		friend EventDispatcher;
	public:
		
		Event(){}
		Event(string type){ this->type = type; }
		Event(string type, void* params = NULL):type(type), params(params) {}
		virtual ~Event(){ params = NULL; }
		bool hasParams() { return params != NULL; }
		
		string type;
		void* params;
		
	private:
		void *target, *listener;
	};
	
	//////////////////////////////////////////////////
	// Key Event
	//////////////////////////////////////////////////
	
	class AppEvent : public Event {
	public:
		static string INIT;
		static string UPDATE;
		static string DRAW;
		static string RESIZE;
		AppEvent(){}
		AppEvent(string type){ this->type = type; }
		AppEvent(string type, void* params){ this->type = type; this->params = params; }
	};
	
	//////////////////////////////////////////////////
	// Key Event
	//////////////////////////////////////////////////
	
	class KeyEvent : public Event {
	public:
		static string DOWN;
		static string UP;
		int key;
		
		KeyEvent(string type, int key, void* params = NULL) {
			this->type = type;
			this->key = key;
			this->params = params;
		}
	};
	
	//////////////////////////////////////////////////
	// Mouse Event
	//////////////////////////////////////////////////
	
	class MouseEvent : public Event {
	public:
		static string DRAGGED;
		static string MOVED;
		static string PRESSED;
		static string RELEASED;
		static string SCROLLED;
		
		MouseEvent(string type, int x, int y, int index = 0, void* params = NULL) {
			this->type = type;
			this->x = x;
			this->y = y;
			this->index = index;
			this->params = params;
		}
		
		int x, y, index;
	};
	
	//////////////////////////////////////////////////
	// Touch Event
	//////////////////////////////////////////////////
	
	class TouchEvent : public Event {
	public:
		static string MOVE;
		static string DOWN;
		static string UP;
		static string DOUBLE_TAP;
		static string CANCEL;
		
		TouchEvent(string type, int x, int y, int index = 0, float pressure = 0, void* params = NULL) {
			this->type = type;
			this->x = x;
			this->y = y;
			this->index = index;
			this->pressure = pressure;
			this->params = params;
		}
		
		int x, y, index;
		float pressure;
	};
	
	typedef void (*listenerHandler)(Event&);
}
