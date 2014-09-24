//
//  MotionScene.h
//  ApolloTests
//
//  Created by Colin Duffy on 9/23/14.
//
//

#include "Apollo.h"

class MotionBox : public DisplayObject {
public:
	
	MotionBox() {
		size.set(100, 100, 0);
	}
	
protected:
	
	virtual void render() {
		ofPushMatrix();
		ofTranslate(size.x * -0.5f, size.y * -0.5f);
		
		ofSetColor(255);
		ofRect(0, 0, size.x, size.y);
		
		ofPopMatrix();
	}
	
};

//////////////////////////////////////////////////

class MotionScene : public Scene {
public:
	
	MotionBox			*box;
	
	MotionScene();
	virtual void update();
	
protected:
	
	virtual void render();
	
	void loopAnimation();
	void animateLeft();
	void animateRight();
	
};
