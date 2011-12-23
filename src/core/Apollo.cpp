//
//  DUFF.cpp
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#include <iostream>
#include "Apollo.h"

Apollo* Apollo::_instance = NULL;

Apollo* Apollo::instance(){
	if(_instance == NULL){
		_instance = new Apollo();
	}
	return _instance;
}

Apollo::Apollo(){
	
}

void Apollo::update() {
	
}
