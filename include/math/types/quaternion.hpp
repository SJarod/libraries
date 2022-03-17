#pragma once

struct float4;
struct mat4;

struct Quaternion
{
	union
	{
		//q = a + bi + cj + dk
		struct { float a; float i; float j; float k; };
	};

	//identity
	static const Quaternion id;

	Quaternion() = default;

	/**
	 * Create a simple quaternion.
	 */
	inline Quaternion(const float& a, const float& i, const float& j, const float& k);

	/**
	 * Create rotation quaternion.
	 *
	 * @param angle in degrees
	 * @param v
	 */
	inline Quaternion(const float& angle, const float3& v);

	/**
	 * Return the conjugate of the quaternion.
	 *
	 * @return quaternion's conjugate
	 */
	inline Quaternion	conjugate() const;

	inline float4		vec() const;

	/**
	 * Return the quaternion as a rotation matrix.
	 *
	 * @return mat4
	 */
	inline mat4			mat() const;
};

//q * f
inline Quaternion operator*(const Quaternion& q, const float& f);
//-q
inline Quaternion operator-(const Quaternion& q);
//q + q
inline Quaternion operator+(const Quaternion& q1, const Quaternion& q2);
//q * q
inline Quaternion operator*(const Quaternion& q1, const Quaternion& q2);

#include "math/types/quaternion.inl"