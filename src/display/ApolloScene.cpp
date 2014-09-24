//
//  ApolloScene.cpp
//  Apollo
//
//  Created by Colin Duffy on 9/18/14.
//  Copyright (c) 2014 Tomorrow Evening. All rights reserved.
//

#include "ApolloScene.h"

namespace Apollo {
	
	const string Scene::SCENE_IN	= "Scene::SCENE_IN";
	const string Scene::SCENE_OUT	= "Scene::SCENE_OUT";
	
	Scene::Scene() {
		frameNum = 0;
		elapsedTime = 0;
		bShowing = false;
		state = Scene_Hidden;
	}

	Scene::~Scene() {
		
	}

	void Scene::show() {
		if(bShowing) return;
		visible = true;
		bShowing = true;
		frameNum = 0;
		elapsedTime = 0;
		showStart = getSystemMS();
		state = Scene_In;
		animateIn();
	}

	void Scene::hide() {
		if(!bShowing) return;
		state = Scene_Out;
		animateOut();
	}

	void Scene::update() {
		DisplayObject::update();
		++frameNum;
		elapsedTime = getSystemMS() - showStart;
	}

	#pragma mark Protected

	void Scene::animateIn() {
		animateInComplete();
	}

	void Scene::animateInComplete() {
		state = Scene_Idle;
		AnimationEvent aEvt = AnimationEvent(Scene::SCENE_IN, name);
		dispatchEvent( aEvt );
	}

	void Scene::animateOut() {
		animateOutComplete();
	}

	void Scene::animateOutComplete() {
		bShowing = false;
		state = Scene_Hidden;
		visible = false;
		AnimationEvent aEvt = AnimationEvent(Scene::SCENE_OUT, name);
		dispatchEvent( aEvt );
	}

}