#include "math/quaternion.hpp"

#include <iostream>

Core::Math::Quaternion::Quaternion(const float& a, const float& i, const float& j, const float& k)
{
	this->a = a;
	this->i = i;
	this->j = j;
	this->k = k;
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

Quaternion Core::Math::Quaternion::conjugate() const
{
	Quaternion qb = { a, -i, -j, -k };
	return qb;
}

Quaternion Core::Math::Quaternion::operator*(const Quaternion& q) const
{
	Quaternion qr;	//result
	qr.a = a * q.a - i * q.i - j * q.j - k * q.k;
	qr.i = a * q.i + i * q.a + j * q.k - k * q.j;
	qr.j = a * q.j - i * q.k + j * q.a + k * q.i;
	qr.k = a * q.k + i * q.j - j * q.i + k * q.a;
	return qr;
}

vec3 Core::Math::rotateQ(const vec3& v, const float& angle, const vec3& axis)
{
	Quaternion q(angle, axis);
	Quaternion qb = q.conjugate();
	Quaternion qv = v.q();

	Quaternion qr = q * qv * qb;	//quaternion after rotation

	return { qr.i, qr.j, qr.k };
}