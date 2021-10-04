#pragma once

#include "math/math.hpp"

namespace Core
{
	namespace Math
	{
		union Quaternion
		{
			struct	{ float a; float i; float j; float k; };
			vec4	v4;	//show quaternion as a vec4

			//scalar, vector
			//scalar is angle in rad
			Quaternion(float a, vec3 v);
		};

		//quaternion rotation
		vec3 rotateQ(vec3 a, Quaternion q);
	}
}

using namespace Core::Math;