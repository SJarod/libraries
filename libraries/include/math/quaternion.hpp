#pragma once

#include "math/math.hpp"

namespace Core
{
	namespace Math
	{
		union Quaternion
		{
			struct { float a; float i; float j; float k; };

			Quaternion(float a, vec3 v);
		};
	}
}

using namespace Core::Math;