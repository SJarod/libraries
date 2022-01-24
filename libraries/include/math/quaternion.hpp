#pragma once

#include "math/math.hpp"

namespace Math3
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

template <class Q>
vec3 Math3::rotateQ(const vec3& v, const Q& q)
{
	Quaternion qr = q * v.q() * q.conjugate();
	return { qr.i, qr.j, qr.k };
}

template<typename firstQuaternion, typename... quaternionArgs>
vec3 Math3::rotateQ(const vec3& v, const firstQuaternion& q1, const quaternionArgs&... qs)
{
	vec3 r = rotateQ(v, q1);
	r = rotateQ(r, qs...);

	return r;
}