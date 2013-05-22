//
//  CocosScene.h
//  SushiHero
//
//  Created by Colin Duffy on 5/21/13.
//
//

#pragma once

#include "cocos2d.h"
using namespace cocos2d;

class ApolloCocosApp :
#ifdef COCOS2D_VERSION
public CCLayer
#endif
{
public:
	
	ApolloCocosApp();
	~ApolloCocosApp();
	
	virtual bool init();
	virtual void onExit();
	virtual void update(float dt);
	virtual void draw();
	
#ifdef COCOS2D_VERSION
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
	
	static CCScene* scene();
#endif
};