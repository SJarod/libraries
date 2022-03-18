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

	/**
	 * Get the square magnitude of this vector.
	 * 
	 * @return float
	 */
	inline float sqrMag() const;

	/**
	 * Get the magnitude of this vector.
	 * 
	 * @return 
	 */
	inline float mag() const;

	/**
	 * Get this vector with normalized magnitude.
	 * 
	 * @return 
	 */
	inline float2 normalized() const;

	/**
	 * Access this vector's elements with [].
	 * 
	 * @param i
	 * @return 
	 */
	inline float& operator[](const uint i);

	/**
	 * Access this vector's elements with [].
	 * 
	 * @param i
	 * @return 
	 */
	inline const float& operator[](const uint i) const;
};

/**
 * float2 + float2.
 */
inline float2 operator+(const float2& a, const float2& f);

/**
 * float2 - float2.
 */
inline float2 operator-(const float2& a, const float2& f);

/**
 * f * float2.
 */
inline float2 operator*(const float& f, const float2& a);

/**
 * float2 / f.
 */
inline float2 operator/(const float2& a, const float& f);

#ifdef FLOAT_AS_VEC
typedef float2 vec2;
#endif

#include "types/float2.inl"