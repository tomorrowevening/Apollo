//
//  ParticleController.cpp
//  Apollo
//
//  Created by Colin Duffy on 10/1/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#include "ParticleController.h"
#include "Particle.h"
#include "MathUtil.h"

ParticleController::ParticleController() {
	pos = vec3f::zero();
	size = vec3f::one();
	time = vec3f::one();
	
	bounceConstrain = false;
	constrain = false;
	wrap = true;
}

void ParticleController::constrainParticles() {
	int total = totalParticles();
	for(int i = 0; i < total; ++i) {
		particles[i]->constrain(size);
	}
}

void ParticleController::wrapParticles() {
	int total = totalParticles();
	for(int i = 0; i < total; ++i) {
		particles[i]->wrap(size);
	}
}

void ParticleController::bounceConstrainParticles(float amount) {
	vec3f dampen = vec3f(amount, amount, amount);
	int total = totalParticles();
	for(int i = 0; i < total; ++i) {
		particles[i]->bounceOffWalls(size, dampen);
	}
}

void ParticleController::update() {
	float amount = 0.5f;
	int i, total;
	vec3f dampen = vec3f(amount, amount, amount);
	vec3f maxBounds = pos + size;
	
	total = totalForces();
	for(i = 0; i < total; ++i) {
		forces[i]->update(particles);
	}
	
	for(i = 0; i < totalParticles();) {
		particles[i]->update(time);
		particles[i]->dampen();
		if(bounceConstrain) particles[i]->bounceOffWalls(pos, maxBounds, dampen);
		if(wrap) particles[i]->wrap(size);
		if(constrain) particles[i]->constrain(size);
		
		if(particles[i]->dead()) {
			removeParticle(i);
		} else {
			++i;
		}
	}
}

Particle* ParticleController::operator[](unsigned i) {
	return particles[i];
}

int ParticleController::totalParticles() {
	return particles.size();
}

int ParticleController::totalForces() {
	return forces.size();
}

void ParticleController::addParticle(Particle* p) {
	particles.push_back(p);
}

void ParticleController::addParticle(float x, float y, float z) {
	particles.push_back(new Particle(vec3f(x, y, z)));
}

void ParticleController::addForce(Force* f) {
	forces.push_back(f);
}

void ParticleController::addForce(float x, float y, float z) {
	Force* f = new Force();
	f->pos = vec3f(x, y, z);
	addForce(f);
}

void ParticleController::removeParticle(int index) {
	Particle* p = particles[index];
	particles.erase(particles.begin() + index);
	delete p;
	p = NULL;
}

void ParticleController::removeForce(int index) {
	Force* f = forces.at(index);
	forces.erase(forces.begin() + index);
	delete f;
	f = NULL;
}
