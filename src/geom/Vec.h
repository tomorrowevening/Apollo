//
//  Vec.h
//  Apollo
//
//  Created by Colin Duffy on 1/18/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#pragma once

#pragma mark Vec2f

class vec2f {
public:
	float x, y;
	
	vec2f( float _x=0.f, float _y=0.f );
    vec2f( const vec2f& vec );
	
	bool operator==( const vec2f& vec ) const;
	bool operator!=( const vec2f& vec ) const;
	
	vec2f  operator+( const vec2f& vec ) const;
    vec2f& operator+=( const vec2f& vec );
    vec2f  operator-( const vec2f& vec ) const;
    vec2f& operator-=( const vec2f& vec );
    vec2f  operator*( const vec2f& vec ) const;
    vec2f& operator*=( const vec2f& vec );
    vec2f  operator/( const vec2f& vec ) const;
    vec2f& operator/=( const vec2f& vec );
	
	vec2f  operator+( const float f ) const;
    vec2f& operator+=( const float f );
    vec2f  operator-( const float f ) const;
    vec2f& operator-=( const float f );
    vec2f  operator-() const;
    vec2f  operator*( const float f ) const;
    vec2f& operator*=( const float f );
    vec2f  operator/( const float f ) const;
    vec2f& operator/=( const float f );
	
	static vec2f zero();
    static vec2f one();
	static vec2f random(float x, float y);
	static vec2f randomRange(float minX, float maxX, float minY, float maxY);

	float length();
	void normalize();
	void rotate(float angle);
	
};

vec2f operator+( float f, const vec2f& vec );
vec2f operator-( float f, const vec2f& vec );
vec2f operator*( float f, const vec2f& vec );
vec2f operator/( float f, const vec2f& vec );



#pragma mark - Vec3f

class vec3f {
public:
	
	float x, y, z;
	
	vec3f( float _x=0.f, float _y=0.f, float _z=0.f );
	vec3f( const vec3f& vec );
	
	bool operator==( const vec3f& vec ) const;
	bool operator!=( const vec3f& vec ) const;
	
	vec3f  operator+( const vec3f& vec ) const;
	vec3f& operator+=( const vec3f& vec );
	vec3f  operator-( const vec3f& vec ) const;
	vec3f& operator-=( const vec3f& vec );
	vec3f  operator*( const vec3f& vec ) const;
	vec3f& operator*=( const vec3f& vec );
	vec3f  operator/( const vec3f& vec ) const;
	vec3f& operator/=( const vec3f& vec );
	
	vec3f  operator+( const float f ) const;
	vec3f& operator+=( const float f );
	vec3f  operator-( const float f ) const;
	vec3f& operator-=( const float f );
	vec3f  operator-() const;
	vec3f  operator*( const float f ) const;
	vec3f& operator*=( const float f );
	vec3f  operator/( const float f ) const;
	vec3f& operator/=( const float f );
	
	float length();
	void normalize();
	void rotate(float angle);
	void rotateX(float angle);
	void rotateY(float angle);
	void rotateZ(float angle);
	
	static vec3f zero();
    static vec3f one();
	static vec3f random(float x, float y, float z);
	static vec3f randomRange(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	
};

vec3f operator+(float f, const vec3f& vec);
vec3f operator-(float f, const vec3f& vec);
vec3f operator*(float f, const vec3f& vec);
vec3f operator/(float f, const vec3f& vec);


