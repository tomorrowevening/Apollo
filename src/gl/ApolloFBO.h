//
//  ApolloFBO.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"
#include "ApolloGL.h"
#include "ApolloTexture.h"

namespace Apollo {
	namespace gl {
		
		class FBO {
		public:
			void setup();
			void dispose();
			void start();
			void stop();
			void draw();
		};
		
	}
}
