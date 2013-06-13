//
//  EventDispatcher.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#include "ApolloEventDispatcher.h"
#include "ApolloStrings.h"

namespace Apollo {
	
	EventDispatcher Dispatcher;
	
	void EventDispatcher::dispatchEvent(Event *event){
		if(!hasListener(event->type)) return;
		
		event->target = target;
		vector<EventData> &eHandlers = handlers[event->type];
		for(vector<EventData>::iterator f = eHandlers.begin(); f != eHandlers.end(); ++f){
			event->listener = f->listener;
			(*f->handler)(*event);
		}
		
		delete event;
	}
	
	void EventDispatcher::addListener(const string &type, void* listener, listenerHandler handler){
		EventData data;
		data.listener = listener;
		data.handler = handler;
		handlers[type].push_back(data);
	}
	
	void EventDispatcher::removeListener(const string &type, void* listener, listenerHandler handler){
		if(!hasListener(type)) return;
		
		const string sHandler = Apollo::toString(handler);
		vector<EventData> &eHandlers = handlers[type];
		for(vector<EventData>::iterator f = eHandlers.begin(); f != eHandlers.end(); f) {
			if(Apollo::toString(f->handler) == sHandler) {
				eHandlers.erase(f);
			} else {
				++f;
			}
		}
		if(eHandlers.empty()) handlers.erase(type);
	}
	
	bool EventDispatcher::hasListener(const string &type){
		return (handlers.find(type) != handlers.end());
	}
	
}
