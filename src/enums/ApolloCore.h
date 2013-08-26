//
//  ApolloCore.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once

// Common
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <float.h>

// Array extensions
#include <list>
#include <map>
#include <vector>
#include <iterator>

#define APOLLO_VERSION 125

#if defined(_WIN64) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN32)
	#define APOLLO_MSW
#elif defined(linux) || defined(__linux) || defined(__linux__)
	#define APOLLO_LINUX
#elif __APPLE__
	#include "TargetConditionals.h"
	#define APOLLO_COCOA
	#if TARGET_OS_IPHONE
		#define APOLLO_COCOA_TOUCH
		#define APOLLO_GLES
		#if TARGET_IPHONE_SIMULATOR
			#define APOLLO_COCOA_TOUCH_SIMULATOR
		#else
			#define APOLLO_COCOA_TOUCH_DEVICE
		#endif
	#else
		#define APOLLO_MAC
	#endif
#elif defined (ANDROID)
	#define APOLL_ANDROID
	#define APOLLO_GLES
#endif

// Set these within the project's Preprocessor Macros
//#define APOLLO_DEBUG
//#define APOLLO_OPENFRAMEWORKS
//#define APOLLO_CINDER
//#define APOLLO_COCOS2D
//#define APOLLO_GLSL
//#define APOLLO_BOX2D
//#define APOLLO_KINECT
//#define APOLLO_LEAP
//#define APOLLO_ARDUINO
//#define APOLLO_RASPBERRY_PI

namespace Apollo {}

using namespace std;
using std::list;
using std::map;
using std::string;
using std::vector;
using std::iterator;
