#pragma once

struct float4;

struct mat4
{
	union
	{
		float4	row[4];
		float	elem[16];
	};

	//zero
	static const mat4 zo;
	//identity
	static const mat4 id;

	inline float4& operator[](const unsigned int i);
	inline const float4& operator[](const unsigned int i) const;
};

//mat4 * float4
inline float4 operator*(const mat4& m, const float4& f);
//mat4 * mat4
inline mat4 operator*(const mat4& m1, const mat4& m2);

#include "math/mat4.hpp"