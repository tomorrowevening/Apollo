//
//  Event.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"

namespace Apollo {
	
	using std::string;
	using namespace Apollo;
	
	class EventArgs {};
	
	class Event {
	public:
		
		static const std::string UPDATE;
		static const std::string DRAW;
		
		std::string type;
		EventArgs* args;
		
		Event(std::string type = ""){
			this->type = type;
		}
	};
	
	class KeyEvent : public Event {
	public:
		static const std::string DOWN;
		static const std::string UP;
	};
	
	class MouseEvent : public Event {
	public:
		static const std::string MOVED;
		static const std::string PRESSED;
		static const std::string RELEASED;
		static const std::string SCROLLED;
	};
	
	class TouchEvent : public Event {
	public:
		static const std::string MOVE;
		static const std::string DOWN;
		static const std::string UP;
		static const std::string DOUBLE_TAP;
		static const std::string CANCEL;
	};
	
}

