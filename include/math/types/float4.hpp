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

	/**
	 * Get the square magnitude of this vector.
	 * 
	 * @return 
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
	inline float4 normalized() const;

	/**
	 * Access this vector's elements with [].
	 * 
	 * @param i
	 * @return 
	 */
	inline float& operator[](const unsigned int i);

	/**
	 * Access this vector's elements with [].
	 * 
	 * @param i
	 * @return 
	 */
	inline const float& operator[](const unsigned int i) const;
};

/**
 * float4 / f.
 */
inline float4 operator/(const float4& a, const float& f);

#ifdef FLOAT_AS_VEC
typedef float4 vec4;
#endif

#include "math/types/float4.inl"