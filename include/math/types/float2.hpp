#pragma once

struct float2
{
	union
	{
		struct { float x; float y; };
		float  elem[2];
	};

	//zero
	static const float2 zo;
	//up
	static const float2 up;
	//down
	static const float2 dn;
	//left
	static const float2 le;
	//right
	static const float2 ri;

	inline float	sqrMag() const;
	inline float	mag() const;
	inline float2	normalized() const;

	inline float& operator[](const unsigned int i);
	inline const float& operator[](const unsigned int i) const;
};

//float2 + float2
inline float2 operator+(const float2& a, const float2& f);
//float2 - float2
inline float2 operator-(const float2& a, const float2& f);
//f * float2
inline float2 operator*(const float& f, const float2& a);
//float2 / f
inline float2 operator/(const float2& a, const float& f);

#ifdef FLOAT_AS_VEC
typedef float2 vec2;
#endif

#include "math/types/float2.inl"