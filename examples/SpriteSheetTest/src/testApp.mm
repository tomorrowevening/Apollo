#include "testApp.h"
#include "StringUtil.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofxiPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
	ofSetCircleResolution(40);
	ofBackground(0, 0, 0);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	
	sheet.x = 50;
	sheet.y = 50;
	sheet.speed = 0.5;
	
	sheet.useTexture = true;
	sheet.load("smallAnimation/smallAnimation.png", 28, 6);
	
//	sheet.useTexture = false;
//	sheet.load("largeAnimation/largeAnimation_", 28, 6);
}

void testApp::exit() {
	sheet.dispose();
}


//--------------------------------------------------------------
void testApp::update(){
	sheet.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255);
	sheet.render();
	
	ofDrawBitmapString("FPS: " + ofToString(round(ofGetFrameRate())), 25, 25);
}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs &touch){
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs &touch){
	
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs &touch){
	
}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs &touch){

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs &touch){

}
