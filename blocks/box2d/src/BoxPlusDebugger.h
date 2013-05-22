//
//  BoxPlusDebugger.h
//
//  Created by Colin Duffy on 4/24/13.
//
//

#pragma once
#include "Box2D.h"
#include "BoxPlusCommon.h"

#ifdef OF_VERSION_MAJOR
#include "ofMain.h"
#endif

class BoxPlusDebugger : public b2Draw {
public:
	
	float scale;
	
	BoxPlusDebugger() {
		scale = 1.f;
	}
	
	~BoxPlusDebugger() {
		
	}
	
	virtual void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	virtual void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
	virtual void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
	virtual void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
	virtual void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
	virtual void DrawTransform(const b2Transform& xf);
	
};
