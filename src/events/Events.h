//
//  Event.h
//  Apollo
//  Created by Colin Duffy on 4/25/13.
//

#pragma once
#include "Apollo.h"

namespace Apollo {

	using namespace std;
	using namespace Apollo;
	
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
	
//	typedef std::tr1::function<void(const Event&)> Callback;
	typedef int Callback;
	
	//////////////////////////////////////////////////
	// Event dispatcher
	//////////////////////////////////////////////////
	
	class EventDispatcher {
	private:
		std::map<const std::string, std::map<int, std::vector<Callback > > > eventHandlers; // The deep-rooted std::vector<float> should be of Callback type
	public:
		
		EventDispatcher() {
			printf("!!! Apollo::EventDispatcher is still in production! Do not use yet.\n");
		}
		
		bool hasListener(const std::string type);
		void dispatchEvent(const Event& evt);
		
		template <class ListenerClass>
		void addListener(const std::string &type, ListenerClass* listener, void (ListenerClass::*listenerMethod)(), int priority = 0) {
//			eventHandlers[type][priority].push_back( std::tr1::bind( listenerMethod, listener ) );
		}
		
		template <class ListenerClass>
		void removeListener(const std::string &type, ListenerClass* listener, void (ListenerClass::*listenerMethod)()) {
			if(!hasListener(type)) return;
			
			// Reference to keep the code clean
			std::map<int, std::vector<Callback > > &allFunctions = eventHandlers[type];
			
			// Since we don't know the function's priority, we'll search for it
			for(std::map<int, std::vector<Callback > >::iterator i=allFunctions.begin(); i!=allFunctions.end(); ++i) {
				// Saving a branch here: instead of checking if the callback exists let remove() do it for us
//				i->second.remove(listener);
				
				// Remove object from the map if list gone empty to eliminate false positives
				if(i->second.empty()) allFunctions.erase(i);
			}
			
			// Remove map to eliminate false positives
			if(allFunctions.empty()) eventHandlers.erase(type);
		}
		
	};
	
	extern EventDispatcher Dispatcher;

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
}
