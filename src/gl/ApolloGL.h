//
//  ApolloGL.h
//  SingleViewApp
//
//  Created by Colin Duffy on 7/14/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloGLEnum.h"
#include "ApolloMath.h"
#include "ApolloVec.h"

namespace Apollo {
	namespace gl {
		
		using namespace Apollo;
		using namespace std;
		
		class ApolloGLSettings {
		public:
			
			MatrixAlign		alignment;
			bool			fill, smooth;
			
			Vec3f			linePts[1];
			Vec3f			rectPts[3];
			
			ApolloGLSettings() {
				alignment		= ALIGN_TOP_LEFT;
				fill			= true;
				smooth			= false;
				
				linePts[0].set(0, 0, 0);
				linePts[1].set(1, 1, 0);
				
				rectPts[0].set(0, 0, 0);
				rectPts[1].set(1, 0, 0);
				rectPts[2].set(0, 1, 0);
				rectPts[3].set(1, 1, 0);
			}
		};
		
		static ApolloGLSettings glSettings;
		
		void fill();
		void noFill();
		
		void enableAlpha();
		void enableDepth();
		void enableDepthMask();
		void enableSmooth();
		void disableAlpha();
		void disableDepth();
		void disableDepthMask();
		void disableSmooth();
		
		void pushMatrix();
		void popMatrix();
		
		void rotate(float degrees);
		void rotate(Vec3f amount);
		void rotateX(float degrees);
		void rotateY(float degrees);
		void rotateZ(float degrees);
		void scale(float amount);
		void scale(float x, float y, float z = 1.f);
		void scale(Vec3f amount);
		void translate(float x, float y, float z = 0);
		void translate(Vec3f amount);
		
		void drawLine(float x1, float y1, float x2, float y2);
		void drawLine(float x1, float y1, float z1, float x2, float y2, float z2);
		void drawLine(Vec2f a, Vec2f b);
		void drawLine(Vec3f a, Vec3f b);
		void drawRect(float x, float y, float w, float h);
		void drawRect(float x, float y, float z, float w, float h);
		void drawRect(Vec3f pos, Vec3f size);
		void drawCircle(float x, float y, float z, float radius, int segments = 36, float rotationOffset = 90.f);
		void drawCircle(Vec3f pos, float radius, int segments = 36, float rotationOffset = 90.f);
		void drawText(string msg, float x, float y);
		void drawText(string msg, Vec3f pos);
		
		void setColorGL(float r, float g, float b, float a = 1.f);
		void setColorGL(float brightness, float a = 1.f);
		void setColor(float r, float g, float b, float a = 255.f);
		void setColor(float brightness, float alpha = 255.f);
		void setColor(Vec3f col);
		
		void setAlignment(MatrixAlign align);
		MatrixAlign getAlignment();
		
	}
}


