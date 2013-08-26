//
//  CocosScene.h
//  SushiHero
//
//  Created by Colin Duffy on 5/21/13.
//
//

#pragma once
#include "Apollo.h"
#ifdef APOLLO_COCOS2D
#include "cocos2d.h"
using namespace cocos2d;
#endif

using namespace Apollo;
#ifdef APOLLO_COCOS2D
using namespace cocos2d;
#endif

class ApolloCocosApp
#ifdef APOLLO_COCOS2D
: public CCLayer
#endif
{
public:
	
	ApolloCocosApp();
	~ApolloCocosApp();
	
	virtual bool init();
	virtual void onExit();
	virtual void update(float dt);
	virtual void draw();
	
#ifdef APOLLO_COCOS2D
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
	
	static CCScene* scene();
#endif
};