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
	
	static string formatDigits(int num, int totalDigits, string prefix, string suffix) {
		int i, n;
		int hundreds = 1;
		string result = "";
		for(i = 0; i <= totalDigits; ++i) {
			hundreds *= 10;
			if(num < hundreds) {
				for(n = i; n < totalDigits-1; ++n) {
					result += "0";
				}
				result += toString(num);
				break;
			}
		}
		
		return prefix + result + suffix;
	}
	
	static string fileType(string path) {
		return path.substr(path.find_last_of(".")+1);
	}
	
}
