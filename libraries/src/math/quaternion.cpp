#include "math/quaternion.hpp"

#include <iostream>

Core::Math::Quaternion::Quaternion(const float& a, const float& i, const float& j, const float& k)
	: a(a), i(i), j(j), k(k)
{
}

Core::Math::Quaternion::Quaternion(const float& angle, const vec3& v)
{
	float a = angle * TORAD;

	//real part
	this->a = cosf(a / 2);

	//imaginary part
	float im = sinf(a / 2);
	vec3 axis = v.normalized();
	this->i = im * axis.i;
	this->j = im * axis.j;
	this->k = im * axis.k;
}

vec3 Core::Math::rotateQ(const vec3& v, const float& angle, const vec3& axis)
{
	Quaternion q(angle, axis);
	Quaternion qb = q.conjugate();
	Quaternion qv = v.q();

	Quaternion qr = q * qv * qb;	//quaternion after rotation

	return { qr.i, qr.j, qr.k };
}