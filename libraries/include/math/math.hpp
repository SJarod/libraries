#pragma once

#ifndef M_PI
#define M_PI 3.14159265358979323846264338327950288f
#endif
#ifndef TORAD
#define TORAD M_PI / 180.f
#endif
#ifndef TODEG
#define TODEG 180.f / M_PI
#endif

#include <cmath>
#include <cfloat>

#include <iostream>

namespace Math
{
	typedef unsigned int uint;

	union vec2;
	union vec3;
	union Quaternion;

	union int2
	{
		int e[2];
	};

	union int3
	{
		int e[3];
	};

	union uint2
	{
		uint e[2];
	};

	union uint3
	{
		uint e[3];
	};

	union float2
	{
		float e[2];

		inline operator vec2() const;
	};

	union float3
	{
		float e[3];

		inline operator vec3() const;
	};

	union vec2
	{
		float  e[2];
		struct { float x; float y; };

		inline operator float2() const;
	};

	union vec3
	{
		float  e[3];
		struct { float x; float y; float z; };
		struct { float i; float j; float k; };
		vec2   xy;

		inline operator float3() const;

		//get vector's quaternion
		Quaternion q() const;

		inline float	sqrMag() const;
		inline float	mag() const;
		inline vec3		normalized() const;
	};

	union vec4
	{
		float  e[4];
		struct { float x; float y; float z; float w; };
		struct { float r; float g; float b; float a; };
		vec3   xyz;
		vec3   rgb;
	};

	union mat3
	{
		vec3	c[3];
		float	e[9];
	};

	union mat4
	{
		vec4	c[4];
		float	e[16];
	};

	inline mat3	identity3();
	inline mat4	identity4();

	inline mat4 frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);
	inline mat4 perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far);
	inline mat4 orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far);

	inline float	min(const float& a, const float& b);
	inline float	max(const float& a, const float& b);
	inline vec3		min(const vec3& a, const vec3& b);
	inline vec3		max(const vec3& a, const vec3& b);
	inline void		clamp(float& value, const float& mini, const float& maxi);

	inline float	dotProduct(const vec2& a, const vec2& b);
	inline float	dotProduct(const vec3& a, const vec3& b);
	vec3			crossProduct(const vec3& a, const vec3& b);

	//angle in degrees
	vec2	vec2Rotation(const vec2& v, const float& angle);

	mat4	translateMatrix(const vec3& pos);

	//euler rotation
	mat4	rotateXMatrix(const float& pitch);		//angle in degrees
	mat4	rotateYMatrix(const float& yaw);		//angle in degrees
	mat4	rotateZMatrix(const float& roll);		//angle in degrees

	mat4	scaleMatrix(const vec3& scale);

	//vec2 + vec2
	inline vec2 operator+(const vec2& a, const vec2& b);
	//vec2 - vec2
	inline vec2 operator-(const vec2& a, const vec2& b);
	//f * vec2
	inline vec2 operator*(const float& a, const vec2& v);
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
	//mat4 * vec4
	inline vec4 operator*(const mat4& m, const vec4& v);
	//mat4 * mat4
	inline mat4 operator*(const mat4& m, const mat4& m2);

	std::ostream& operator<<(std::ostream& os, const vec2& v);
	std::ostream& operator<<(std::ostream& os, const vec3& v);
	std::ostream& operator<<(std::ostream& os, const vec4& v);
	std::ostream& operator<<(std::ostream& os, const mat3& m);
	std::ostream& operator<<(std::ostream& os, const mat4& m);
}

using namespace Math;

#include "math/math.inl"