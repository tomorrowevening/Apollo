//
//  ApolloMask.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"

namespace Apollo {
	
	class Mask {
	protected:
		
		
		
	public:
		
		bool active;
		
		Mask(int wid = 0, int hei = 0) {
			active = true;
			if(wid > 0 && hei > 0) setup(wid, hei);
		}
		
		void setup(int wid, int hei);
		void dispose();
		void render(float x = 0, float y = 0);
		
	};
	
}
