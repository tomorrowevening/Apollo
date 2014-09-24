//
//  LoadingScene.h
//  ApolloTests
//
//  Created by Colin Duffy on 9/23/14.
//
//

#pragma once
#include "Apollo.h"

class LoadingScene : public Scene {
public:
	
	float			progress;
	
	LoadingScene();
	
protected:
	
	virtual void render();
	
};
