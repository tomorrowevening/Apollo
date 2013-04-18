#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(32);
	ofSetFrameRate(60);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	
	bez.setup(50, 200, 300, 300);
	bez.disableEvents();
	reset();
	
#ifdef OFXUI
	const int guiHei = 80;
	gui = new ofxUICanvas(bez.getX(), bez.getY() - guiHei, bez.getWidth(), guiHei);
	gui->addSlider("Duration", 0.25, 5.f, duration);
	gui->addSlider("Time", 0, 1, time);
	gui->setAutoDraw(false);
	gui->setAutoUpdate(false);
	gui->disableKeyEventCallbacks();
	ofAddListener(gui->newGUIEvent,this,&testApp::guiEvent);
#endif
}

#ifdef OFXUI

void testApp::exit() {
	ofRemoveListener(gui->newGUIEvent,this,&testApp::guiEvent);
	delete gui;
}

void testApp::guiEvent(ofxUIEventArgs &e) {
	string name = e.widget->getName();
	if(name == "Duration") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		duration = slider->getScaledValue();
	} else if(name == "Time") {
		ofxUISlider *slider = (ofxUISlider *) e.widget;
		time = slider->getScaledValue();
	}
}


void testApp::reposition() {
	gui->setPosition(bez.getX(), bez.getY() - gui->getHeight());
}

#endif

void testApp::reset() {
	duration = 1.f;
	time  = 0;
	playing = false;
	bez.linear();
	bez.setX(50);
	bez.setY(200);
	bez.resize(300, 300);
}

//--------------------------------------------------------------
void testApp::update(){
#ifdef OFXUI
	gui->update();
	reposition();
#endif
	
	if(playing) {
		time = ofClamp(1.f / (duration * 60.f) + time, 0, 1);
		if(time == 1) playing = false; // stop playing
	}
	
#ifdef OFXUI
	ofxUISlider *slider = (ofxUISlider *)gui->getWidget("Time");
	slider->setValue(time);
#endif
	
	bez.update();
}

//--------------------------------------------------------------
void testApp::draw(){
#ifdef OFXUI
	gui->draw();
#endif
	
	const float val = bez.getValue(time);
	ofRectangle bezValue = ofRectangle(bez.getX(), bez.getY(), val * bez.getWidth(), bez.getHeight());
	ofSetColor(160, 224, 255, 64);
	ofRect(bezValue);
	
	ofSetColor(255, 64);
	ofLine(bezValue.getRight(), bezValue.getY(), bezValue.getRight(), bezValue.getBottom());
	
	bez.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch(key) {
		case '0':
			time = 0;
			break;
		case '5':
			time = 0.5;
			break;
		case '1':
			time = 1;
			break;
			
		case ' ':
			if(!playing && time == 1) time = 0; //restart
			playing = !playing;
			break;
		case 'l':
			// Reset curve to linear
			bez.linear();
			break;
		case 'r':
			reset();
			break;
		case 's':
			bez.resize(round(ofRandom(100, 300)), round(ofRandom(100, 300)));
			break;
		case 'p':
			// Test repositioning bezier
			bez.setX(round(ofRandom(250)));
			bez.setY(round(ofRandom(250)));
			break;
	}
}
