//
//  Apollo.h
//
//  Created by Colin Duffy on 4/25/13.
//
//

#pragma once

// Common
#include <float.h>
#include <string>

// Array extensions
#include <list>
#include <map>
#include <vector>
#include <iterator>

#define APOLLO_VERSION 250

namespace Apollo {
	
	using std::list;
	using std::map;
	using std::string;
	using std::vector;
	using std::iterator;
	
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
	#define APOLLO_MSW
#elif defined(linux) || defined(__linux) || defined(__linux__)
	#define APOLLO_LINUX
#elif defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
	#define APOLLO_COCOA
	#if TARGET_OS_IPHONE
		#define APOLLO_COCOA_TOUCH
		#if TARGET_IPHONE_SIMULATOR
			#define APOLLO_COCOA_TOUCH_SIMULATOR
		#else
			#define APOLLO_COCOA_TOUCH_DEVICE
		#endif
	#else
		#define APOLLO_MAC
	#endif
#endif
	
}

#include "MathUtil.h"
#include "StringUtil.h"
