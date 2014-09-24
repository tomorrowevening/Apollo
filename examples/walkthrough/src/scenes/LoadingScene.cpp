//
//  LoadingScene.cpp
//  ApolloTests
//
//  Created by Colin Duffy on 9/23/14.
//
//

#include "LoadingScene.h"

LoadingScene::LoadingScene() {
	name = "Loading";
	progress = 1;
}

void LoadingScene::render() {
	ofSetColor(255);
	progress   = cosRange(frameNum * 0.5f, 1.0, 0.0);
	string msg = "Loading: " + ofToString(progress * 100.0f, 0) + "%";
	ofDrawBitmapString(msg, ofGetWidth()/2-64, ofGetHeight()/2-4);
}
