//
//  TweenController.cpp
//  Created by Colin Duffy on 5/6/13.
//
//

#include "TweenController.h"

#ifdef OF_VERSION_MAJOR
#include "ofMain.h"
#endif

namespace Apollo {

	TweenController Tweener;

	void TweenController::update() {
		const bool sequenceAnis = !overrideTween();
		float aniPercent;
		for(int i = tweens.size() -1; i >= 0; --i){
			aniPercent = float(tweens[i].timestamp.elapsed()) / float(tweens[i].duration);
			if(aniPercent >= 1.f){
				tweens[i].var[0] = tweens[i].to;
				removeTween(i);
			} else if(aniPercent > 0){
				tweens[i].update(aniPercent);
			}
		}
	}
	
	void TweenController::drawDebug() {
#ifdef OF_VERSION_MAJOR
		
		ofSetColor(255);
		ofDrawBitmapString("Total tweens: " + Apollo::toString(totalTweens()), 25, 25);
#endif
	}

	//////////////////////////////////////////////////
	#pragma mark - Management
	//////////////////////////////////////////////////

	void TweenController::addTween(float &var, float to, float time, CubicEase ease, float delay) {
		addTween(var, to, time, ease.c0.x, ease.c0.y, ease.c1.x, ease.c1.y, delay);
	}
	
	void TweenController::addTween(float &var, float to, float time, PennerEases ease, float delay) {
		CubicEase tEase = Tween::getEase(ease);
		addTween(var, to, time, tEase.c0.x, tEase.c0.y, tEase.c1.x, tEase.c1.y, delay);
	}

	void TweenController::addTween(float &var, float to, float time, vec2f c0, vec2f c1, float delay) {
		addTween(var, to, time, c0.x, c0.y, c1.x, c1.y, delay);
	}

	void TweenController::addTween(float &var, float to, float time, float x0, float y0, float x1, float y1, float delay) {
		float from = var;
		float _delay = delay;
		Poco::Timestamp latest = 0;
		
		const int total = totalTweens();
		const bool override = overrideTween();
		for(int i = 0; i < total; ++i){
			if(tweens[i].var == &var) {
				if(override){
					tweens[i].from = from;
					tweens[i].to = to;
					tweens[i].setEase(x0, y0, x1, y1);
					tweens[i].timestamp = Poco::Timestamp() + (delay * 1000000.0f);
					tweens[i].duration = time * 1000000.0f;
					return;
				} else {
					//sequence mode
					if((tweens[i].timestamp + tweens[i].duration) > latest){
						latest = (tweens[i].timestamp + tweens[i].duration);
						delay = _delay + ((tweens[i].duration - tweens[i].timestamp.elapsed())/1000000.0f);
						from = tweens[i].to;
					}
				}
			}
		}
		
		Tween t;
		t.var = &var;
		t.from = from;
		t.to = to;
		t.setEase(x0, y0, x1, y1);
		t.timestamp = Poco::Timestamp() + (delay * 1000000.0f) ;
		t.duration = time * 1000000.0f;
		tweens.push_back(t);
	}

	void TweenController::removeTween(int index) {
		tweens.erase(tweens.begin() + index);
	}

	void TweenController::removeTween(float &var) {
		for(int i = totalTweens()-1; i > -i; --i) if(tweens[i].var == &var) removeTween(i);
	}

	void TweenController::removeAllTweens() { tweens.clear(); }

	//////////////////////////////////////////////////
	#pragma mark - Getters
	//////////////////////////////////////////////////

	int TweenController::totalTweens() { return (int)tweens.size(); }

	//////////////////////////////////////////////////
	#pragma mark - Setters
	//////////////////////////////////////////////////

	void TweenController::setPlaymode(Playmode playMode) { this->playMode = playMode; }

}