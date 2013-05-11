//
//  BoxEngine.h
//
//  Created by Colin Duffy on 4/23/13.
//
//

#pragma once
#include <vector>
#include "Box2D.h"
#include "BoxPlusCommon.h"
#include "BoxShape.h"

#ifdef BOX_PLUS_DEBUG
#include "BoxRenderer.h"
#endif

using namespace std;

class BoxEngine : public b2ContactListener {
public:
	
	b2Vec2 gravity;
	
	b2World* world;
	b2Body* ground;
	
	float groundFriction, groundBounce;
	
	int updateFrequency;
	
	BoxEngine();
	~BoxEngine();
	virtual void setup();
	virtual void dispose();
	virtual void enable();
	virtual void disable();
	virtual void update();
	virtual void draw();
	
	virtual void play();
	virtual void stop();
	virtual void restart();
	
	void addBound(float x, float y, float wid, float hei);
	void clearBounds();
	
	// Shapes
	virtual void addShape(BoxShape* shape);
	virtual void removeShape(BoxShape* shape);
	void removeShapeNum(int index);
	void removeAllShapes();
	
	void addRect(float x, float y, float wid, float hei,
				 float friction = 0.5f,
				 float bounce = 0.3f,
				 bool dynamicBody = true);
	
	void addCircle(float x, float y, float radius,
				 float friction = 0.5f,
				 float bounce = 0.3f,
				 bool dynamicBody = true);
	
	// Getters
	BoxShape* operator[](unsigned i);
	int getFPS();
	int totalShapes();
	
	// Setters
	void setFPS(int value);
	
protected:
	
	int fps;
	float timeStep;
	bool playing;
	std::vector<BoxShape*> shapes;
	
	virtual void contactBegin(b2Contact* contact) {}
	virtual void contactEnd(b2Contact* contact) {}
	
private:
	
	virtual void BeginContact(b2Contact* contact) {
		if(contact->GetFixtureA() == NULL || contact->GetFixtureB() == NULL) return;
		contactBegin(contact);
	}
	
	virtual void EndContact(b2Contact* contact) {
		if(contact->GetFixtureA() == NULL || contact->GetFixtureB() == NULL) return;
		contactEnd(contact);
	}
	
};
