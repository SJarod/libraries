#pragma once

struct float3;

struct float4
{
	union
	{
		struct { float x; float y; float z; float w; };
		float3 xyz;
		float  elem[4];
	};

	//zero
	static const float4 zo;

	inline float	sqrMag() const;
	inline float	mag() const;
	inline float4	normalized() const;

	inline float& operator[](const unsigned int i);
	inline const float& operator[](const unsigned int i) const;
};

//float4 / f
inline float4 operator/(const float4& a, const float& f);

#ifdef FLOAT_AS_VEC
typedef float4 vec4;
#endif

#include "math/types/float4.inl"