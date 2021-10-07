#pragma once

#ifndef M_PI
	#define M_PI 3.14159265358979323846264338327950288f
#endif
#ifndef TORAD
	#define TORAD M_PI / 180.f
#endif
#ifndef TODEG
	#define TODEG 180.f / M_PI
#endif

#include <cmath>
#include <cfloat>

namespace Core
{
	namespace Math
	{
		union Quaternion;

		union vec2
		{
			float	e[2];
			struct	{ float x; float y; };

			void	print() const;
		};

		union vec3
		{
			float	e[3];
			struct	{ float x; float y; float z; };
			struct	{ float i; float j; float k; };
			vec2	xy;

			//get vector's quaternion
			Quaternion q() const;

			inline float	sqrMag() const;
			inline float	mag() const;
			inline vec3		normalized() const;

			void		print() const;
		};

		union vec4
		{
			float	e[4];
			struct	{ float x; float y; float z; float w; };
			struct	{ float r; float g; float b; float a; };
			vec3	xyz;
			vec3	rgb;

			void	print() const;
		};

		union mat3
		{
			vec3	c[3];
			float	e[9];

			void	print() const;
		};

		union mat4
		{
			vec4	c[4];
			float	e[16];

			void	print() const;
		};

		inline mat3	identity3();
		inline mat4	identity4();

		inline float	min(const float& a, const float& b);
		inline float	max(const float& a, const float& b);
		inline vec3		min(const vec3& a, const vec3& b);
		inline vec3		max(const vec3& a, const vec3& b);
		inline void		clamp(float& value, const float& mini, const float& maxi);

		inline float	dotProduct(const vec2& a, const vec2& b);
		inline float	dotProduct(const vec3& a, const vec3& b);
		vec3			crossProduct(const vec3& a, const vec3& b);

		//angle in degrees
		vec2	vec2Rotation(const vec2& v, const float& angle);

		mat4	translateMatrix(const vec3& pos);

		//euler rotation
		mat4	rotateXMatrix(const float& pitch);		//angle in degrees
		mat4	rotateYMatrix(const float& yaw);		//angle in degrees
		mat4	rotateZMatrix(const float& roll);		//angle in degrees

		mat4	scaleMatrix(const vec3& scale);

		//vec2 + vec2
		inline vec2 operator+(const vec2& a, const vec2& b);
		//vec2 - vec2
		inline vec2 operator-(const vec2& a, const vec2& b);
		//f * vec2
		inline vec2 operator*(const float& a, const vec2& v);
		//-vec3
		inline vec3 operator-(const vec3& v);
		//vec3 - vec3
		inline vec3 operator-(const vec3& a, const vec3& b);
		//f * vec3
		inline vec3 operator*(const float& a, const vec3& v);
		//vec3 / f
		inline vec3 operator/(const vec3& v, const float a);
		//vec3 += vec3
		inline void operator+=(vec3& a, const vec3& b);
		//mat4 * vec4
		inline vec4 operator*(const mat4& m, const vec4& v);
		//mat4 * mat4
		inline mat4 operator*(const mat4& m, const mat4& m2);
	}
}

using namespace Core::Math;

inline float Core::Math::vec3::sqrMag() const
{
	return x * x + y * y + z * z;
}

inline float Core::Math::vec3::mag() const
{
	return sqrtf(sqrMag());
}

inline vec3 Core::Math::vec3::normalized() const
{
	return (*this) / mag();
}

inline mat3 Core::Math::identity3()
{
	mat3 m;
	m.c[0] = { 1.f, 0.f, 0.f };
	m.c[1] = { 0.f, 1.f, 0.f };
	m.c[2] = { 0.f, 0.f, 1.f };
	return m;
}

inline mat4 Core::Math::identity4()
{
	mat4 m;
	m.c[0] = { 1.f, 0.f, 0.f, 0.f };
	m.c[1] = { 0.f, 1.f, 0.f, 0.f };
	m.c[2] = { 0.f, 0.f, 1.f, 0.f };
	m.c[3] = { 0.f, 0.f, 0.f, 1.f };
	return m;
}

inline float Core::Math::min(const float& a, const float& b)
{
	return a < b ? a : b;
}

inline float Core::Math::max(const float& a, const float& b)
{
	return a > b ? a : b;
}

inline vec3 Core::Math::min(const vec3& a, const vec3& b)
{
	return { min(a.x, b.x), min(a.y, b.y), min(a.z, a.z) };
}

inline vec3 Core::Math::max(const vec3& a, const vec3& b)
{
	return { max(a.x, b.x), max(a.y, b.y), max(a.z, a.z) };
}

inline void Core::Math::clamp(float& value, const float& mini, const float& maxi)
{
	value = max(mini, min(value, maxi));
}

inline float Core::Math::dotProduct(const vec2& a, const vec2& b)
{
	return a.x * b.x + a.y * b.y;
}

inline float Core::Math::dotProduct(const vec3& a, const vec3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline vec2 Core::Math::operator+(const vec2& a, const vec2& b)
{
	return { a.x + b.x, a.y + b.y };
}

vec2 Core::Math::operator-(const vec2& a, const vec2& b)
{
	return { a.x - b.x, a.y - b.y };
}

inline vec2 Core::Math::operator*(const float& a, const vec2& v)
{
	return { a * v.x, a * v.y };
}

inline vec3 Core::Math::operator-(const vec3& v)
{
	return { -v.x, -v.y, -v.z };
}

inline vec3 Core::Math::operator-(const vec3& a, const vec3& b)
{
	return { a.x - b.x, a.y - b.y, a.z - b.z };
}

inline vec3 Core::Math::operator*(const float& a, const vec3& v)
{
	return { a * v.x, a * v.y, a * v.z };
}

inline vec3 Core::Math::operator/(const vec3& v, const float a)
{
	if (a == 0)
		return v;

	return { v.x / a, v.y / a, v.z / a };
}

inline void Core::Math::operator+=(vec3& a, const vec3& b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
}

inline vec4 Core::Math::operator*(const mat4& m, const vec4& v)
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

inline mat4 Core::Math::operator*(const mat4& m, const mat4& m2)
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