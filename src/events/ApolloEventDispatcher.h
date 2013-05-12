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
	
	class EventDispatcher {
	protected:
		void *target;
	private:
		typedef struct st_Data {
			void* listener;
			listenerHandler handler;
		} EventData;
		
		map<const string, vector<EventData> > handlers;
	public:
		
		EventDispatcher() { target = this; }
		~EventDispatcher(){ target = NULL; handlers.clear(); }
		
		void dispatchEvent(Event *event);
		void addListener(const string &type, void* listener, listenerHandler handler);
		void removeListener(const string &type, listenerHandler handler);
		bool hasListener(const string &type);
		const int totalListeners() { return (int)handlers.size(); }
	};
	
	extern EventDispatcher Dispatcher;
	
}