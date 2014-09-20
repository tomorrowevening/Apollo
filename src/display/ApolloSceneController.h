//
//  ApolloSceneController.h
//  Apollo
//
//  Created by Colin Duffy on 9/18/14.
//
//

#pragma once
#include "ApolloStage.h"
//#include "ApolloScene.h"

using namespace Apollo;

class SceneController : public Stage {
public:
	
	SceneController();
	virtual ~SceneController();
	
	virtual void showScene(string name);
	virtual void hideScene(string name);
	
	// Handlers
	
	virtual void evtHandler(Event *evt);
	
protected:
	
	Scene				*activeScene, *nextScene;
	
	virtual void showNextScene();
	virtual void hideCurrentScene();
	
};
