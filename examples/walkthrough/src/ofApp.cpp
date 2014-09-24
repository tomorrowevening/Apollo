#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackgroundHex(0x202020);
	ofSetFrameRate(60);
	//
	setupStage();
}

//--------------------------------------------------------------
void ofApp::update() {
	Motion.update();
	stage.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	stage.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'f') {
		ofToggleFullscreen();
	}
}

void ofApp::evtHandler(Event *event) {
	const string eType = event->type;
	if(eType == Button::CLICK) {
		Button *btn = (Button*)event->getDispatcher();
		const string eName = btn->name;
		printf("Show section: %s\n", eName.c_str());
		stage.showScene( eName );
	}
}

//

void ofApp::setupStage() {
	setupSections();
	setupNav();
}

void ofApp::setupNav() {
	DisplayObject *nav = new DisplayObject();
	nav->position.set(5, 5, 0);
	stage.addChild(nav);
	nav->visible = true;
	
	Button *btnLoading = new Button();
	btnLoading->name = "Loading";
	btnLoading->setup(0, 0, 150, 20);
	btnLoading->enable();
	btnLoading->addListener(Button::CLICK, this);
	nav->addChild(btnLoading);
	
	Button *btnMotion = new Button();
	btnMotion->name = "Motion";
	btnMotion->setup(btnLoading->right() + 20, 0, 150, 20);
	btnMotion->enable();
	btnMotion->addListener(Button::CLICK, this);
	nav->addChild(btnMotion);
}

void ofApp::setupSections() {
	stage.addChild( new LoadingScene() );
	stage.addChild( new MotionScene() );
	//
	stage.showScene("Loading");
}
