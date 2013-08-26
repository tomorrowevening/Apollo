//
//  ApolloDisplayObject.h
//  Apollo
//  Created by Colin Duffy on 7/22/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloGL.h"
#include "ApolloFBO.h"
#include "ApolloStrings.h"
#include "ApolloVec.h"

using namespace std;
using namespace Apollo;

namespace Apollo {
	
	class DisplayObject {
	public:
		
		string						name;
		bool						snapshot, visible;
		Vec3f						anchor, position, rotation, scale, size;
		float						alpha;
		int							zIndex;
		DisplayObject*				parent;
		vector<DisplayObject*>		children;
		
		DisplayObject();
		virtual ~DisplayObject() {	dispose(); }
		
		virtual void				setup();
		virtual void				dispose();
		virtual void				update();
		virtual void				draw();
		virtual void				drawBounds();
		
		virtual void				addChild(DisplayObject* obj);
		virtual void				removeChild(DisplayObject* obj);
		virtual void				removeChildAt(int index);
		
		// Getters
		
		// Position
		const float					left()  { return position.x; }
		const float					top()   { return position.y; }
		const float					front() { return position.z; }
		
		// Size
		const float					width()  { return size.x; }
		const float					height() { return size.y; }
		const float					depth()  { return size.z; }
		
		const float					right()  { return position.x + size.x; }
		const float					bottom() { return position.y + size.y; }
		const float					back()   { return position.z + size.z; }
		
		const bool hitTest(float x, float y) {
			return Apollo::inRange(x, position.x, right()) && Apollo::inRange(y, position.y, bottom());
		}
		
		const int numChildren() {
			return (int)children.size();
		}
		
		const float opacity() {
			if(parent) return alpha * parent->alpha;
			return alpha;
		}
		
		const float opacityHex() { return opacity() * 255.f; }
		
		// Setters
		
	protected:
		
		gl::FBO						screenshot;
		
		virtual void				updateChildren();
		virtual void				drawChildren();
		virtual void				render() {}
		
	private:
		
		static int					displayObjectCount;
		bool operator<(const DisplayObject& val) const { return zIndex < val.zIndex; }
		
	};
	
}
