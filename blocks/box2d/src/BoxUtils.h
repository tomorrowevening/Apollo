//
//  BoxUtils.h
//  BoxEngine
//
//  Created by Colin Duffy on 4/27/13.
//
//

#pragma once

// Vector
#include <vector>
#include "Box2d.h"

class BoxUtil {
public:
	
	static void clearFixtures(b2Body* body) {
		if(body == NULL) return;
		for(b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext()) body->DestroyFixture(f);
	}
	
	static const std::vector<b2Vec2> getVertices(b2Body* body) {
		std::vector<b2Vec2> pts;
		b2Shape *shape = body->GetFixtureList()->GetShape();
		if( shape->GetType() == b2Shape::e_polygon ) {
			b2PolygonShape *poly = (b2PolygonShape*)shape;
			
			int count = poly->GetVertexCount();
			b2Vec2* verts = (b2Vec2*) poly->m_vertices;
			
			for( int i = 0; i < count; i++ ) pts.push_back(body->GetWorldPoint(verts[i]));
		}
		return pts;
	}
	
};
