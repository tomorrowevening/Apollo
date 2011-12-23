//
//  DUFF.h
//
//  Created by Colin Duffy on 10/22/11.
//  Copyright (c) 2011 Tomorrow Evening. All rights reserved.
//

#pragma once

class Apollo {
public:
	static Apollo*	instance();
	void			update();
private:
	Apollo();
	static Apollo*	_instance;
};
