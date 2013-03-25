//
//  StringUtil.h
//
//  Created by Colin Duffy on 9/27/12.
//
//

#pragma once

#include "ofUtils.h"

class StringUtil {
public:
	
	static string fileType(string path) {
		return path.substr(path.find_last_of(".")+1);
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
				result += ofToString(num);
				break;
			}
		}
		
		return prefix + result + suffix;
	}
};
