#include <iostream>

#include "math/quaternion.hpp"

Quaternion::Quaternion(const float& a, const float& i, const float& j, const float& k)
	: a(a), i(i), j(j), k(k)
{
}

Quaternion::Quaternion(const float& angle, const vec3& v)
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

mat4 Quaternion::mat() const
{
	//source : https://automaticaddison.com/how-to-convert-a-quaternion-to-a-rotation-matrix/#:~:text=Quaternions%20are%20often%20used%20instead%20of%20Euler%20angle,in%203D%20space%29%20about%20an%20arbitrary%20axis%2C%20
	float q0 = a, q1 = i, q2 = j, q3 = k;
	mat4 mq;
	mq.row[0] = { 2.f * (q0 * q0 + q1 * q1) - 1, 2.f * (q1 * q2 - q0 * q3), 2.f * (q1 * q3 + q0 * q2), 0.f };
	mq.row[1] = { 2.f * (q1 * q2 + q0 * q3), 2.f * (q0 * q0 + q2 * q2) - 1, 2.f * (q2 * q3 - q0 * q1), 0.f };
	mq.row[2] = { 2.f * (q1 * q3 - q0 * q2), 2.f * (q2 * q3 + q0 * q1), 2.f * (q0 * q0 + q3 * q3) - 1, 0.f };
	mq.row[3] = { 0.f, 0.f, 0.f, 1.f };
	return mq;
}

vec3 Math3::rotateQ(const vec3& v, const float& angle, const vec3& axis)
{
	Quaternion q(angle, axis);
	Quaternion qb = q.conjugate();
	Quaternion qv = v.q();

	Quaternion qr = q * qv * qb;	//quaternion after rotation

	return { qr.i, qr.j, qr.k };
}