//
//  ApolloTime.h
//  Apollo
//  Created by Colin Duffy on 5/26/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once

#include "ApolloCore.h"
#include <time.h>
#include <stdio.h>
#ifdef APOLLO_COCOA
#include <sys/time.h>
#endif

namespace Apollo {
	
	double getElapsedMS(double from = -1);
	double getSystemMS();
	unsigned long long getSystemTime();
	
	static double startTime = getSystemMS();
	
	class Stopwatch {
	public:
		
		float initTime, endTime, lastLap, ms;
		
		Stopwatch(bool startNow = false) {
			initTime = endTime = lastLap = ms = 0;
			if(startNow) start();
		}
		
		float start();
		float stop();
		float lap();
		float read();
		
	};
	
}
