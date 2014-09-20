//
//  ApolloSceneController.cpp
//  Apollo
//
//  Created by Colin Duffy on 9/18/14.
//
//

#include "ApolloSceneController.h"

SceneController::SceneController() {
	activeScene	= NULL;
	nextScene	= NULL;
}

SceneController::~SceneController() {
//	activeScene	= NULL;
//	nextScene	= NULL;
}

void SceneController::showScene(string name) {
//	int index = getChildIndex(name);
//	if(index < 0) return;
//	nextScene = (Scene*)children[index];
//	
//	if(activeScene != NULL) hideCurrentScene();
//	else showNextScene();
}

void SceneController::hideScene(string name) {
//	int index = getChildIndex(name);
//	if(index < 0) return;
//	
//	if(activeScene != NULL && activeScene->name == name) {
//		hideCurrentScene();
//	} else {
//		Stage::hideChild(name);
//	}
}

void SceneController::evtHandler(Event *evt) {
//	const string eType = evt->type;
//	if(eType == Scene::SCENE_OUT) {
//		activeScene->removeListener(Scene::SCENE_OUT, this);
//		activeScene = NULL;
//		//
//		if(nextScene != NULL) showNextScene();
//	}
}

#pragma mark Protected

void SceneController::showNextScene() {
//	activeScene = nextScene;
//	nextScene = NULL;
//	//
//	activeScene->show();
}

void SceneController::hideCurrentScene() {
//	activeScene->addListener(Scene::SCENE_OUT, this);
//	activeScene->hide();
}
