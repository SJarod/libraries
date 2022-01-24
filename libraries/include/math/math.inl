#include "math.hpp"

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

inline mat4 Math3::frustum(const float& left, const float& right, const float& bot, const float& top, const float& near, const float& far)
{
	mat4 frs;
	frs.c[0] = { (2 * near) / (right - left), 0.f, 0.f, -near * (right + left) / (right - left) };
	frs.c[1] = { 0.f, (2 * near) / (top - bot), 0.f, -near * (top + bot) / (top - bot) };
	frs.c[2] = { 0.f, 0.f, -(far + near) / (far - near), -(2 * far * near) / (far - near) };
	frs.c[3] = { 0.f, 0.f, -1.f, 0.f };
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
	orth.c[0] = { 2 / (right - left), 0.f, 0.f, -(right + left) / (right - left) };
	orth.c[1] = { 0.f, 2 / (top - bot), 0.f, -(top + bot) / (top - bot) };
	orth.c[2] = { 0.f, 0.f, -2 / (far - near), -(far + near) / (far - near) };
	orth.c[3] = { 0.f, 0.f, 0.f, 1.f };
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

float Math::saturate(const float& value)
{
	//clamp between 0 and 1
	return max(0.f, min(value, 1.f));
}

inline float Math2::dotProduct(const vec2& a, const vec2& b)
{
	return a.x * b.x + a.y * b.y;
}

inline float Math3::dotProduct(const vec3& a, const vec3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
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

inline vec4 operator*(const mat4& m, const vec4& v)
{
	vec4 temp = {};

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			temp.e[i] += m.c[i].e[j] * v.e[j];
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
				temp.c[i].e[j] += m.c[i].e[k] * m2.e[k * 4 + j];
			}
		}
	}

	return temp;
}