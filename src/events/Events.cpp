//
//  Event.cpp
//  OFBoxShapes
//
//  Created by Colin Duffy on 4/25/13.
//
//

#include "Events.h"

//EventDispatcher Dispatcher;

//////////////////////////////////////////////////
// Event Dispatcher
//////////////////////////////////////////////////

bool EventDispatcher::hasListener(const std::string type) {
	return eventHandlers.find(type) != eventHandlers.end();
}

void EventDispatcher::dispatchEvent(const Event& event) {
	if(!hasListener(event.type)) return;
	
	std::map<int, std::list<Callback> > &allCallbacks = eventHandlers[event.type];
	for(std::map<int, std::list<Callback > >::reverse_iterator i = allCallbacks.rbegin(); i != allCallbacks.rend(); ++i) {
		std::list<Callback > &funcList = i->second;
		for(std::list<Callback >::iterator f=funcList.begin(); f!=funcList.end(); ++f) (*f)(event);
	}
}

template <class T>
void EventDispatcher::addListener(const std::string &type, T* listener, void (T::*handler)(const Event&), bool useCapture, int priority, bool useWeakReference) {
	Callback cb = std::tr1::bind(handler, listener);
	eventHandlers[type][priority].push_back(cb);
}

template <class T>
void EventDispatcher::removeListener(const std::string &type, T* listener, void (T::*handler)(const Event&)) {
	if(!hasListener(type)) return;
	
	std::map<int, std::list<Callback > > &allFunctions = eventHandlers[type];
	for(std::map<int, std::list<Callback > >::iterator i = allFunctions.begin(); i != allFunctions.end(); ++i) {
		i->second.remove(listener);
		if(i->second.empty()) allFunctions.erase(i);
	}
	
	if(allFunctions.empty()) eventHandlers.erase(type);
}

//////////////////////////////////////////////////
// Common event types
//////////////////////////////////////////////////

// Key
const std::string KeyEvent::DOWN = "Apollo::KeyEvent::Down";
const std::string KeyEvent::UP = "Apollo::KeyEvent::Up";

// Mouse
const std::string MouseEvent::OVER = "Apollo::MouseEvent::Over";
const std::string MouseEvent::OUT = "Apollo::MouseEvent::Out";
const std::string MouseEvent::CLICK = "Apollo::MouseEvent::Click";
const std::string MouseEvent::PRESSED = "Apollo::MouseEvent::Pressed";
const std::string MouseEvent::RELEASED = "Apollo::MouseEvent::Released";
const std::string MouseEvent::RELEASED_OUTSIDE = "Apollo::MouseEvent::ReleasedOutside";
const std::string MouseEvent::SCROLL = "Apollo::MouseEvent::Scroll";

// Touch
const std::string TouchEvent::DOWN = "Apollo::TouchEvent::Down";
const std::string TouchEvent::UP = "Apollo::TouchEvent::Up";
const std::string TouchEvent::MOVE = "Apollo::TouchEvent::Move";
const std::string TouchEvent::DOUBLE_TAP = "Apollo::TouchEvent::DoubleTap";
const std::string TouchEvent::CANCEL = "Apollo::TouchEvent::Cancel";
