//
//  ApolloVec.cpp
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#include "ApolloVec.h"

namespace Apollo {
	
	//////////////////////////////////////////////////
	#pragma mark - Vec2
	//////////////////////////////////////////////////
	
	Vec2f::Vec2f(const Vec3f& v) {
		x = v.x;
		y = v.y;
	}
	
	Vec2f Vec2f::range(float minX, float maxX, float minY, float maxY, float per) {
		return Vec2f(Apollo::lerp(per, minX, maxX), Apollo::lerp(per, minY, maxY));
	}
	
	Vec2f Vec2f::randomRange(float minX, float maxX, float minY, float maxY) {
		return Vec2f(Apollo::randomRange(minX, maxX), Apollo::randomRange(minY, maxY));
	}
	
	Vec2f Vec2f::random(float maxX, float maxY) {
		return Vec2f(Apollo::random(maxX), Apollo::random(maxY));
	}
	
	Vec2f Vec2f::alignmentOffset(MatrixAlign align, float x, float y) {
		Vec2f offset;
		switch (align) {
			default:
			case ALIGN_TOP_LEFT:	offset.set(0,			0);			break;
			case ALIGN_TOP_CENTER:	offset.set(-x * 0.5f,	0);			break;
			case ALIGN_TOP_RIGHT:	offset.set(-x,			0);			break;
				
			case ALIGN_MID_LEFT:	offset.set(0,			-y*0.5f);	break;
			case ALIGN_MID_CENTER:	offset.set(-x * 0.5f,	-y*0.5f);	break;
			case ALIGN_MID_RIGHT:	offset.set(-x,			-y*0.5f);	break;
				
			case ALIGN_BOT_LEFT:	offset.set(0,			-y);		break;
			case ALIGN_BOT_CENTER:	offset.set(-x * 0.5f,	-y);		break;
			case ALIGN_BOT_RIGHT:	offset.set(-x,			-y);		break;
		}
		return offset;
	}
	
	#pragma mark Operators

	bool Vec2f::operator==( const Vec2f& vec ) const { return vec.x == x && vec.y == y; }
	bool Vec2f::operator!=( const Vec2f& vec ) const { return vec.x != x || vec.y != y; }

	Vec2f Vec2f::operator+( const Vec2f& vec ) const {
		return Vec2f( x+vec.x, y+vec.y);
	}

	Vec2f& Vec2f::operator+=( const Vec2f& vec ) {
		x += vec.x;
		y += vec.y;
		return *this;
	}

	Vec2f Vec2f::operator-( const Vec2f& vec ) const {
		return Vec2f(x-vec.x, y-vec.y);
	}

	Vec2f& Vec2f::operator-=( const Vec2f& vec ) {
		x -= vec.x;
		y -= vec.y;
		return *this;
	}

	Vec2f Vec2f::operator*( const Vec2f& vec ) const {
		return Vec2f(x*vec.x, y*vec.y);
	}

	Vec2f& Vec2f::operator*=( const Vec2f& vec ) {
		x*=vec.x;
		y*=vec.y;
		return *this;
	}

	Vec2f Vec2f::operator/( const Vec2f& vec ) const {
		return Vec2f( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y);
	}

	Vec2f& Vec2f::operator/=( const Vec2f& vec ) {
		vec.x!=0 ? x/=vec.x : x;
		vec.y!=0 ? y/=vec.y : y;
		return *this;
	}

	Vec2f Vec2f::operator+( const float f ) const {
		return Vec2f( x+f, y+f);
	}

	Vec2f& Vec2f::operator+=( const float f ) {
		x += f;
		y += f;
		return *this;
	}

	Vec2f Vec2f::operator-( const float f ) const {
		return Vec2f( x-f, y-f);
	}

	Vec2f& Vec2f::operator-=( const float f ) {
		x -= f;
		y -= f;
		return *this;
	}

	Vec2f Vec2f::operator-() const {
		return Vec2f(-x, -y);
	}

	Vec2f Vec2f::operator*( const float f ) const {
		return Vec2f(x*f, y*f);
	}

	Vec2f& Vec2f::operator*=( const float f ) {
		x*=f;
		y*=f;
		return *this;
	}

	Vec2f Vec2f::operator/( const float f ) const {
		if(f == 0) return Vec2f(x, y);
		
		return Vec2f(x/f, y/f);
	}

	Vec2f& Vec2f::operator/=( const float f ) {
		if(f == 0) return *this;
		
		x/=f;
		y/=f;
		return *this;
	}
	
	// Non-instance methods
	
	Vec2f operator+( float f, const Vec2f& vec ) {
		return Vec2f( f+vec.x, f+vec.y);
	}
	
	Vec2f operator-( float f, const Vec2f& vec ) {
		return Vec2f( f-vec.x, f-vec.y);
	}
	
	Vec2f operator*( float f, const Vec2f& vec ) {
		return Vec2f( f*vec.x, f*vec.y);
	}
	
	Vec2f operator/( float f, const Vec2f& vec ) {
		return Vec2f( f/vec.x, f/vec.y);
	}
	
	//////////////////////////////////////////////////
	#pragma mark - Vec3
	//////////////////////////////////////////////////
	
	Vec3f Vec3f::range(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, float per) {
		return Vec3f(Apollo::lerp(per, minX, maxX), Apollo::lerp(per, minY, maxY), Apollo::lerp(per, minZ, maxZ));
	}
	
	Vec3f Vec3f::randomRange(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
		return Vec3f(Apollo::randomRange(minX, maxX), Apollo::randomRange(minY, maxY), Apollo::randomRange(minZ, maxZ));
	}
	
	Vec3f Vec3f::random(float maxX, float maxY, float maxZ) {
		return Vec3f(Apollo::random(maxX), Apollo::random(maxY), Apollo::random(maxZ));
	}
	
	#pragma mark Operators
	
	bool Vec3f::operator==( const Vec3f& vec ) const { return vec.x == x && vec.y == y && vec.z == z; }
	bool Vec3f::operator!=( const Vec3f& vec ) const { return vec.x != x || vec.y != y || vec.z != z; }
	
	Vec3f Vec3f::operator+( const Vec3f& vec ) const {
		return Vec3f( x+vec.x, y+vec.y, z+vec.z);
	}
	
	Vec3f& Vec3f::operator+=( const Vec3f& vec ) {
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	
	Vec3f Vec3f::operator-( const Vec3f& vec ) const {
		return Vec3f(x-vec.x, y-vec.y, z-vec.z);
	}
	
	Vec3f& Vec3f::operator-=( const Vec3f& vec ) {
		x -= vec.x;
		y -= vec.y;
		z -= vec.z;
		return *this;
	}
	
	Vec3f Vec3f::operator*( const Vec3f& vec ) const {
		return Vec3f(x*vec.x, y*vec.y, z*vec.z);
	}
	
	Vec3f& Vec3f::operator*=( const Vec3f& vec ) {
		x*=vec.x;
		y*=vec.y;
		z*=vec.z;
		return *this;
	}
	
	Vec3f Vec3f::operator/( const Vec3f& vec ) const {
		return Vec3f( vec.x!=0 ? x/vec.x : x, vec.y!=0 ? y/vec.y : y, vec.z!=0 ? z/vec.z : z);
	}
	
	Vec3f& Vec3f::operator/=( const Vec3f& vec ) {
		vec.x!=0 ? x/=vec.x : x;
		vec.y!=0 ? y/=vec.y : y;
		vec.z!=0 ? z/=vec.z : z;
		return *this;
	}
	
	Vec3f Vec3f::operator+( const float f ) const {
		return Vec3f(x+f, y+f, z+f);
	}
	
	Vec3f& Vec3f::operator+=( const float f ) {
		x += f;
		y += f;
		z += f;
		return *this;
	}
	
	Vec3f Vec3f::operator-( const float f ) const {
		return Vec3f( x-f, y-f, z-f);
	}
	
	Vec3f& Vec3f::operator-=( const float f ) {
		x -= f;
		y -= f;
		z -= f;
		return *this;
	}
	
	Vec3f Vec3f::operator-() const {
		return Vec3f(-x, -y, -z);
	}
	
	Vec3f Vec3f::operator*( const float f ) const {
		return Vec3f(x*f, y*f, z*f);
	}
	
	Vec3f& Vec3f::operator*=( const float f ) {
		x*=f;
		y*=f;
		z*=f;
		return *this;
	}
	
	Vec3f Vec3f::operator/( const float f ) const {
		if(f == 0) return Vec3f(x, y);
		return Vec3f(x/f, y/f, z/f);
	}
	
	Vec3f& Vec3f::operator/=( const float f ) {
		if(f == 0) return *this;
		x/=f;
		y/=f;
		z/=f;
		return *this;
	}
	
	// Non-instance methods
	
	Vec3f operator+( float f, const Vec3f& vec ) {
		return Vec3f( f+vec.x, f+vec.y, f+vec.z);
	}
	
	Vec3f operator-( float f, const Vec3f& vec ) {
		return Vec3f( f-vec.x, f-vec.y, f-vec.z);
	}
	
	Vec3f operator*( float f, const Vec3f& vec ) {
		return Vec3f( f*vec.x, f-vec.y, f-vec.z);
	}
	
	Vec3f operator/( float f, const Vec3f& vec ) {
		return Vec3f( f/vec.x, f/vec.y, f/vec.z);
	}
	
	//////////////////////////////////////////////////
	#pragma mark - Rectangle
	//////////////////////////////////////////////////
	
	// Getters
	float Rectangle::left() {
		if(align == ALIGN_TOP_LEFT || align == ALIGN_MID_LEFT || align == ALIGN_BOT_LEFT) return x;
		if(align == ALIGN_TOP_LEFT || align == ALIGN_MID_LEFT || align == ALIGN_BOT_LEFT) return width * 0.5f + x;
		return x + width;
	}
	
	float Rectangle::top() {
		if(align == ALIGN_TOP_LEFT || align == ALIGN_TOP_CENTER || align == ALIGN_TOP_RIGHT) return y;
		if(align == ALIGN_MID_LEFT || align == ALIGN_MID_CENTER || align == ALIGN_MID_RIGHT) return height * 0.5f + y;
		return y + height;
	}
	
	float Rectangle::right() {
		return left() + width;
	}
	
	float Rectangle::bottom() {
		return top() + height;
	}
	
	float Rectangle::midX() {
		return width * 0.5f + left();
	}
	
	float Rectangle::midY() {
		return height * 0.5f + top();
	}
	
	bool Rectangle::inside(float x, float y) {
		return Apollo::inRange(x, left(), right()) && Apollo::inRange(y, top(), bottom());
	}
	
	bool Rectangle::inside(const Vec2f& v) {
		return inside(v.x, v.y);
	}
	
	bool Rectangle::overlapping(Rectangle r) {
		bool xOverlap = Apollo::inRange(left(), r.left(), r.right()) || Apollo::inRange(r.left(), left(), right());
		bool yOverlap = Apollo::inRange(top(), r.top(), r.bottom()) || Apollo::inRange(r.top(), top(), bottom());
		return xOverlap && yOverlap;
	}
	
	
}