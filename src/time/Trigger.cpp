//
//  Trigger.cpp
//  Stripes
//
//  Created by Colin Duffy on 2/27/13.
//
//

#include "Trigger.h"

Trigger::Trigger() {
}

void Trigger::start() {
	if(running) return;
	
	running = true;
	ofAddListener(ofEvents().update, this, &Trigger::update);
}

void Trigger::end() {
	running = false;
	ofRemoveListener(ofEvents().update, this, &Trigger::update);
}

template <class T>
void Trigger::addCall(T* listener, void (T::*listenerMethod)(void), float ms) {
	CallbackClass trigger;
	trigger.total = (int)round(ms * 60.0f);
	trigger.addCallback(listener, listenerMethod);
	callbacks.push_back(trigger);
}

#pragma mark - Private

void Trigger::update(ofEventArgs &data) {
	if(!running) return;
	for(int i = getTotalTriggers(); i > -1; --i) {
		callbacks[i].update();
		if(callbacks[i].complete()) {
			printf("Trigger complete! %i\n", i);
			callbacks[i].call();
			callbacks.erase(callbacks.begin() + i);
			if(getTotalTriggers() == 0) {
				printf("Triggers complete!\n");
				end();
			}
		}
	}
}
