//
//  BoxShape.h
//
//  Created by Colin Duffy on 4/23/13.
//
//

#pragma once
#include "Box2D.h"
#include "BoxUtils.h"
#include <vector>

using std::vector;


//////////////////////////////////////////////////
// Shape
//////////////////////////////////////////////////

class BoxShape {
public:
	
	enum BoxShapeType {
		Rectangle = 0,
		Circle = 1,
		Polygon = 2
	};
	
	float bounce, density, friction;
	
	BoxShape();
	~BoxShape();
	
	virtual void dispose();
	virtual void update();
	virtual void draw() {}
	
	// Getters
	b2Body* getBody();
	bool isAlive() { return true; }
	float getX() { return x; }
	float getY() { return y; }
	float getVelocityX();
	float getVelocityY();
	float getAngle();
	int getType();
	
	// Setters
	void setX(float value);
	void setY(float value);
	void setVelocityX(float value);
	void setVelocityY(float value);
	
protected:
	
	float x, y, velocityX, velocityY;
	BoxShapeType type;
	
	b2Body* body;
	b2FixtureDef fixture;
	
	virtual void init(b2World* world, bool dynamicBody = true);
	void updatePosition();
	void clearFixtures();
	
	bool hasBody() { return body != NULL; }
	
};


//////////////////////////////////////////////////
// Rectangle
//////////////////////////////////////////////////

class BoxRect : public BoxShape {
public:
	
	BoxRect();
	virtual void init(b2World* world, float x, float y, float wid, float hei, bool dynamicBody = true);
	
	// Getters
	float getWidth() { return width; }
	float getHeight(){ return height; }
	
	// Setters
	void setWidth(float value);
	void setHeight(float value);
	
protected:
	float width, height;
	void updateSize();
	
};


//////////////////////////////////////////////////
// Circle
//////////////////////////////////////////////////

class BoxCircle : public BoxShape {
public:
	
	BoxCircle();
	virtual void init(b2World* world, float x, float y, float radius, bool dynamicBody = true);
	
	// Getters
	float getRadius() { return radius; }
	
	// Setters
	void setRadius(float value);
	
protected:
	float radius;
	
};


//////////////////////////////////////////////////
// PolyEdge
//////////////////////////////////////////////////

class BoxPolyEdge : public BoxShape {
public:
	
	virtual void init(b2World* world, float x, float y, bool dynamicBody = true);
	virtual void addVertex(float x, float y, bool update = false);
	virtual void addVertexes(vector<b2Vec2> vertices, bool update = true);
	virtual void updateVertices();
	
	int totalVertices() { return (int)vertices.size(); }
	b2Vec2 vertice(int index) { return vertices[index]; }
	
protected:
	std::vector<b2Vec2> vertices;
};


//////////////////////////////////////////////////
// Polygon
//////////////////////////////////////////////////

class BoxPolygon : public BoxShape {
protected:
	b2Vec2 vertices[8];
	int _totalVertices;
public:
	
	static const int MIN_POLY_VERTICES = 3;
	static const int MAX_POLY_VERTICES = 8;
	
	BoxPolygon();
	virtual void init(b2World* world, float x, float y, bool dynamicBody = true);
	virtual void addVertex(float x, float y, bool update = false);
	virtual void addVertexes(vector<b2Vec2> vertices, bool update = true);
	virtual void updateVertices();
	
	int totalVertices() { return _totalVertices; }
	b2Vec2 vertice(int index) { return vertices[index]; }
};




