#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288419716939937510f
#endif
// 2 * pi
#ifndef M_TAU
#define M_TAU 6.28318530717958647692528676655900576839433879875020f
#endif
// pi / 180
#ifndef TORAD
#define TORAD 0.017453292519943295769236907684886127134428718885417f
#endif
// 180 / pi
#ifndef TODEG
#define TODEG 57.295779513082320876798154814105170332405472466564f
#endif

#include <cmath>
#include <cfloat>

#include <iostream>

#include "types.hpp"

namespace Math
{
	inline float min(const float& a, const float& b);
	inline float max(const float& a, const float& b);
	inline vec3	 min(const vec3& a, const vec3& b);
	inline vec3	 max(const vec3& a, const vec3& b);

	inline float clamp(const float& value, const float& mini, const float& maxi);
	inline float saturate(const float& value);

	inline int	 remap(int val, int min1, int max1, int min2, int max2);

	inline float lerp(const float& from, const float& to, const float& t);
	inline vec3	 lerp(const vec3& from, const vec3& to, const float& t);
	Quaternion	 nlerp(const Quaternion& from, const Quaternion& to, const float& t);
	Quaternion	 slerp(const Quaternion& from, const Quaternion& to, const float& t);
}

namespace Math2
{
	inline float dotProduct(const vec2& a, const vec2& b);

	//angle in degrees
	vec2 rotate(const vec2& v, const float& angle);
}

namespace Math3
{
	inline float dotProduct(const vec3& a, const vec3& b);
	inline float dotProduct(const vec4& a, const vec4& b);
	vec3		 crossProduct(const vec3& a, const vec3& b);

	inline mat4 transpose(const mat4& m);

	inline mat4 frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);
	inline mat4 perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far);
	inline mat4 orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	mat4 translateMatrix(const vec3& pos);

	//euler rotation
	mat4 rotateXMatrix(const float& pitch);		//angle in degrees
	mat4 rotateYMatrix(const float& yaw);		//angle in degrees
	mat4 rotateZMatrix(const float& roll);		//angle in degrees

	mat4 scaleMatrix(const vec3& scale);
}

//vec2 + vec2
inline vec2 operator+(const vec2& a, const vec2& b);
//vec2 - vec2
inline vec2 operator-(const vec2& a, const vec2& b);
//f * vec2
inline vec2 operator*(const float& a, const vec2& v);
//vec2 / f
inline vec2 operator/(const vec2& v, const float a);

//-vec3
inline vec3 operator-(const vec3& v);
//vec3 - vec3
inline vec3 operator-(const vec3& a, const vec3& b);
//f * vec3
inline vec3 operator*(const float& a, const vec3& v);
//vec3 / f
inline vec3 operator/(const vec3& v, const float a);
//vec3 += vec3
inline void operator+=(vec3& a, const vec3& b);

//vec4 / f
inline vec4 operator/(const vec4& v, const float a);

//mat4 * vec4
inline vec4 operator*(const mat4& m, const vec4& v);
//mat4 * mat4
inline mat4 operator*(const mat4& m, const mat4& m2);

//q * f
inline Quaternion operator*(const Quaternion& q, const float& f);
//-q
inline Quaternion operator-(const Quaternion& q);
//q + q
inline Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
//q * q
inline Quaternion operator*(const Quaternion& q1, const Quaternion& q2);

std::ostream& operator<<(std::ostream& os, const vec2& v);
std::ostream& operator<<(std::ostream& os, const vec3& v);
std::ostream& operator<<(std::ostream& os, const vec4& v);
std::ostream& operator<<(std::ostream& os, const mat3& m);
std::ostream& operator<<(std::ostream& os, const mat4& m);

#include "math/math.inl"