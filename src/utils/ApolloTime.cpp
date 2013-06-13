//
//  ApolloTime.cpp
//  Apollo
//  Created by Colin Duffy on 5/26/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#include "ApolloTime.h"

namespace Apollo {
	
	double getElapsedMS(double from) {
		return getSystemMS() - (from != -1 ? from : startTime);
	}
	
	double getSystemMS() {
		return (double)getSystemTime();
	}
	
	unsigned long long getSystemTime() {
#ifndef APOLLO_MSW
		struct timeval now;
		gettimeofday( &now, NULL );
		return (unsigned long long) now.tv_usec/1000 + (unsigned long long) now.tv_sec*1000;
#else
		return timeGetTime();
#endif
	}
	
	//////////////////////////////////////////////////
	// Stopwatch
	//////////////////////////////////////////////////
	
	float Stopwatch::start() {
		lastLap = initTime = getSystemMS();
		return read();
	}
	
	float Stopwatch::stop() {
		endTime = getSystemMS();
		ms = endTime - initTime;
		return ms;
	}
	
	float Stopwatch::lap() {
		float now = getSystemMS();
		ms = now - lastLap;
		lastLap = now;
		return ms;
	}
	
	float Stopwatch::read() {
		return getSystemMS() - initTime;
	}
	
	
}
