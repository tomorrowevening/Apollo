//
//  Event.h
//  OFBoxShapes
//
//  Created by Colin Duffy on 4/25/13.
//
//

#pragma once
#include "Apollo.h"
#include <tr1/functional>

//namespace Apollo {

	using namespace std;
	
	class EventArgs {};
	
	//////////////////////////////////////////////////
	// Events
	//////////////////////////////////////////////////
	
	class Event {
	public:
		string type;
		EventArgs* args;
		const bool bubbles;
		const bool cancelable;
		
		Event(const string &type, bool bubbles = false, bool cancelable = false) : type(type), bubbles(bubbles), cancelable(cancelable) {}
		~Event() { args = NULL; }
		
		bool hasArgs() { return args != NULL; }
	};
	
	typedef std::tr1::function<void(const Event&)> Callback;
	
	class EventCallback {
	public:
		Callback callback;
		void call(const Event& evt) { callback(evt); }
		
		template <class T>
		void setCallback(T* listener, void (T::*handler)(const Event&)) {
			callback = std::tr1::bind(handler, listener);
		}
	};
	
	//////////////////////////////////////////////////
	// Event dispatcher
	//////////////////////////////////////////////////
	
	class EventDispatcher {
	private:
		std::map<const std::string, std::map<int, std::list<Callback > > > eventHandlers;
	public:
		
		// "void EventDispatcher::addListener<HelloWorld>(std::string const&, HelloWorld*, void (HelloWorld::*)(Event const&), bool, int, bool)"
		
		bool hasListener(const std::string type);
		void dispatchEvent(const Event& evt);
		
		template <class T>
		void test(T* listener, void (T::*handler)(const int& d)) {
			printf("Test!\n");
		}
		
		template <class T>
		void addListener(const std::string &type, T* listener, void (T::*handler)(const Event&), bool useCapture = false, int priority = 0, bool useWeakReference = false);
		
		template <class T>
		void removeListener(const std::string &type, T* listener, void (T::*handler)(const Event&));
		
	};
	
//	extern EventDispatcher Dispatcher;

	//////////////////////////////////////////////////
	// Common event types
	//////////////////////////////////////////////////
	
	class KeyEvent : public Event {
	public:
		int key;
		const static std::string DOWN;
		const static std::string UP;
	};
	
	class MouseEvent : public Event {
	public:
		int button;
		float x, y;
		
		const static std::string OVER;
		const static std::string OUT;
		const static std::string CLICK;
		const static std::string PRESSED;
		const static std::string RELEASED;
		const static std::string RELEASED_OUTSIDE;
		const static std::string SCROLL;
	};
	
	class TouchEvent : public Event {
	public:
		int id;
		float x, y;
		
		const static std::string DOWN;
		const static std::string UP;
		const static std::string MOVE;
		const static std::string DOUBLE_TAP;
		const static std::string CANCEL;
	};
//}
