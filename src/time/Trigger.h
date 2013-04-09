//
//  Trigger.h
//  This class needs work...
//
//  Created by Colin Duffy on 2/27/13.
//
//

#pragma once

#include "ofMain.h"
#include <tr1/functional>

class CallbackClass {
public:
	
	int count, total;
	std::tr1::function<void(void)> callback;
	
	template <class T>
	void addCallback(T* listener, void (T::*listenerMethod)(void)) {
		callback = std::tr1::bind(listenerMethod, listener);
	}
	
	void call() {
		callback();
	}
	
	void update() {
		++count;
	}
	
	bool complete() {
		return count >= total;
	}
	
};

class Trigger {
private:
	
	void update(ofEventArgs &data);
	
public:
	
	bool running;
	
	vector<CallbackClass> callbacks;
	
	Trigger();
	void start();
	void end();
	
	template <class T>
	void addCall(T* listener, void (T::*listenerMethod)(void), float ms);
	
	int getTotalTriggers() { return (int)callbacks.size(); }
	
};
