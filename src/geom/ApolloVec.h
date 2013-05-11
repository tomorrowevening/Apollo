//
//  ApolloVec.h
//  Apollo
//  Created by Colin Duffy on 5/10/13.
//
//

#pragma once
#include "ApolloMath.h"

namespace Apollo {
	
	//////////////////////////////////////////////////
	// Vec 2
	//////////////////////////////////////////////////
	
	class Vec2f {
	public:
		float x, y;
		Vec2f(float _x = 0, float _y = 0):x(_x), y(_y){}
		Vec2f(const Vec2f& v){ x = v.x; y = v.y; }
		
		void normalize() {
			float delim = 1.0f / length();
			x *= delim;
			y *= delim;
		}
		
		// Getters
		float distanceTo(float ox, float oy) { return Apollo::distance(x, y, ox, oy); }
		float distanceTo(const Vec2f& other) { return Apollo::distance(x, y, other.x, other.y); }
		float length() { return sqrt(x*x + y*y); }
		static Vec2f range(float minX, float maxX, float minY, float maxY, float per);
		static Vec2f randomRange(float minX, float maxX, float minY, float maxY);
		static Vec2f random(float maxX, float maxY);
		
		// Setters
		void set(float _x, float _y){ x = _x; y = _y; }
		void set(const Vec2f& v){ x = v.x; y = v.y; }
		
		// Operators
		bool operator==( const Vec2f& vec ) const;
		bool operator!=( const Vec2f& vec ) const;
		Vec2f  operator+( const Vec2f& vec ) const;
		Vec2f& operator+=( const Vec2f& vec );
		Vec2f  operator-( const Vec2f& vec ) const;
		Vec2f& operator-=( const Vec2f& vec );
		Vec2f  operator*( const Vec2f& vec ) const;
		Vec2f& operator*=( const Vec2f& vec );
		Vec2f  operator/( const Vec2f& vec ) const;
		Vec2f& operator/=( const Vec2f& vec );
		
		Vec2f  operator+( const float f ) const;
		Vec2f& operator+=( const float f );
		Vec2f  operator-( const float f ) const;
		Vec2f& operator-=( const float f );
		Vec2f  operator-() const;
		Vec2f  operator*( const float f ) const;
		Vec2f& operator*=( const float f );
		Vec2f  operator/( const float f ) const;
		Vec2f& operator/=( const float f );
	};
	
	Vec2f operator+( float f, const Vec2f& vec );
	Vec2f operator-( float f, const Vec2f& vec );
	Vec2f operator*( float f, const Vec2f& vec );
	Vec2f operator/( float f, const Vec2f& vec );
	
	//////////////////////////////////////////////////
	// Vec 3
	//////////////////////////////////////////////////
	
	class Vec3f {
	public:
		float x, y, z;
		Vec3f(float _x = 0, float _y = 0, float _z = 0):x(_x), y(_y), z(_z){}
		Vec3f(const Vec3f& v){ x = v.x; y = v.y; z = v.z; }
		
		void normalize() {
			float delim = 1.0f / length();
			x *= delim;
			y *= delim;
			z *= delim;
		}
		
		// Getters
		float length() { return sqrt(x*x + y*y + z*z); }
		static Vec3f range(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, float per);
		static Vec3f randomRange(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
		static Vec3f random(float maxX, float maxY, float maxZ);
		
		// Setters
		void set(float _x, float _y, float _z){ x = _x; y = _y; z = _z; }
		void set(const Vec3f& v){ x = v.x; y = v.y; z = v.z; }
		
		// Operators
		bool operator==( const Vec3f& vec ) const;
		bool operator!=( const Vec3f& vec ) const;
		Vec3f  operator+( const Vec3f& vec ) const;
		Vec3f& operator+=( const Vec3f& vec );
		Vec3f  operator-( const Vec3f& vec ) const;
		Vec3f& operator-=( const Vec3f& vec );
		Vec3f  operator*( const Vec3f& vec ) const;
		Vec3f& operator*=( const Vec3f& vec );
		Vec3f  operator/( const Vec3f& vec ) const;
		Vec3f& operator/=( const Vec3f& vec );
		
		Vec3f  operator+( const float f ) const;
		Vec3f& operator+=( const float f );
		Vec3f  operator-( const float f ) const;
		Vec3f& operator-=( const float f );
		Vec3f  operator-() const;
		Vec3f  operator*( const float f ) const;
		Vec3f& operator*=( const float f );
		Vec3f  operator/( const float f ) const;
		Vec3f& operator/=( const float f );
	};
	
	Vec3f operator+( float f, const Vec3f& vec );
	Vec3f operator-( float f, const Vec3f& vec );
	Vec3f operator*( float f, const Vec3f& vec );
	Vec3f operator/( float f, const Vec3f& vec );
	
	//////////////////////////////////////////////////
	// Rectangle
	//////////////////////////////////////////////////
	
	class Rectangle : public Vec2f {
	public:
		
		MatrixAlign align;
		float width, height;
		
		Rectangle(float _x = 0, float _y = 0){ x = _x; y = _y;}
		Rectangle(const Vec2f& v){ x = v.x; y = v.y; }
		
		// Getters
		float left();
		float top();
		float right();
		float bottom();
		float midX();
		float midY();
		
		bool inside(float x, float y);
		bool inside(const Vec2f& v);
		bool overlapping(Rectangle r);
		
	};
	
}

