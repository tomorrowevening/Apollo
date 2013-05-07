//
//  TweenController.h
//  An extended/cleaned up version of ofxTweener
//  https://github.com/hautetechnique/ofxTweener/
//  Created by Colin Duffy on 5/6/13.
//

#pragma once
#include "Apollo.h"
#include "Tween.h"

namespace Apollo {

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
		void addTween(float &var, float to, float time, CustomEase ease,	float delay = 0.f);
		void addTween(float &var, float to, float time, PennerEases ease,   float delay = 0.f);
		void addTween(float &var, float to, float time, vec2f c0, vec2f c1, float delay = 0.f);
		void addTween(float &var, float to, float time, float x0, float y0, float x1, float y1, float delay = 0.f);
		void removeTween(float &var);
		void removeAllTweens();
		
		// Getters
		int totalTweens();
		
		// Setters
		void setPlaymode(Playmode playMode);
		
	private:
		Playmode playMode;
		std::vector<Tween> tweens;
		const bool overrideTween() { return playMode == Override; }
		void removeTween(int index);
	};

	extern TweenController Tweener;
	
}
