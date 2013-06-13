//
//  TweenController.h
//  Apollo
//  An extended/cleaned up version of ofxTweener
//  https://github.com/hautetechnique/ofxTweener/
//  Created by Colin Duffy on 5/6/13.
//

#pragma once
#include "ApolloCore.h"
#include "ApolloTime.h"
#include "ApolloTween.h"

namespace Apollo {
	
	using namespace std;
	using namespace Apollo;

	typedef enum {
		Sequence = 0,
		Override
	} Playmode;

	class TweenController {
	public:
		
		TweenController() { playMode = Sequence; }
		~TweenController(){ removeAllTweens(); }
		
		void update();
		void drawDebug();
		
		// Management
		void addTween(float &var, float to, float time, CubicEase ease,	float delay = 0.f);
		void addTween(float &var, float to, float time, PennerEases ease,   float delay = 0.f);
		void addTween(float &var, float to, float time, Vec2f c0, Vec2f c1, float delay = 0.f);
		void addTween(float &var, float to, float time, float x0, float y0, float x1, float y1, float delay = 0.f);
		void removeTween(float &var);
		void removeAllTweens();
		
		// Getters
		int activeTweens();
		int totalTweens();
		
		// Setters
		void setPlaymode(Playmode playMode);
		
	private:
		Playmode playMode;
		int _activeTweens;
		std::vector<Tween> tweens;
		const bool overrideTween() { return playMode == Override; }
		void removeTween(int index);
	};

	extern TweenController Tweener;
	
}
