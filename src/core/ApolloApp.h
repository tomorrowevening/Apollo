//
//  ApolloApp.h
//  SushiHero
//
//  Created by colin.duffy on 5/15/13.
//  Copyright (c) 2013 Design Symphony, LLC. All rights reserved.
//

#pragma once
#include "Apollo.h"

namespace Apollo {
	
	using namespace std;
	using namespace Apollo;
	
	class ApolloApp {
	public:
		
		virtual ~ApolloApp(){ exit(); }
		
		// Core
		virtual void setup();
		virtual void exit();
		virtual void update();
		virtual void draw();
		virtual void enable();
		virtual void disable();
		
		virtual void enableEvents();
		virtual void disableEvents();
		
		// Handlers
		virtual void keyHandler(KeyEvent& key) {}
		virtual void mouseHandler(MouseEvent& key) {}
		virtual void touchHandler(TouchEvent& key) {}
		
		static ApolloApp& app();
		
	private:
		
		ApolloApp() {};
		ApolloApp(ApolloApp const&);
		void operator=(ApolloApp const&);
		static void appHandlers(Event& evt);
		
	};
}
