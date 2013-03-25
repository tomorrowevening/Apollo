//
//  ParticleController.h
//  Apollo
//
//  Created by Colin Duffy on 10/1/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#include <vector>
#include "Particle.h"
#include "Force.h"
#include "LinearForce.h"
#include "RotationalForce.h"

using namespace std;

class ParticleController {
public:
	
	vec3f pos, size, time;
	vector<Particle*> particles;
	vector<Force*> forces;
	
	bool constrain, wrap, bounceConstrain;
	
	ParticleController();
	void constrainParticles();
	void wrapParticles();
	void bounceConstrainParticles(float amount = 0.05f);
	
	void update();
	
	Particle* operator[](unsigned i);
	int totalParticles();
	int totalForces();
	
	void addParticle(Particle* p);
	void addParticle(float x, float y, float z);
	
	void addForce(Force* f);
	void addForce(float x, float y, float z);
	
	void removeParticle(int index);
	void removeForce(int index);
	
};
