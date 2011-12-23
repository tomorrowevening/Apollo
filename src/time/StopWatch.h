//
//  StopWatch.h
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#pragma once

class StopWatch {
public:
	
	float		initTime;
	float		endTime;
	float		lastLap;
	float		ms;
	
	StopWatch();
	float lap();
	float read();
	float start();
	float stop();
private:
	int now();
	
};
