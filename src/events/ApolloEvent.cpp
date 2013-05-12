//
//  ApolloEvent.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#include "ApolloEvent.h"

namespace Apollo {
	
	string AppEvent::INIT			= "Apollo::AppEvent::init";
	string AppEvent::UPDATE			= "Apollo::AppEvent::update";
	string AppEvent::DRAW			= "Apollo::AppEvent::draw";
	string AppEvent::RESIZE			= "Apollo::AppEvent::resize";
	
	string KeyEvent::DOWN			= "Apollo::KeyEvent::down";
	string KeyEvent::UP				= "Apollo::KeyEvent::up";
	
	string MouseEvent::DRAGGED		= "Apollo::MouseEvent::dragged";
	string MouseEvent::MOVED		= "Apollo::MouseEvent::moved";
	string MouseEvent::PRESSED		= "Apollo::MouseEvent::pressed";
	string MouseEvent::RELEASED		= "Apollo::MouseEvent::released";
	string MouseEvent::SCROLLED		= "Apollo::MouseEvent::scrolled";
	
	string TouchEvent::MOVE			= "Apollo::TouchEvent::move";
	string TouchEvent::DOWN			= "Apollo::TouchEvent::down";
	string TouchEvent::UP			= "Apollo::TouchEvent::up";
	string TouchEvent::DOUBLE_TAP	= "Apollo::TouchEvent::doubleTap";
	string TouchEvent::CANCEL		= "Apollo::TouchEvent::cancel";
}
