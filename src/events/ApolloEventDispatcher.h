//
//  EventDispatcher.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"
#include "ApolloEvent.h"

namespace Apollo {
	
	using std::string;
	using namespace Apollo;
	
	class EventDispatcher {
	public:
		
		void dispatchEvent(const Event& evt);
		void addListener(string type);
		void removeListener(string type);
		bool hasListener(string type);
		
	};
	
	extern EventDispatcher Trigger;
	
}