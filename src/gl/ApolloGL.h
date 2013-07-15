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
			bool			fill;
			
			Vec3f			linePts[1];
			Vec3f			rectPts[3];
			
			ApolloGLSettings() {
				alignment		= ALIGN_TOP_LEFT;
				fill			= true;
				
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
		
		void enableSmooth();
		void disableSmooth();
		
		void pushMatrix();
		void popMatrix();
		
		void drawLine(float x1, float y1, float x2, float y2);
		void drawLine(float x1, float y1, float z1, float x2, float y2, float z2);
		void drawRect(float x, float y, float w, float h);
		void drawRect(float x, float y, float z, float w, float h);
		void drawCircle(float x, float y, float radius, int segments = 36);
		void drawCircle(float x, float y, float z, float radius, int segments = 36);
		void drawText(string msg, float x, float y);
		
		void setColor(float r, float g, float b, float a = 255.f);
		void setColor(float brightness, float alpha = 255.f);
		
		void setAlignment(MatrixAlign align);
		MatrixAlign getAlignment();
		
	}
}


