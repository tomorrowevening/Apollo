#pragma once
#include "ofMain.h"
#include "Apollo.h"

// Scenes
#include "LoadingScene.h"
#include "MotionScene.h"

class ofApp : public ofBaseApp,
public EventHandler {
public:
	
	// Apollo
	OFDispatcher			dispatcher;
	Stage					stage;
	
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	virtual void evtHandler(Event *event);
	
	void setupStage();
	void setupNav();
	void setupSections();
		
};
