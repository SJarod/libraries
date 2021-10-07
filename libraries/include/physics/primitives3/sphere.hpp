#pragma once

#include "math/math.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Sphere
		{
		public:
			vec3	omega;
			float	radius;

			Sphere() = default;
			Sphere(const vec3& center, const float& radius);
		};
	}
}

using namespace Physics::Primitives3;