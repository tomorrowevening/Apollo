//
//  DragPoint.h
//  Apollo
//  Created by Colin Duffy on 3/25/13.
//

#pragma once
#include "Apollo.h"
#include "Button.h"

namespace Apollo {
	
	#define DRAG_POINT_SIZE		14.0f
	
	class DragPoint : public Button {
	public:
		
		DragPoint() {
			alignment = ALIGN_MID_CENTER;
			setWidth(DRAG_POINT_SIZE);
			setHeight(DRAG_POINT_SIZE);
			draggable = true;
		}
		
	};
}
