//
//  ApolloGL.cpp
//  SingleViewApp
//
//  Created by Colin Duffy on 7/14/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#include "ApolloGL.h"
#include "ApolloMath.h"

#ifdef APOLLO_OPENFRAMEWORKS
#include "ofMain.h"
#endif

namespace Apollo {
	namespace gl {
		
		void fill()   { glSettings.fill = true; }
		void noFill() { glSettings.fill = false; }
		
		void enableSmooth() {
			glSettings.smooth = true;
#ifndef APOLLO_GLES
			glPushAttrib(GL_COLOR_BUFFER_BIT | GL_ENABLE_BIT);
#endif
			glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
			glEnable(GL_LINE_SMOOTH);
			glEnable(GL_BLEND);
		}
		
		void disableSmooth() {
			glSettings.smooth = false;
#ifndef APOLLO_GLES
			glDisable(GL_BLEND);
			glDisable(GL_LINE_SMOOTH);
			glPopAttrib();
#endif
		}
		
		void pushMatrix() { glPushMatrix(); }
		void popMatrix()  { glPopMatrix(); }
		
		void rotate (float degrees) { glRotatef(degrees, 0, 0, 1); }
		void rotateX(float degrees) { glRotatef(degrees, 1, 0, 0); }
		void rotateY(float degrees) { glRotatef(degrees, 0, 1, 0); }
		void rotateZ(float degrees) { rotate(degrees); }
		
		void scale(float amount) { scale(amount, amount, amount); }
		void scale(float x, float y, float z) { glScalef(x, y, z); }
		
		void translate(float x, float y, float z) { glTranslatef(x, y, z); }
		
#pragma mark - Primitives
		
		void drawLine(float x1, float y1, float x2, float y2) { drawLine(x1, y1, 0, x2, y2, 0); }
		
		void drawLine(float x1, float y1, float z1, float x2, float y2, float z2) {
			glSettings.linePts[0].set(x1, y1, z1);
			glSettings.linePts[1].set(x2, y2, z2);
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, sizeof(Vec3f), &glSettings.linePts[0].x);
			glDrawArrays(GL_LINES, 0, 2);
		}
		
		void drawRect(float x, float y, float w, float h) { drawRect(x, y, 0, w, h); }
		
		void drawRect(float x, float y, float z, float w, float h) {
			Vec2f offset = Vec2f::alignmentOffset(glSettings.alignment, w, h);
			
			float l = x + offset.x,
			t = y + offset.y,
			r = x + w + offset.x,
			b = y + h + offset.y;
			
			glSettings.rectPts[0].set(l, t, z);
			glSettings.rectPts[1].set(r, t, z);
			glSettings.rectPts[2].set(r, b, z);
			glSettings.rectPts[3].set(l, b, z);
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, sizeof(Vec3f), &glSettings.rectPts[0].x);
			glDrawArrays(glSettings.fill ? GL_TRIANGLE_FAN : GL_LINE_LOOP, 0, 4);
		}
		
		void drawCircle(float x, float y, float radius, int segments) { drawCircle(x, y, 0, radius, segments); }
		
		void drawCircle(float x, float y, float z, float radius, int segments) {
			const float halfRadius = radius * 0.5f;
			Vec2f offset = Vec2f::alignmentOffset(glSettings.alignment, radius, radius);
			
			float l = x + offset.x+halfRadius,
			t = y + offset.y+halfRadius,
			ang = 0,
			dis = 360.f / (float)segments;
			
			vector<Vec3f> circlePts;
			for(int i = 0; i < segments; ++i) {
				ang = toRad((float)i * dis + 90.f);
				circlePts.push_back( Vec3f( cos(ang) * halfRadius + l, sin(ang) * halfRadius + t, z ) );
			}
			
			glEnableClientState(GL_VERTEX_ARRAY);
			glVertexPointer(3, GL_FLOAT, sizeof(Vec3f), &circlePts[0].x);
			glDrawArrays(glSettings.fill ? GL_TRIANGLE_FAN : GL_LINE_LOOP, 0, segments);
			
			if(glSettings.smooth && glSettings.fill) glDrawArrays(GL_LINE_LOOP, 0, segments); // smooth edges
		}
		
		void drawText(string msg, float x, float y) {
#ifdef APOLLO_OPENFRAMEWORKS
			ofDrawBitmapString(msg, x, y);
#endif
		}
		
#pragma mark - Getters
		
		MatrixAlign getAlignment() { return glSettings.alignment; }
		
#pragma mark - Setters
		
		void setColor(float r, float g, float b, float a) { glColor4f(r / 255.f, g / 255.f, b / 255.f, a / 255.f); }
		void setColor(float brightness, float alpha) { setColor(brightness, brightness, brightness, alpha); }
		
		void setAlignment(MatrixAlign align) { glSettings.alignment = align; }
		
	}
}
