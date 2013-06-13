//
//  CocosScene.cpp
//  SushiHero
//
//  Created by Colin Duffy on 5/21/13.
//
//

#include "ApolloCocosApp.h"
#include "Apollo.h"

using namespace Apollo;

ApolloCocosApp::ApolloCocosApp() {
#ifdef COCOS2D_VERSION
	setTouchEnabled(true);
	setAccelerometerEnabled(true);
	scheduleUpdate();
#endif
}

ApolloCocosApp::~ApolloCocosApp() {
	
}

bool ApolloCocosApp::init() {
	printf("ApolloCocosApp inited\n");
#ifdef COCOS2D_VERSION
	return CCLayer::init();
#else
	return true;
#endif
}

void ApolloCocosApp::onExit() {
#ifdef COCOS2D_VERSION
	CCLayer::onExit();
#else
#endif
}

void ApolloCocosApp::update(float dt) {
	Dispatcher.dispatchEvent(new AppEvent(AppEvent::UPDATE));
}

void ApolloCocosApp::draw() {
#ifdef COCOS2D_VERSION
	CCLayer::draw();
#endif
	Dispatcher.dispatchEvent(new AppEvent(AppEvent::DRAW));
}

#ifdef COCOS2D_VERSION
void ApolloCocosApp::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent) {
	for(CCSetIterator it = pTouches->begin(); it != pTouches->end(); ++it) {
		CCTouch* t = (CCTouch*)(*it);
		CCPoint pos = t->getLocation();
		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::DOWN, pos.x, pos.y, t->getID()));
	}
}

void ApolloCocosApp::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent) {
	for(CCSetIterator it = pTouches->begin(); it != pTouches->end(); ++it) {
		CCTouch* t = (CCTouch*)(*it);
		CCPoint pos = t->getLocation();
		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::MOVE, pos.x, pos.y, t->getID()));
	}
}

void ApolloCocosApp::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent) {
	for(CCSetIterator it = pTouches->begin(); it != pTouches->end(); ++it) {
		CCTouch* t = (CCTouch*)(*it);
		CCPoint pos = t->getLocation();
		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::UP, pos.x, pos.y, t->getID()));
	}
}

void ApolloCocosApp::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent) {
	for(CCSetIterator it = pTouches->begin(); it != pTouches->end(); ++it) {
		CCTouch* t = (CCTouch*)(*it);
		CCPoint pos = t->getLocation();
		Dispatcher.dispatchEvent(new TouchEvent(TouchEvent::CANCEL, pos.x, pos.y, t->getID()));
	}
}


CCScene* ApolloCocosApp::scene() {
	CCScene *scene = CCScene::create();
	CCLayer* layer = new ApolloCocosApp();
	scene->addChild(layer);
	layer->release();
	return scene;
}
#endif