#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofBackground(32);
	ofEnableAlphaBlending();
	
	bez.setup(50, 50, 300, 300);
}

//--------------------------------------------------------------
void testApp::update(){
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key) {
		case ' ':
			// Check bezier values
			float percent;
			for(int i = 0; i < 11; ++i) {
				percent = (float)i / 10.0f;
				printf("%f: %f\n", percent, bez.getValue(percent));
			}
		break;
		case 'l':
			// Reset curve to linear
			bez.linear();
		break;
		case 'p':
			// Test repositioning bezier
			bez.setX(round(ofRandom(250)));
			bez.setY(round(ofRandom(250)));
		break;
	}
}

