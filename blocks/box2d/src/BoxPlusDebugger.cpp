//
//  BoxPlusDebugger.cpp
//
//  Created by Colin Duffy on 4/24/13.
//
//

#include "BoxPlusDebugger.h"

void BoxPlusDebugger::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
#ifdef OF_VERSION_MAJOR
	ofSetColor(color.r*255.0, color.g*255.0, color.b*255.0);
	ofBeginShape();
	for (int i = 0; i < vertexCount; ++i) {
		ofVertex(vertices[i].x*BOX_PLUS_SCALE, vertices[i].y*BOX_PLUS_SCALE);
	}
	ofEndShape();
#else
	
#endif
}

void BoxPlusDebugger::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) {
#ifdef OF_VERSION_MAJOR
	ofSetHexColor(0xffffff);
	ofBeginShape();
	for(int i=0; i<vertexCount; ++i) {
		ofVertex(vertices[i].x*BOX_PLUS_SCALE, vertices[i].y*BOX_PLUS_SCALE);
	}
	ofEndShape();
#else
	
#endif
}

void BoxPlusDebugger::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
#ifdef OF_VERSION_MAJOR
	const float32 k_segments = 16.0f;
	const float32 k_increment = 2.0f * b2_pi / k_segments;
	float32 theta = 0.0f;
	ofSetColor(color.r*255.0, color.g*255.0, color.b*255.0);
	ofBeginShape();
	for (int i = 0; i < k_segments; i++) {
		b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
		ofVertex(v.x, v.y);
		theta += k_increment;
	}
	ofEndShape();
#else
	
#endif
}

void BoxPlusDebugger::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
#ifdef OF_VERSION_MAJOR
	const float32 k_segments    = 16.0f;
	const float32 k_increment   = 2.0f * b2_pi / k_segments;
	float32 theta			    = 0.0f;
	float rad = (radius*scale);
	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	ofSetColor(255, 255, 255, 200);
	ofFill();
	ofCircle(center.x*scale, center.y*scale, rad);
#else
	
#endif
}

void BoxPlusDebugger::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
#ifdef OF_VERSION_MAJOR
	ofSetColor(255, 255, 255, 200);
	ofLine(p1.x*BOX_PLUS_SCALE, p1.y*BOX_PLUS_SCALE, p2.x*BOX_PLUS_SCALE, p2.y*BOX_PLUS_SCALE);
#else
	
#endif
}

void BoxPlusDebugger::DrawTransform(const b2Transform& xf) {
#ifdef OF_VERSION_MAJOR
	
#else
	
#endif
}


