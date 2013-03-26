//
//  DragBezier.h
//
//  Created by Colin Duffy on 3/25/13.
//
//

#pragma once
#include "DragPoint.h"
#include "Bezier.h"
#include "MathUtil.h"

class DragBezier : public ofRectangle {
private:
	
	Bezier bezier;
	
	void _update(ofEventArgs &e) { update(); }
	void _draw(ofEventArgs &e) { draw(); }
	
	void updateDrags() {
		float yOffset = y+height;
		bezier.setControl(0, (drag0.x-x) / width, (drag0.y-yOffset) / -height);
		bezier.setControl(1, (drag1.x-x) / width, (drag1.y-yOffset) / -height);
		bezier.setControl(2, (drag2.x-x) / width, (drag2.y-yOffset) / -height);
		bezier.setControl(3, (drag3.x-x) / width, (drag3.y-yOffset) / -height);
	}
	
public:
	
	DragPoint drag0, drag1, drag2, drag3;
	bool clampX, clampY;
	
	DragBezier() {
		clampX = false;
		clampY = false;
	}
	
	void setup(float x = 0.0f, float y = 0.0f, float width = 100.0f, float height = 100.0f) {
		this->x = x;
		this->y = y;
		this->width  = width;
		this->height = height;
		
		drag0.setup();
		drag1.setup();
		drag2.setup();
		drag3.setup();
		
		drag0.disableMouseEvents();
		drag3.disableMouseEvents();
		
		linear();
		update();
		
		ofAddListener(ofEvents().update, this, &DragBezier::_update);
		ofAddListener(ofEvents().draw, this, &DragBezier::_draw);
	}
	
	void linear() {
		float right  = x + width;
		float bottom = y + height;
		
		drag0.x = ofLerp(x, right,  0);
		drag0.y = ofLerp(bottom, y, 0);
		
		drag1.x = ofLerp(x, right,  0.333f);
		drag1.y = ofLerp(bottom, y, 0.333f);
		
		drag2.x = ofLerp(x, right,  0.667f);
		drag2.y = ofLerp(bottom, y, 0.667f);
		
		drag3.x = ofLerp(x, right,  1.f);
		drag3.y = ofLerp(bottom, y, 1.f);
		updateDrags();
	}
	
	void setX(float px) {
		float right  = px + width;
		drag0.x = px;
		drag1.x = ofLerp(px, right,  (drag1.x-x)/width);
		drag2.x = ofLerp(px, right,  (drag2.x-x)/width);
		drag3.x = right;
		x = px;
	}
	
    void setY(float py) {
		float bottom  = py + height;
		drag0.y = bottom;
		drag1.y = ofLerp(bottom, py, 1.f - ((drag1.y-y)/height));
		drag2.y = ofLerp(bottom, py, 1.f - ((drag2.y-y)/height));
		drag3.y = py;
		y = py;
	}
	
	void destroy() {
		ofRemoveListener(ofEvents().update, this, &DragBezier::_update);
		ofRemoveListener(ofEvents().draw, this, &DragBezier::_draw);
		drag0.killMe();
		drag1.killMe();
		drag2.killMe();
		drag3.killMe();
	}
	
	void update() {
		float prevD1X = drag1.x;
		float prevD1Y = drag1.y;
		
		float prevD2X = drag2.x;
		float prevD2Y = drag2.y;
		
		drag0._onUpdate();
		drag1._onUpdate();
		drag2._onUpdate();
		drag3._onUpdate();
		
		// Stop further calculations if there weren't any changes
		if(drag1.x == prevD1X && drag1.y == prevD1Y && drag2.x == prevD2X && drag2.y == prevD2Y) return;
		
		if(clampX) {
			float right  = x+width;
			drag1.x = ofClamp(drag1.x, x, right);
			drag2.x = ofClamp(drag2.x, x, right);
		}
		
		if(clampY) {
			float bottom = y+height;
			drag1.y = ofClamp(drag1.y, y, bottom);
			drag2.y = ofClamp(drag2.y, y, bottom);
		}
		
		updateDrags();
	}
	
	float getValue(float percent) {
		return bezier.getValue(percent);
	}
	
	void draw() {
		ofPushMatrix();
		ofTranslate(DRAG_POINT_SIZE_H, DRAG_POINT_SIZE_H);
		ofNoFill();
		ofSetColor(255, 204);
		ofRect(x, y, width, height);
		
		ofSetColor(255, 172);
		ofBezier(drag0.x, drag0.y,
				 drag1.x, drag1.y,
				 drag2.x, drag2.y,
				 drag3.x, drag3.y);
		
		ofSetColor(255, 102);
		ofLine(drag0.x, drag0.y, drag1.x, drag1.y);
		ofLine(drag2.x, drag2.y, drag3.x, drag3.y);
		ofPopMatrix();
		
		// Reset
		ofSetColor(255);
		ofFill();
		
		drag0.draw();
		drag1.draw();
		drag2.draw();
		drag3.draw();
	}
	
};
