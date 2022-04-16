#include "mathematics.hpp"
#include "types/float4.hpp"
#include "types/mat4.hpp"

#include "types/quaternion.hpp"

inline const Quaternion Quaternion::id = { 1.f, 0.f, 0.f, 0.f };

inline Quaternion::Quaternion(const float& a, const float& i, const float& j, const float& k)
	: a(a), i(i), j(j), k(k)
{
}

inline Quaternion::Quaternion(const float4& v)
	: a(v.x), i(v.y), j(v.z), k(v.w)
{
}

inline Quaternion::Quaternion(const float& angle, const float3& v)
{
	float a = angle * Math::Conversion::degrad;

	//real part
	this->a = cosf(a / 2);

	//imaginary part
	float im = sinf(a / 2);
	float3 axis = v.normalized();
	this->i = im * axis.i;
	this->j = im * axis.j;
	this->k = im * axis.k;
}

inline Quaternion Quaternion::conjugate() const
{
	Quaternion qb = { a, -i, -j, -k };
	return qb;
}

inline float4 Quaternion::vec() const
{
	return { a, i, j, k };
}

inline mat4 Quaternion::mat() const
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

inline Quaternion operator*(const Quaternion& q, const float& f)
{
	return { q.a * f, q.i * f, q.j * f, q.k * f };
}

inline Quaternion operator-(const Quaternion& q)
{
	return q * -1.f;
}

inline Quaternion operator+(const Quaternion& q1, const Quaternion& q2)
{
	return { q1.a + q2.a, q1.i + q2.i, q1.j + q2.j, q1.k + q2.k };
}

inline Quaternion operator*(const Quaternion& q1, const Quaternion& q2)
{
	Quaternion qr;	//result
	qr.a = q1.a * q2.a - q1.i * q2.i - q1.j * q2.j - q1.k * q2.k;
	qr.i = q1.a * q2.i + q1.i * q2.a + q1.j * q2.k - q1.k * q2.j;
	qr.j = q1.a * q2.j - q1.i * q2.k + q1.j * q2.a + q1.k * q2.i;
	qr.k = q1.a * q2.k + q1.i * q2.j - q1.j * q2.i + q1.k * q2.a;
	return qr;
}