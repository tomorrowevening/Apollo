//
//  Vec.cpp
//  Apollo
//
//  Created by Colin Duffy on 1/18/12.
//  Copyright (c) 2012 Tomorrow Evening. All rights reserved.
//

#include "Vec.h"
#include "MathUtil.h"

vec2f vec2f::zero() {
	return vec2f(0, 0);
}
vec2f vec2f::one() {
	return vec2f(1, 1);
}

float vec2f::length() {
	return sqrt(x*x + y*y);
}

void vec2f::normalize() {
	float delim = 1.0f / length();
	x *= delim;
	y *= delim;
}

void vec2f::rotate(float angle) {
	float cosA = cos(angle);
	float sinA = sin(angle);
	float rotX = x * cosA - y * sinA;
	y = x * sinA + y * cosA;
	x = rotX;
}

vec2f vec2f::range(float minX, float maxX, float minY, float maxY, float per) {
	return vec2f(RANGE(minX, maxX, per), RANGE(minY, maxY, per));
}
vec2f vec2f::random(float x, float y) {
	return vec2f(MathUtil::randomRange(0, x), MathUtil::randomRange(0, y));
}
vec2f vec2f::randomRange(float minX, float maxX, float minY, float maxY) {
	return vec2f(MathUtil::randomRange(minX, maxX), MathUtil::randomRange(minY, maxY));
}

vec2f::vec2f( float _x, float _y ):x(_x), y(_y) {}

vec2f::vec2f( const vec2f& vec ) {
	x = vec.x;
	y = vec.y;
}

bool vec2f::operator==( const vec2f& vec ) const {
	return (x == vec.x) && (y == vec.y);
}

bool vec2f::operator!=( const vec2f& vec ) const {
	return (x != vec.x) || (y != vec.y);
}

vec2f vec2f::operator+( const vec2f& vec ) const {
	return vec2f( x+vec.x, y+vec.y);
}

vec2f& vec2f::operator+=( const vec2f& vec ) {
	x += vec.x;
	y += vec.y;
	return *this;
}

vec2f vec2f::operator-( const vec2f& vec ) const {
	return vec2f(x-vec.x, y-vec.y);
}

vec2f& vec2f::operator-=( const vec2f& vec ) {
	x -= vec.x;
	y -= vec.y;
	return *this;
}

vec2f vec2f::operator*( const vec2f& vec ) const {
	return vec2f(x*vec.x, y*vec.y);
}

vec2f& vec2f::operator*=( const vec2f& vec ) {
	x*=vec.x;
	y*=vec.y;
	return *this;
}

vec2f vec2f::operator/( const vec2f& vec ) const {
	return vec2f( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y);
}

vec2f& vec2f::operator/=( const vec2f& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	return *this;
}

vec2f vec2f::operator+( const float f ) const {
	return vec2f( x+f, y+f);
}

vec2f& vec2f::operator+=( const float f ) {
	x += f;
	y += f;
	return *this;
}

vec2f vec2f::operator-( const float f ) const {
	return vec2f( x-f, y-f);
}

vec2f& vec2f::operator-=( const float f ) {
	x -= f;
	y -= f;
	return *this;
}

vec2f vec2f::operator-() const {
	return vec2f(-x, -y);
}

vec2f vec2f::operator*( const float f ) const {
	return vec2f(x*f, y*f);
}

vec2f& vec2f::operator*=( const float f ) {
	x*=f;
	y*=f;
	return *this;
}

vec2f vec2f::operator/( const float f ) const {
	if(f == 0) return vec2f(x, y);
	
	return vec2f(x/f, y/f);
}

vec2f& vec2f::operator/=( const float f ) {
	if(f == 0) return *this;
	
	x/=f;
	y/=f;
	return *this;
}

void vec2f::set(float px, float py) {
	x = px;
	y = py;
}

void vec2f::set(vec2f pos) {
	x = pos.x;
	y = pos.y;
}

vec2f operator+( float f, const vec2f& vec ) {
    return vec2f( f+vec.x, f+vec.y);
}

vec2f operator-( float f, const vec2f& vec ) {
    return vec2f( f-vec.x, f-vec.y);
}

vec2f operator*( float f, const vec2f& vec ) {
    return vec2f( f*vec.x, f*vec.y);
}

vec2f operator/( float f, const vec2f& vec ) {
    return vec2f( f/vec.x, f/vec.y);
}

#pragma mark - Vec3

float vec3f::length() {
	return sqrt(x*x + y*y + z*z);
}

void vec3f::normalize() {
	float delim = 1.0f / length();
	x *= delim;
	y *= delim;
	z *= delim;
}

void vec3f::rotate(float angle) {
	rotateZ(angle);
}

void vec3f::rotateX(float angle) {
	float sinA = sin(angle);
	float cosA = cos(angle);
	float rotY = y * cosA - z * sinA;
	float rotZ = y * sinA + z * cosA;
	y = rotY;
	z = rotZ;
}

void vec3f::rotateY(float angle) {
	float sinA = sin(angle);
	float cosA = cos(angle);
	float rotX = x * cosA - z * sinA;
	float rotZ = x * sinA + z * cosA;
	x = rotX;
	z = rotZ;
}

void vec3f::rotateZ(float angle) {
	float sinA = sin(angle);
	float cosA = cos(angle);
	float rotX = x * cosA - y * sinA;
	float rotY = x * sinA + y * cosA;
	x = rotX;
	y = rotY;
}


#pragma Vec3

vec3f vec3f::zero() {
	return vec3f(0, 0, 0);
}
vec3f vec3f::one() {
	return vec3f(1, 1, 1);
}

vec3f vec3f::range(float minX, float maxX, float minY, float maxY, float minZ, float maxZ, float per) {
	return vec3f(RANGE(minX, maxX, per), RANGE(minY, maxY, per), RANGE(minZ, maxY, per));
}
vec3f vec3f::random(float x, float y, float z) {
	return vec3f(MathUtil::randomRange(0, x), MathUtil::randomRange(0, y), MathUtil::randomRange(0, z));
}
vec3f vec3f::randomRange(float minX, float maxX, float minY, float maxY, float minZ, float maxZ) {
	return vec3f(MathUtil::randomRange(minX, maxX), MathUtil::randomRange(minY, maxY), MathUtil::randomRange(minZ, maxZ));
}

vec3f::vec3f::vec3f( float _x, float _y, float _z ):x(_x), y(_y), z(_z) {}

vec3f::vec3f( const vec3f& vec ) {
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

bool vec3f::operator==( const vec3f& vec ) const {
	return (x == vec.x) && (y == vec.y) && (z == vec.z);
}

bool vec3f::operator!=( const vec3f& vec ) const {
	return (x != vec.x) || (y != vec.y) || (z != vec.z);
}

vec3f vec3f::operator+( const vec3f& vec ) const {
	return vec3f( x+vec.x, y+vec.y, z+vec.z);
}

vec3f& vec3f::operator+=( const vec3f& vec ) {
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

vec3f vec3f::operator-( const vec3f& vec ) const {
	return vec3f(x-vec.x, y-vec.y, z-vec.z);
}

vec3f& vec3f::operator-=( const vec3f& vec ) {
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

vec3f vec3f::operator*( const vec3f& vec ) const {
	return vec3f(x*vec.x, y*vec.y, z*vec.z);
}

vec3f& vec3f::operator*=( const vec3f& vec ) {
	x*=vec.x;
	y*=vec.y;
	z*=vec.z;
	return *this;
}

vec3f vec3f::operator/( const vec3f& vec ) const {
	return vec3f( vec.x!=0 ? x/vec.x : x , vec.y!=0 ? y/vec.y : y , vec.z!=0 ? z/vec.z : z);
}

vec3f& vec3f::operator/=( const vec3f& vec ) {
	vec.x!=0 ? x/=vec.x : x;
	vec.y!=0 ? y/=vec.y : y;
	vec.z!=0 ? z/=vec.z : z;
	return *this;
}

vec3f vec3f::operator+( const float f ) const {
	return vec3f( x+f, y+f, z+f);
}

vec3f& vec3f::operator+=( const float f ) {
	x += f;
	y += f;
	z += f;
	return *this;
}

vec3f vec3f::operator-( const float f ) const {
	return vec3f( x-f, y-f, z-f);
}

vec3f& vec3f::operator-=( const float f ) {
	x -= f;
	y -= f;
	z -= f;
	return *this;
}

vec3f vec3f::operator-() const {
	return vec3f(-x, -y, -z);
}

vec3f vec3f::operator*( const float f ) const {
	return vec3f(x*f, y*f, z*f);
}

vec3f& vec3f::operator*=( const float f ) {
	x*=f;
	y*=f;
	z*=f;
	return *this;
}

vec3f vec3f::operator/( const float f ) const {
	if(f == 0) return vec3f(x, y, z);
	
	return vec3f(x/f, y/f, z/f);
}

vec3f& vec3f::operator/=( const float f ) {
	if(f == 0) return *this;
	
	x/=f;
	y/=f;
	z/=f;
	return *this;
}

void vec3f::set(float px, float py, float pz) {
	x = px;
	y = py;
	z = pz;
}

void vec3f::set(vec3f pos) {
	x = pos.x;
	y = pos.y;
	z = pos.z;
}

vec3f operator+( float f, const vec3f& vec ) {
	return vec3f( f+vec.x, f+vec.y, f+vec.z);
}

vec3f operator-( float f, const vec3f& vec ) {
	return vec3f( f-vec.x, f-vec.y, f-vec.z);
}

vec3f operator*( float f, const vec3f& vec ) {
	return vec3f( f*vec.x, f*vec.y, f*vec.z);
}

vec3f operator/( float f, const vec3f& vec ) {
	return vec3f( f/vec.x, f/vec.y, f/vec.z);
}



#pragma mark - Rectangle

float Rectangle::x()  {
	return pos.x;
}

float Rectangle::y() {
	return pos.y;
}

float Rectangle::z() {
	return pos.z;
}

float Rectangle::width() {
	return size.x;
}
float Rectangle::height() {
	return size.y;
}
float Rectangle::depth() {
	return size.z;
}

float Rectangle::left() {
	return pos.x;
}

float Rectangle::top() {
	return pos.y;
}

float Rectangle::right() {
	return pos.x + size.x;
}

float Rectangle::bottom() {
	return pos.y + size.y;
}

float Rectangle::front() {
	return pos.z;
}

float Rectangle::back() {
	return pos.z + size.z;
}

bool Rectangle::inside(vec2f point) {
	bool insideX = point.x >= left()  && point.x <= right();
	bool insideY = point.y >= top()   && point.y <= bottom();
	return insideX && insideY;
}

bool Rectangle::inside(vec3f point) {
	bool insideX = MathUtil::inRange(point.x, left(),  right());
	bool insideY = MathUtil::inRange(point.y, top(),   bottom());
	bool insideZ = MathUtil::inRange(point.z, front(), back());
	return insideX && insideY && insideZ;
}

bool Rectangle::overlapping(Rectangle rect) {
	bool xOverlap = MathUtil::inRange(rect.pos.x, left(),  right())  || MathUtil::inRange(left(),  rect.left(),  rect.right());
	bool yOverlap = MathUtil::inRange(rect.pos.y, top(),   bottom()) || MathUtil::inRange(top(),   rect.top(),   rect.bottom());
	bool zOverlap = MathUtil::inRange(rect.pos.z, front(), back())   || MathUtil::inRange(front(), rect.front(), rect.back());
	return xOverlap && yOverlap && zOverlap;
}
