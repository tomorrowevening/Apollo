//
//  StringUtil.h
//
//  Created by Colin Duffy on 4/27/13.
//
//

#pragma once

// String
#include "Apollo.h"
#include <iostream>
#include <iostream>
#include <sstream>

namespace Apollo {
	
	using std::ostringstream;
	using std::stringstream;
	
	template <class T>
	string toString(const T& value) {
		ostringstream out;
		out << value;
		return out.str();
	}
	
	template<class T>
	string toString(const vector<T>& values) {
		stringstream out;
		int n = values.size();
		out << "{";
		if(n > 0) {
			for(int i = 0; i < n - 1; i++) {
				out << values[i] << ", ";
			}
			out << values[n - 1];
		}
		out << "}";
		return out.str();
	}
}
