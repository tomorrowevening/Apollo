//
//  BoxRenderer.cpp
//  SushiHero
//
//  Created by Colin Duffy on 5/21/13.
//
//

#include "BoxRenderer.h"

#ifdef COCOS2D_VERSION
using namespace cocos2d;
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

USING_NS_CC;

void BoxRenderer::initShader( void ) {
	mShaderProgram = CCShaderCache::sharedShaderCache()->programForKey(kCCShader_Position_uColor);
	mColorLocation = glGetUniformLocation( mShaderProgram->getProgram(), "u_color");
}
#endif

b2Vec2* BoxRenderer::createCircle(const b2Vec2& center, float32 radius) {
	b2Vec2* vertices = new b2Vec2[CIRCLE_SEGMENTS];
	float ang;
	for(int i = 0; i < CIRCLE_SEGMENTS; ++i) {
		ang = ((float)i / (float)CIRCLE_SEGMENTS) * PI_2;
		vertices[i].x = cosf(ang) * radius + center.x;
		vertices[i].y = sinf(ang) * radius + center.y;
	}
	return vertices;
}

void BoxRenderer::drawShape(const b2Vec2* vertices, int32 vertexCount, const b2Color& color, bool fill) {
#ifdef COCOS2D_VERSION
	
#else
	glBegin(fill ? GL_TRIANGLE_FAN : GL_LINE_LOOP);
	glColor3f(color.r, color.g, color.b);
	for(int i = 0; i < vertexCount; ++i) glVertex2f(vertices[i].x, vertices[i].y);
	glEnd();
#endif
}

void BoxRenderer::DrawPolygon(const b2Vec2* old_vertices, int32 vertexCount, const b2Color& color) {
#ifdef COCOS2D_VERSION
	mShaderProgram->use();
    mShaderProgram->setUniformsForBuiltins();
	
    b2Vec2* vertices = new b2Vec2[vertexCount];
    for( int i=0;i<vertexCount;i++)
    {
        vertices[i] = old_vertices[i];
        vertices[i] *= mRatio;
    }
	
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r, color.g, color.b, 1);
	
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, vertices);
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
	
    CC_INCREMENT_GL_DRAWS(1);
	
    CHECK_GL_ERROR_DEBUG();
	
    delete[] vertices;
#else
	drawShape(old_vertices, vertexCount, color, false);
#endif
}

void BoxRenderer::DrawSolidPolygon(const b2Vec2* old_vertices, int32 vertexCount, const b2Color& color) {
#ifdef COCOS2D_VERSION
	mShaderProgram->use();
    mShaderProgram->setUniformsForBuiltins();
	
    b2Vec2* vertices = new b2Vec2[vertexCount];
    for( int i=0;i<vertexCount;i++) {
        vertices[i] = old_vertices[i];
        vertices[i] *= mRatio;
    }
    
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r*0.5f, color.g*0.5f, color.b*0.5f, 0.5f);
	
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, vertices);
	
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
	
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r, color.g, color.b, 1);
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
	
    CC_INCREMENT_GL_DRAWS(2);
	
    CHECK_GL_ERROR_DEBUG();
	
    delete[] vertices;
#else
	drawShape(old_vertices, vertexCount, color, true);
#endif
}

void BoxRenderer::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color) {
#ifdef COCOS2D_VERSION
	mShaderProgram->use();
    mShaderProgram->setUniformsForBuiltins();
	
    const float32 k_segments = 16.0f;
    int vertexCount=16;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    
    GLfloat*    glVertices = new GLfloat[vertexCount*2];
    for (int i = 0; i < k_segments; ++i)
    {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertices[i*2]=v.x * mRatio;
        glVertices[i*2+1]=v.y * mRatio;
        theta += k_increment;
    }
    
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r, color.g, color.b, 1);
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, glVertices);
	
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
	
    CC_INCREMENT_GL_DRAWS(1);
	
    CHECK_GL_ERROR_DEBUG();
	
    delete[] glVertices;
#else
	drawShape(createCircle(center, radius), CIRCLE_SEGMENTS, color, false);
#endif
}

void BoxRenderer::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color) {
#ifdef COCOS2D_VERSION
	mShaderProgram->use();
    mShaderProgram->setUniformsForBuiltins();
	
    const float32 k_segments = 16.0f;
    int vertexCount=16;
    const float32 k_increment = 2.0f * b2_pi / k_segments;
    float32 theta = 0.0f;
    
    GLfloat*    glVertices = new GLfloat[vertexCount*2];
    for (int i = 0; i < k_segments; ++i)
    {
        b2Vec2 v = center + radius * b2Vec2(cosf(theta), sinf(theta));
        glVertices[i*2]=v.x * mRatio;
        glVertices[i*2+1]=v.y * mRatio;
        theta += k_increment;
    }
    
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r*0.5f, color.g*0.5f, color.b*0.5f, 0.5f);
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, glVertices);
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount);
	
	
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r, color.g, color.b, 1);
    glDrawArrays(GL_LINE_LOOP, 0, vertexCount);
	
    // Draw the axis line
    DrawSegment(center,center+radius*axis,color);
	
    CC_INCREMENT_GL_DRAWS(2);
	
    CHECK_GL_ERROR_DEBUG();
	
    delete[] glVertices;
#else
	drawShape(createCircle(center, radius), CIRCLE_SEGMENTS, color, true);
#endif
}

void BoxRenderer::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) {
#ifdef COCOS2D_VERSION
	mShaderProgram->use();
    mShaderProgram->setUniformsForBuiltins();
	
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r, color.g, color.b, 1);
	
    GLfloat    glVertices[] =
    {
        p1.x * mRatio, p1.y * mRatio,
        p2.x * mRatio, p2.y * mRatio
    };
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, glVertices);
	
    glDrawArrays(GL_LINES, 0, 2);
	
    CC_INCREMENT_GL_DRAWS(1);
	
    CHECK_GL_ERROR_DEBUG();
#else
	glBegin(GL_LINES);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
#endif
}

void BoxRenderer::DrawTransform(const b2Transform& xf) {
#ifdef COCOS2D_VERSION
	b2Vec2 p1 = xf.p, p2;
    const float32 k_axisScale = 0.4f;
    p2 = p1 + k_axisScale * xf.q.GetXAxis();
    DrawSegment(p1, p2, b2Color(1,0,0));
	
    p2 = p1 + k_axisScale * xf.q.GetYAxis();
    DrawSegment(p1,p2,b2Color(0,1,0));
#else
	
#endif
}

void BoxRenderer::DrawPoint(const b2Vec2& p, float32 size, const b2Color& color) {
#ifdef COCOS2D_VERSION
	mShaderProgram->use();
    mShaderProgram->setUniformsForBuiltins();
	
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r, color.g, color.b, 1);
	
    GLfloat                glVertices[] = {
        p.x * mRatio, p.y * mRatio
    };
	
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, glVertices);
	
    glDrawArrays(GL_POINTS, 0, 1);
	
    CC_INCREMENT_GL_DRAWS(1);
	
    CHECK_GL_ERROR_DEBUG();
#else
	glBegin(GL_POINT);
	glColor3f(color.r, color.g, color.b);
	glVertex2f(p.x, p.y);
	glEnd();
#endif
}

void BoxRenderer::DrawString(int x, int y, const char* string, ...) {
	
}

void BoxRenderer::DrawAABB(b2AABB* aabb, const b2Color& color) {
#ifdef COCOS2D_VERSION
	mShaderProgram->use();
    mShaderProgram->setUniformsForBuiltins();
	
    mShaderProgram->setUniformLocationWith4f(mColorLocation, color.r, color.g, color.b, 1);
	
    GLfloat                glVertices[] = {
        aabb->lowerBound.x * mRatio, aabb->lowerBound.y * mRatio,
        aabb->upperBound.x * mRatio, aabb->lowerBound.y * mRatio,
        aabb->upperBound.x * mRatio, aabb->upperBound.y * mRatio,
        aabb->lowerBound.x * mRatio, aabb->upperBound.y * mRatio
    };
	
    glVertexAttribPointer(kCCVertexAttrib_Position, 2, GL_FLOAT, GL_FALSE, 0, glVertices);
    glDrawArrays(GL_LINE_LOOP, 0, 8);
	
    CC_INCREMENT_GL_DRAWS(1);
	
    CHECK_GL_ERROR_DEBUG();
#else
	
#endif
}
