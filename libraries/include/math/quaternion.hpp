#pragma once

#include "math/math.hpp"

namespace Core
{
	namespace Math
	{
		namespace Complex
		{
			struct k;
			struct j;

			struct i
			{
				float	scalar;

				float	operator*(i i);	//i * i = -1
				k		operator*(j j);	//i * j = k
				j		operator*(k k);	//i * k = -j

				void	print();
			};

			struct j
			{
				float	scalar;

				k		operator*(i i);	//j * i = -k
				float	operator*(j j);	//j * j = -1
				i		operator*(k k);	//j * k = i

				void	print();
			};

			struct k
			{
				float	scalar;

				j		operator*(i i);	//k * i = j
				i		operator*(j j);	//k * j = -i
				float	operator*(k k);	//k * k = -1

				void	print();
			};
		}

		union Quaternion
		{
			struct	{ float a; Complex::i i; Complex::j j; Complex::k k; };
			vec4	v4;	//show quaternion as a vec4

			Quaternion() = default;
			//scalar, vector
			//scalar is angle in rad
			Quaternion(float a, vec3 v);

			Quaternion conjugate();
			Quaternion operator*(Quaternion q);
		};

		//quaternion rotation
		vec3 rotateQ(vec3 a, Quaternion q);
	}
}

using namespace Core::Math;