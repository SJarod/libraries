#include <cassert>

#include "math.hpp"
#include "types.hpp"

inline int& int2::operator[](const unsigned int i)
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline const int& int2::operator[](const unsigned int i) const
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline int& int3::operator[](const unsigned int i)
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}

inline const int& int3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}

inline uint& uint2::operator[](const unsigned int i)
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline const uint& uint2::operator[](const unsigned int i) const
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline uint& uint3::operator[](const unsigned int i)
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}

inline const uint& uint3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}

inline float& vec2::operator[](const unsigned int i)
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline const float& vec2::operator[](const unsigned int i) const
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline float vec2::sqrMag() const
{
	return x * x + y * y;
}

inline float vec2::mag() const
{
	return sqrtf(sqrMag());
}

inline vec2 vec2::normalized() const
{
	return (*this) / mag();
}

inline float& vec3::operator[](const unsigned int i)
{
	assert(("out of range", i < 3));
	return i == 2 ? z : xy[i];
}

inline const float& vec3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 3));
	return i == 2 ? z : xy[i];
}

inline float vec3::sqrMag() const
{
	return x * x + y * y + z * z;
}

inline float vec3::mag() const
{
	return sqrtf(sqrMag());
}

inline vec3 vec3::normalized() const
{
	return (*this) / mag();
}

inline float& vec4::operator[](const unsigned int i)
{
	assert(("out of range", i < 4));
	return i == 3 ? w : xyz[i];
}

inline const float& vec4::operator[](const unsigned int i) const
{
	assert(("out of range", i < 4));
	return i == 3 ? w : xyz[i];
}

inline float vec4::sqrMag() const
{
	return x * x + y * y + z * z + w * w;
}

inline float vec4::mag() const
{
	return sqrtf(sqrMag());
}

inline vec4 vec4::normalized() const
{
	return (*this) / mag();
}

inline float& mat3::operator[](const unsigned int i)
{
	assert(("out of range", i < 9));
	int m = i % 3;
	return row[(i - m) / 3][m];
}

inline const float& mat3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 9));
	int m = i % 3;
	return row[(i - m) / 3][m];
}

inline float& mat4::operator[](const unsigned int i)
{
	assert(("out of range", i < 16));
	int m = i % 4;
	return row[(i - m) / 4][m];
}

inline const float& mat4::operator[](const unsigned int i) const
{
	assert(("out of range", i < 16));
	int m = i % 4;
	return row[(i - m) / 4][m];
}

mat4 Math3::transpose(const mat4& m)
{
	mat4 t = {
		m[0], m[4], m[8], m[12],
		m[1], m[5], m[9], m[13],
		m[2], m[6], m[10], m[14],
		m[3], m[7], m[11], m[15]
	};
	return t;
}

inline mat4 Math3::frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far)
{
	mat4 frs;
	frs.row[0] = { (2 * near) / (right - left), 0.f, (right + left) / (right - left), 0.f };
	frs.row[1] = { 0.f, (2 * near) / (top - bot), (top + bot) / (top - bot), 0.f };
	frs.row[2] = { 0.f, 0.f, -(far + near) / (far - near), -(2 * far * near) / (far - near) };
	frs.row[3] = { 0.f, 0.f, -1.f, 0.f };
	return frs;
}

inline mat4 Math3::perspective(const float& fovYdeg, const float& aspect, const float& near, const float& far)
{
	float top = near * tanf(fovYdeg * TORAD * 0.5f);
	float right = top * aspect;

	return frustum(-right, right, -top, top, near, far);
}

inline mat4 Math3::orthographic(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far)
{
	mat4 orth;
	orth.row[0] = { 2 / (right - left), 0.f, 0.f, -(right + left) / (right - left) };
	orth.row[1] = { 0.f, 2 / (top - bot), 0.f, -(top + bot) / (top - bot) };
	orth.row[2] = { 0.f, 0.f, -2 / (far - near), -(far + near) / (far - near) };
	orth.row[3] = { 0.f, 0.f, 0.f, 1.f };
	return orth;
}

inline float Math::min(const float& a, const float& b)
{
	return a < b ? a : b;
}

inline float Math::max(const float& a, const float& b)
{
	return a > b ? a : b;
}

inline vec3 Math::min(const vec3& a, const vec3& b)
{
	return { min(a.x, b.x), min(a.y, b.y), min(a.z, a.z) };
}

inline vec3 Math::max(const vec3& a, const vec3& b)
{
	return { max(a.x, b.x), max(a.y, b.y), max(a.z, a.z) };
}

inline float Math::clamp(const float& value, const float& mini, const float& maxi)
{
	return max(mini, min(value, maxi));
}

inline float Math::saturate(const float& value)
{
	//clamp between 0 and 1
	return max(0.f, min(value, 1.f));
}

inline int Math::remap(int val, int min1, int max1, int min2, int max2)
{
	return min2 + (val - min1) * (max2 - min2) / (max1 - min1);
}

inline float Math::lerp(const float& from, const float& to, const float& t)
{
	return (1 - t) * from + t * to;
}

inline vec3 Math::lerp(const vec3& from, const vec3& to, const float& t)
{
	return { lerp(from.x, to.x, t),
			 lerp(from.y, to.y, t),
			 lerp(from.z, to.z, t) };
}

inline float Math2::dotProduct(const vec2& a, const vec2& b)
{
	return a.x * b.x + a.y * b.y;
}

inline float Math3::dotProduct(const vec3& a, const vec3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float Math3::dotProduct(const vec4& a, const vec4& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline vec2 operator+(const vec2& a, const vec2& b)
{
	return { a.x + b.x, a.y + b.y };
}

vec2 operator-(const vec2& a, const vec2& b)
{
	return { a.x - b.x, a.y - b.y };
}

inline vec2 operator*(const float& a, const vec2& v)
{
	return { a * v.x, a * v.y };
}

inline vec2 operator/(const vec2& v, const float a)
{
	if (a == 0)
		return v;

	return { v.x / a, v.y / a };
}

inline vec3 operator-(const vec3& v)
{
	return { -v.x, -v.y, -v.z };
}

inline vec3 operator-(const vec3& a, const vec3& b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

inline vec3 operator*(const float& a, const vec3& v)
{
	return { a * v.x, a * v.y, a * v.z };
}

inline vec3 operator/(const vec3& v, const float a)
{
	if (a == 0)
		return v;

	return { v.x / a, v.y / a, v.z / a };
}

inline void operator+=(vec3& a, const vec3& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}

inline vec4 operator/(const vec4& v, const float a)
{
	if (a == 0)
		return v;

	return { v.x / a, v.y / a, v.z / a, v.w / a };
}

inline vec4 operator*(const mat4& m, const vec4& v)
{
	vec4 temp = {};

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			temp[i] += m.row[i][j] * v[j];
		}
	}

	return temp;
}

inline mat4 operator*(const mat4& m, const mat4& m2)
{
	mat4 temp = {};

				// 0  1  2  3
				// 4  5  6  7
				// 8  9 10 11
				//12 13 14 15
	// 0  1  2  3
	// 4  5  6  7
	// 8  9 10 11
	//12 13 14 15

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				//column
				/*
				temp.row[i][j] += m.row[i][k] * m2[k * 4 + j];
				*/
				//row
				temp.row[j][i] += m.row[k][i] * m2[j * 4 + k];
			}
		}
	}

	return temp;
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