#pragma once

#include "math/math.hpp"

namespace Math
{
	//quaternion rotation
	//angle in degrees
	vec3 rotateQ(const vec3& v, const float& angle, const vec3& axis);

	//only accepts Quaternions
	template <class Q>
	vec3 rotateQ(const vec3& v, const Q& q);
	//multiple rotation in the order of arguments
	template <typename firstQuaternion, typename... quaternionArgs>
	vec3 rotateQ(const vec3& v, const firstQuaternion& q1, const quaternionArgs&... qs);
}

inline Quaternion Quaternion::conjugate() const
{
	Quaternion qb = { a, -i, -j, -k };
	return qb;
}

inline Quaternion Quaternion::operator*(const Quaternion& q) const
{
	Quaternion qr;	//result
	qr.a = a * q.a - i * q.i - j * q.j - k * q.k;
	qr.i = a * q.i + i * q.a + j * q.k - k * q.j;
	qr.j = a * q.j - i * q.k + j * q.a + k * q.i;
	qr.k = a * q.k + i * q.j - j * q.i + k * q.a;
	return qr;
}

template <class Q>
vec3 Math::rotateQ(const vec3& v, const Q& q)
{
	Quaternion qr = q * v.q() * q.conjugate();
	return { qr.i, qr.j, qr.k };
}

template<typename firstQuaternion, typename... quaternionArgs>
vec3 Math::rotateQ(const vec3& v, const firstQuaternion& q1, const quaternionArgs&... qs)
{
	vec3 r = rotateQ(v, q1);
	r = rotateQ(r, qs...);

	return r;
}