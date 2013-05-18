//
//  Effectors.h
//  Badge
//
//  Created by Colin Duffy on 5/9/13.
//
//

#pragma once
#include "ApolloMath.h"

using namespace std;
using namespace Apollo;

class Effector {
public:
	string name;
	
	Effector() { name = "Linear"; }
	virtual const float getSize(float percent){ return percent; }
};

class CosEffector : public Effector {
public:
	
	CosEffector() { name = "Cos"; }
	virtual const float getSize(float percent){
		return (1 + cos(toDeg(percent * 360.f))) * 0.5;
	}
};

class SineEffector : public Effector {
public:
	
	SineEffector() { name = "Sine"; }
	virtual const float getSize(float percent){
		return (1 + sin(toDeg(percent * 360.f))) * 0.5;
	}
};
