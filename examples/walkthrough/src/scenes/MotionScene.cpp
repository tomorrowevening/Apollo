//
//  MotionScene.cpp
//  ApolloTests
//
//  Created by Colin Duffy on 9/23/14.
//
//

#include "MotionScene.h"

MotionScene::MotionScene() {
	name = "Motion";
	//
	box = new MotionBox();
	box->position.set(150, ofGetHeight()/2, 0);
	addChild( box );
}

void MotionScene::update() {
	Scene::update();
	box->position.y = ofGetHeight()/2; // vertically centered
	loopAnimation();
}

void MotionScene::render() {
	ofPushMatrix();
	ofTranslate(0, 20);
	
	timeline.drawDebug();
	
	ofPopMatrix();
}

void MotionScene::loopAnimation() {
	int totalTime = 60 * 2;
	int elapsed = frameNum % totalTime;
	if(elapsed == 0) {
		animateRight();
	} else if(elapsed == totalTime-45) {
		animateLeft();
	}
}

void MotionScene::animateLeft() {
	CubicEase ease = CubicEase( 0.820, 0.115, 0.350, 0.945 );
	timeline.addTween(box->position.x, 150.0f, 0.5f, ease);
	timeline.addTween(box->rotation.z,   0.0f, 0.5f, ease);
}

void MotionScene::animateRight() {
	CubicEase ease = CubicEase( 0.920, 0.060, 0.250, 0.955 );
	timeline.addTween(box->position.x, ofGetWidth() - 150.0f, 1.0f, ease);
	timeline.addTween(box->rotation.z, 360.f, 1.0f, ease);
}
