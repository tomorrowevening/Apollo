//
//  BoxEngine.cpp
//
//  Created by Colin Duffy on 4/23/13.
//
//

#include "BoxEngine.h"

#pragma mark Construct

BoxEngine::BoxEngine() {
	updateFrequency = 4;
	gravity.Set(0, 75.f);
	setFPS(60);
	enable();
}

BoxEngine::~BoxEngine() {
	dispose();
}

#pragma mark - Management

void BoxEngine::setup() {
	world = new b2World(gravity);
	world->SetAllowSleeping(true);
	
#ifdef BOX_PLUS_DEBUG
	BoxRenderer* debugger = new BoxRenderer(BOX_PLUS_SCALE);
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	flags += b2Draw::e_jointBit;
	flags += b2Draw::e_centerOfMassBit;
	flags += b2Draw::e_aabbBit;
	flags += b2Draw::e_pairBit;
	debugger->SetFlags(flags);
	
	world->SetDebugDraw(debugger);
#endif
	
	b2BodyDef groundDef;
	groundDef.type = b2_staticBody;
	ground = world->CreateBody(&groundDef);
}

void BoxEngine::dispose() {
	removeAllShapes();
	
	world->ClearForces();
	delete world;
	world = NULL;
}

void BoxEngine::addBound(float x, float y, float wid, float hei) {
	const float halfW = wid * 0.5f;
	const float halfH = hei * 0.5f;
	
	b2PolygonShape shape;
	shape.SetAsBox(halfW, halfH);
	
	b2FixtureDef fix;
	fix.density		= 0;
	fix.friction	= groundFriction;
	fix.restitution	= groundBounce;
	fix.shape = &shape;
	
	
	ground->CreateFixture(&fix);
	
}

void BoxEngine::clearBounds() {
	BoxUtil::clearFixtures(ground);
}

void BoxEngine::enable() {
	playing = true;
}

void BoxEngine::disable() {
	playing = false;
}

BoxShape* BoxEngine::operator[](unsigned i) {
	return shapes[i];
}

#pragma mark - Update

void BoxEngine::update() {
	if(!playing) return;
	
	world->SetGravity(gravity);
	
	for(int i = 0; i < updateFrequency; ++i) world->Step(timeStep, 16, 2);
	
	const int total = totalShapes()-1;
	for(int i = total; i > -1; --i) {
		shapes[i]->update();
		if(!shapes[i]->isAlive()) removeShape(shapes[i]);
	}
}

void BoxEngine::draw() {
	const int total = totalShapes();
	for(int i = 0; i < total; ++i) shapes[i]->draw();
	
#ifdef BOX_PLUS_DEBUG
	world->DrawDebugData();
#endif
}

#pragma mark - Gameplay

void BoxEngine::play() {
	enable();
}

void BoxEngine::stop() {
	disable();
}

void BoxEngine::restart() {
	
}

#pragma mark - Shapes

void BoxEngine::addShape(BoxShape* shape) {
	shapes.push_back(shape);
}

void BoxEngine::addRect(float x, float y, float wid, float hei, float friction, float bounce, bool dynamicBody) {
	const float halfW = wid * 0.5f;
	const float halfH = hei * 0.5f;
	
	BoxRect* shape = new BoxRect();
	shape->friction = friction;
	shape->bounce	= bounce;
	shape->init(world, x+halfW, y+halfH, halfW, halfH, dynamicBody);
	shapes.push_back(shape);
}

void BoxEngine::addCircle(float x, float y, float radius, float friction, float bounce, bool dynamicBody) {
	const float halfR = radius * 0.5f;
	
	BoxCircle* shape = new BoxCircle();
	shape->friction = friction;
	shape->bounce	= bounce;
	shape->init(world, x+halfR, y+halfR, halfR, dynamicBody);
	shapes.push_back(shape);
}

void BoxEngine::removeShape(BoxShape* shape) {
	shape->dispose();
	delete shape;
}

void BoxEngine::removeShapeNum(int index) {
	shapes.erase(shapes.begin() + index);
}

void BoxEngine::removeAllShapes() {
	for(int i = totalShapes()-1; i > -1; --i) removeShape(shapes[i]);
}

#pragma mark - Getters

int BoxEngine::getFPS() {
	return fps;
}

int BoxEngine::totalShapes() {
	return (int)shapes.size();
}

#pragma mark - Setters

void BoxEngine::setFPS(int value) {
	fps = value;
	timeStep = 1.0f / (float)fps;
}
