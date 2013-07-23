//
//  ApolloDisplayObject.cpp
//  Apollo
//  Created by Colin Duffy on 7/22/13.
//  Copyright (c) 2013 Tomorrow Evening. All rights reserved.
//

#include "ApolloDisplayObject.h"

namespace Apollo {
	
	int DisplayObject::displayObjectCount = 0;
	
	DisplayObject::DisplayObject() {
		this->name = "Apollo::DisplayObject::" + toString(DisplayObject::displayObjectCount);
		this->snapshot = false;
		this->visible  = true;
		this->alpha = 1.f;
		this->anchor.set(0, 0, 0);
		this->position.set(0, 0, 0);
		this->rotation.set(0, 0, 0);
		this->scale.set(1, 1, 1);
		this->size.set(0, 0, 0);
		this->parent = NULL;
		
		++DisplayObject::displayObjectCount;
	}
	
	void DisplayObject::setup() {}
	
	void DisplayObject::dispose() {
		parent = NULL;
		screenshot.dispose();
		
		int i, total = numChildren()-1;
		for(i = total; i > -1; --i) children[i]->dispose();
		children.clear();
	}
	
	void DisplayObject::update() {
		updateChildren();
	}
	
	void DisplayObject::drawBounds() {
		gl::noFill();
		gl::setColorGL(1.f, 0, 0);
		gl::drawRect(Vec3f(), size);
		gl::setColorGL(1.f);
		gl::fill();
	}
	
	void DisplayObject::updateChildren() {
		int i, total = numChildren();
		for(i = 0; i < total; ++i) children[i]->update();
	}
	
	void DisplayObject::drawChildren() {
		sort(children.begin(), children.end());
		int i, total = numChildren();
		for(i = 0; i < total; ++i) children[i]->draw();
	}
	
	void DisplayObject::draw() {
		if(!visible || alpha <= 0) return;
		
		gl::pushMatrix();
		
		gl::translate(position);
		gl::rotate(rotation);
		gl::scale(scale);
		gl::translate(-anchor);
		gl::setColorGL(1.f, opacity());
		
		if(snapshot) {
			screenshot.draw();
		} else {
			render();
		}
		
#ifdef APOLLO_DEBUG
		drawBounds();
#endif
		
		// Layers
		drawChildren();
		gl::popMatrix();
	}
	
	void DisplayObject::addView(DisplayObject* obj) {
		obj->parent = this;
		children.push_back( obj );
	}
	
	void DisplayObject::removeView(DisplayObject* obj) {
		int i, index = -1, total = numChildren();
		for(i = 0; i < total; ++i) {
			if(children[i] == obj) {
				index = i;
				removeViewAt(index);
				return;
			}
		}
	}
	
	void DisplayObject::removeViewAt(int index) {
		children[index]->dispose();
		children.erase( children.begin() + index );
	}
	
	
}
