#pragma once

struct float2;
struct Quaternion;

struct float3
{
	union
	{
		struct { float x; float y; float z; };
		struct { float i; float j; float k; };
		float2 xy;
		float  elem[3];
	};

	//zero
	static const float3 zo;
	//up
	static const float3 up;
	//down
	static const float3 dn;
	//left
	static const float3 le;
	//right
	static const float3 ri;
	//forward
	static const float3 fw;
	//backward
	static const float3 bw;

	/**
	 * Get this vector's quaternion.
	 * 
	 * @return 
	 */
	inline Quaternion q() const;

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
	inline float3 normalized() const;

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
 * -float3.
 */
inline float3 operator-(const float3& a);

/**
 * float3 - float3.
 */
inline float3 operator-(const float3& a, const float3& f);

/**
 * f * float3.
 */
inline float3 operator*(const float& f, const float3& a);

/**
 * float3 / f.
 */
inline float3 operator/(const float3& a, const float& f);

/**
 * float3 += float3.
 */
inline void operator+=(float3& a, const float3& f);

#ifdef FLOAT_AS_VEC
typedef float3 vec3;
#endif

#include "math/types/float3.inl"