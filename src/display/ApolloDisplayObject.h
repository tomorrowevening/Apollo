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
		virtual bool				hasChild(DisplayObject* obj);
		virtual int					getChildIndex(DisplayObject* obj);
		virtual void				removeChild(DisplayObject* obj);
		virtual void				removeChildAt(int index);
		
		// Getters
		
		// Position
		virtual const float			left()  { return position.x; }
		virtual const float			top()   { return position.y; }
		virtual const float			front() { return position.z; }
		virtual const float			right() { return left()  + size.x; }
		virtual const float			bottom(){ return top()   + size.y; }
		virtual const float			back()  { return front() + size.z; }
		
		// Size
		virtual const float			width()  { return size.x; }
		virtual const float			height() { return size.y; }
		virtual const float			depth()  { return size.z; }
		
		virtual const bool hitTest(float x, float y) {
			return Apollo::inRange(x, left(), right()) && Apollo::inRange(y, top(), bottom());
		}
		
		virtual const bool hitTest(Vec2f pos, Vec2f size) {
			float	vRight  = pos.x + size.x,
					vBottom = pos.y + size.y;
			bool overlapX =	Apollo::inRange(pos.x, left(), right()) || Apollo::inRange(pos.x+size.x, left(), right()) ||
							Apollo::inRange(left(), pos.x, vRight)  || Apollo::inRange(right(), pos.x, vRight);
			bool overlapY =	Apollo::inRange(pos.y, top(), bottom()) || Apollo::inRange(vBottom, top(), bottom()) ||
							Apollo::inRange(top(), pos.y, vBottom)  || Apollo::inRange(bottom(), pos.y, vBottom);
			return overlapX && overlapY;
		}
		
		virtual const bool hitTest(DisplayObject *dObj) {
			return this->hitTest(dObj->position, dObj->size);
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
