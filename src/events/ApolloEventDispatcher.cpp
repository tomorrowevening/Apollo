//
//  EventDispatcher.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#include "ApolloEventDispatcher.h"

namespace Apollo {
	
	EventDispatcher Trigger;
	
	void EventDispatcher::dispatchEvent(const Event& evt) {
		printf("Dispatch event: %s\n", evt.type.c_str());
	}
	
	void EventDispatcher::addListener(string type) {
		
	}
	
	void EventDispatcher::removeListener(string type) {
		
	}
	
	bool EventDispatcher::hasListener(string type) {
		return false;
	}
	
	
}
