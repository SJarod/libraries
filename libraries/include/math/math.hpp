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
			Quaternion	q() const;
			float		sqrMag() const;
			float		mag() const;
			vec3		normalized() const;

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

		mat3	identity3();
		mat4	identity4();

		float	min(const float& a, const float& b);
		float	max(const float& a, const float& b);
		void	clamp(float& value, const float& mini, const float& maxi);

		float	dotProduct(const vec3& a, const vec3& b);
		vec3	crossProduct(const vec3& a, const vec3& b);

		mat4	translateMatrix(const vec3& pos);

		//euler rotation
		mat4	rotateXMatrix(const float& pitch);		//angle in degrees
		mat4	rotateYMatrix(const float& yaw);		//angle in degrees
		mat4	rotateZMatrix(const float& roll);		//angle in degrees

		mat4	scaleMatrix(const vec3& scale);

		//-vec3
		inline vec3 operator-(const vec3& v)
		{
			return { -v.x, -v.y, -v.z };
		}

		//f * vec3
		inline vec3 operator*(const float& a, const vec3& v)
		{
			return { a * v.x, a * v.y, a * v.z };
		}

		//vec3 / f
		inline vec3 operator/(const vec3& v, const float a)
		{
			if (a == 0)
				return v;

			return { v.x / a, v.y / a, v.z / a };
		}

		//mat4 * vec4
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

		//mat4 * mat4
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
	}
}

using namespace Core::Math;