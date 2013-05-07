#include "testApp.h"
#include "TweenController.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(32);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	
	btn.buttonID = "Click to Ease";
	btn.setRect(100, -30, 150, 30);
	btn.enable();
	btn.showBounds = true;
	ofAddListener(btn.CLICK, this, &testApp::btnHandler);
	
	Tweener.setPlaymode(Override);
	Tweener.addTween(btn.y, 100, 2.5f, EaseExpoOut, 1.5f);
	
	bezier.setup(100, 150, 200, 200);
	bezier.enableEvents();
}

void testApp::exit() {
	ofRemoveListener(btn.CLICK, this, &testApp::btnHandler);
	btn.disable();
	
	bezier.disableEvents();
}

//--------------------------------------------------------------
void testApp::update(){
	Tweener.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255);
	ofLine(btn.x, btn.y, target.x, target.y);
	ofDrawBitmapString("Control Button Ease", bezier.x, bezier.y - 10);
	btn.render();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

void testApp::btnHandler(string& btnID) {
	const float aniTime = 1.f;
	const CubicEase aniEase = bezier.getCurve();
	target.x = ofRandom(100, ofGetWidth() -100);
	target.y = ofRandom(100, ofGetHeight()-100);
	Tweener.addTween(btn.x, target.x, aniTime, aniEase);
	Tweener.addTween(btn.y, target.y, aniTime, aniEase);
	bezier.logCurve();
}