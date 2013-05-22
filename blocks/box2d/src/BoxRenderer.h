//
//  BoxRenderer.h
//  BoxEngine
//
//  Created by Colin Duffy on 4/27/13.
//
//

#pragma once
#include "ApolloCore.h"
#include "ApolloGLEnum.h"
#include "ApolloMath.h"
#include "Box2d.h"
#include "BoxUtils.h"

#include "cocos2d.h"

class BoxRenderer : public b2Draw {
protected:
	
	const static int CIRCLE_SEGMENTS = 8;
	
#ifdef COCOS2D_VERSION
    cocos2d::CCGLProgram* mShaderProgram;
    GLint        mColorLocation;
    void initShader( void );
#endif
	
	b2Vec2* createCircle(const b2Vec2& center, float32 radius);
	void drawShape(const b2Vec2* vertices, int32 vertexCount, const b2Color& color, bool fill);
	
public:
	
    BoxRenderer( float32 ratio ) : mRatio(ratio) {
#ifdef COCOS2D_VERSION
		this->initShader();
#endif
	}
	
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
    void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
    void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
    void DrawTransform(const b2Transform& xf);
    void DrawPoint(const b2Vec2& p, float32 size, const b2Color& color);
    void DrawString(int x, int y, const char* string, ...);
    void DrawAABB(b2AABB* aabb, const b2Color& color);
	
private:
    float mRatio;
};
