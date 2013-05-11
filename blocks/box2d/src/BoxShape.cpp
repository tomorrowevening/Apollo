//
//  BoxShape.cpp
//
//  Created by Colin Duffy on 4/23/13.
//
//

#include "BoxShape.h"
#include "BoxPlusCommon.h"


//////////////////////////////////////////////////
#pragma mark Shape
//////////////////////////////////////////////////

BoxShape::BoxShape() {
	type = Polygon;
	density = 1.f;
}

BoxShape::~BoxShape() {
	dispose();
}

void BoxShape::init(b2World* world, bool dynamicBody) {
	density = dynamicBody ? 1.f : 0.f;
	
	b2BodyDef bodyDef;
	bodyDef.type = dynamicBody ? b2_dynamicBody : b2_staticBody;
	bodyDef.position.Set(x, y);
	body = world->CreateBody(&bodyDef);
	
	fixture.density		= density;
	fixture.friction	= friction;
	fixture.restitution	= bounce;
}

void BoxShape::dispose() {
	clearFixtures();
	if(hasBody()) body->GetWorld()->DestroyBody(body);
	body = NULL;
}

void BoxShape::update() {
	if(!hasBody()) return;
	for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()) {
		f->SetFriction(friction);
		f->SetRestitution(bounce);
	}
}

void BoxShape::clearFixtures() {
	BoxUtil::clearFixtures(body);
}

#pragma mark Getters

b2Body* BoxShape::getBody() {
	return body;
}

float BoxShape::getVelocityX() {
	if(hasBody()) return body->GetLinearVelocity().x;
	return 0;
}

float BoxShape::getVelocityY() {
	if(hasBody()) return body->GetLinearVelocity().y;
	return 0;
}

int BoxShape::getType() {
	return type;
}

float BoxShape::getAngle() {
	return 0;
}

#pragma mark Setters

void BoxShape::setX(float value) {
	x = value;
	updatePosition();
}

void BoxShape::setY(float value) {
	y = value;
	updatePosition();
}

void BoxShape::setVelocityX(float value) {
	velocityX = value;
	body->SetLinearVelocity(b2Vec2(velocityX, velocityY));
}

void BoxShape::setVelocityY(float value) {
	velocityY = value;
	body->SetLinearVelocity(b2Vec2(velocityX, velocityY));
}

#pragma mark Private

void BoxShape::updatePosition() {
	if(hasBody()) body->SetTransform(b2Vec2(x, y), body->GetAngle());
}


//////////////////////////////////////////////////
#pragma mark - Rectangle
//////////////////////////////////////////////////

BoxRect::BoxRect() {
	type = Rectangle;
}

void BoxRect::init(b2World* world, float x, float y, float wid, float hei, bool dynamicBody) {
	this->x = x;
	this->y = y;
	this->width  = wid;
	this->height = hei;
	
	BoxShape::init(world, dynamicBody);
	
	b2PolygonShape shape;
	shape.SetAsBox(this->width, this->height);
	fixture.shape = &shape;
	
	body->CreateFixture( &fixture );
}

void BoxRect::updateSize() {
	if(!hasBody()) return;
	
	const float boxWid = width;
	const float boxHei = height;
	b2PolygonShape* shape;
	for(b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()) {
		shape = (b2PolygonShape*)f->GetShape();
		shape->SetAsBox(boxWid, boxHei);
	}
}

#pragma mark Getters

#pragma mark Setters

void BoxRect::setWidth(float value) {
	width = value;
	updateSize();
}
void BoxRect::setHeight(float value) {
	height = value;
	updateSize();
}


//////////////////////////////////////////////////
#pragma mark - Circle
//////////////////////////////////////////////////

BoxCircle::BoxCircle() {
	type = Circle;
}

void BoxCircle::init(b2World* world, float x, float y, float radius, bool dynamicBody) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	
	BoxShape::init(world, dynamicBody);
	
	b2CircleShape shape;
	shape.m_radius = radius;
	fixture.shape = &shape;
	
	body->CreateFixture( &fixture );
}

#pragma mark Getters

#pragma mark Setters

void BoxCircle::setRadius(float value) {
	radius = value;
	const float boxRadius = radius;
	for(b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()) f->GetShape()->m_radius = boxRadius;
}


//////////////////////////////////////////////////
#pragma mark - PolyEdge
//////////////////////////////////////////////////

void BoxPolyEdge::init(b2World* world, float x, float y, bool dynamicBody) {
	this->x = x;
	this->y = y;
	
	BoxShape::init(world);
}

void BoxPolyEdge::updateVertices() {
	if(!hasBody()) return;
	clearFixtures();
	
	const int total = totalVertices();
	for(int i = 1; i < total; ++i) {
		b2EdgeShape shape;
		shape.Set(vertices[i-1], vertices[i]);
		
		b2FixtureDef fix;
		fix.density = density;
		fix.friction = friction;
		fix.restitution = bounce;
		fix.shape = &shape;
		
		body->CreateFixture(&fix);
	}
}

void BoxPolyEdge::addVertex(float x, float y, bool update) {
	if(!hasBody()) return;
	vertices.push_back(b2Vec2(x, y));
	if(update) updateVertices();
}

void BoxPolyEdge::addVertexes(vector<b2Vec2> polyVertices, bool update) {
	const int total = (int)polyVertices.size();
	for(int i = 0; i < total; ++i) addVertex(polyVertices[i].x, polyVertices[i].y, false);
	if(update) updateVertices();
}


//////////////////////////////////////////////////
#pragma mark - Polygon
//////////////////////////////////////////////////

BoxPolygon::BoxPolygon() {
	_totalVertices = 0;
	for(int i = 0; i < MAX_POLY_VERTICES; ++i) vertices[i].Set(0, 0);
}

void BoxPolygon::init(b2World* world, float x, float y, bool dynamicBody) {
	this->x = x;
	this->y = y;
	
	BoxShape::init(world);
}

void BoxPolygon::addVertex(float x, float y, bool update) {
	if(_totalVertices == MAX_POLY_VERTICES) return;
	vertices[_totalVertices].Set(x, y);
	++_totalVertices;
	if(update) updateVertices();
}

void BoxPolygon::addVertexes(vector<b2Vec2> vertices, bool update) {
	const int total = (int)vertices.size();
	for(int i = 0; i < total; ++i) addVertex(vertices[i].x, vertices[i].y, false);
	if(update) updateVertices();
}

void BoxPolygon::updateVertices() {
	if(!hasBody() || _totalVertices < MIN_POLY_VERTICES) return;
	clearFixtures();
	
	b2PolygonShape shape;
	shape.Set(vertices, _totalVertices);
	
	b2FixtureDef fix;
	fix.density = density;
	fix.friction = friction;
	fix.restitution = bounce;
	fix.shape = &shape;
	
	body->CreateFixture(&fix);
}



