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
		union vec2
		{
			float	e[2];
			struct	{ float x; float y; };

			void	print();
		};

		union vec3
		{
			float	e[3];
			struct	{ float x; float y; float z; };
			struct	{ float i; float j; float k; };
			vec2	xy;

			void	print();
		};

		union vec4
		{
			float	e[4];
			struct	{ float x; float y; float z; float w; };
			struct	{ float r; float g; float b; float a; };
			vec3	xyz;
			vec3	rgb;

			void	print();
		};

		union mat4
		{
			vec4	c[4];
			float	e[16];

			void	print();
		};

		float	min(const float& a, const float& b);
		float	max(const float& a, const float& b);
		void	clamp(float& value, const float& mini, const float& maxi);

		mat4	translateMatrix(const vec3& pos);

		mat4	rotateXMatrix(const float& pitch);		//angle in rad
		mat4	rotateYMatrix(const float& yaw);		//angle in rad
		mat4	rotateZMatrix(const float& roll);		//angle in rad

		mat4	scaleMatrix(const vec3& scale);

		inline vec3 operator-(const vec3& v)
		{
			return { -v.x, -v.y, -v.z };
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
	}
}

using namespace Core::Math;