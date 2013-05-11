//
//  BoxRenderer.h
//  BoxEngine
//
//  Created by Colin Duffy on 4/27/13.
//
//

#pragma once
#include "Apollo.h"
#include "Box2d.h"
#include "BoxUtils.h"

class BoxRenderer : public b2Draw {
protected:
	
	const static int CIRCLE_SEGMENTS = 8;
	
	b2Vec2* createCircle(const b2Vec2& center, float32 radius) {
		b2Vec2* vertices = new b2Vec2[CIRCLE_SEGMENTS];
		float ang;
		for(int i = 0; i < CIRCLE_SEGMENTS; ++i) {
			ang = ((float)i / (float)CIRCLE_SEGMENTS) * TWO_PI;
			vertices[i].x = cosf(ang) * radius + center.x;
			vertices[i].y = sinf(ang) * radius + center.y;
		}
		return vertices;
	}
	
	void drawShape(const b2Vec2* vertices, int32 vertexCount, const b2Color& color, bool fill) {
		int i;
//#ifdef APOLLO_COCOA_TOUCH
//		
//#else
		glBegin(fill ? GL_TRIANGLE_FAN : GL_LINE_LOOP);
		glColor3f(color.r, color.g, color.b);
		for(i = 0; i < vertexCount; ++i) glVertex2f(vertices[i].x, vertices[i].y);
		glEnd();
//#endif
	}
	
public:
	
    BoxRenderer( float32 ratio ) : mRatio(ratio) {}
	
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
		drawShape(vertices, vertexCount, color, false);
	}
	
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
		drawShape(vertices, vertexCount, color, true);
	}
	
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
		drawShape(createCircle(center, radius), CIRCLE_SEGMENTS, color, false);
	}
	
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
		drawShape(createCircle(center, radius), CIRCLE_SEGMENTS, color, true);
	}
	
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
		glBegin(GL_LINES);
		glColor3f(color.r, color.g, color.b);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p2.x, p2.y);
		glEnd();
	}
	
    void DrawTransform(const b2Transform& xf) {
		
	}
	
    void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
		glBegin(GL_POINT);
		glColor3f(color.r, color.g, color.b);
		glVertex2f(p.x, p.y);
		glEnd();
	}
	
    void DrawString(int x, int y, const char* string, ...) {
		
	}
	
    void DrawAABB(b2AABB* aabb, const b2Color& color) {
		
	}
	
private:
    float mRatio;
};
