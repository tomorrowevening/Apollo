//
//  ApolloShader.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloCore.h"

namespace Apollo {
	namespace gl {
		
		using namespace std;
		using namespace Apollo;
		
		class Shader {
		public:
			
			void load(string vertPath, string fragPath);
			void bind();
			void unbind();
			
		};
		
	}
}
