#pragma once

#include "math/math.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Plane
		{
		public:
			vec3	normal;
			float	d;	//scalar offset to origin

			Plane() = default;
			Plane(const vec3& n, const float& d);
			Plane(const vec3& n, const vec3& A);
			Plane(const vec3& A, const vec3& B, const vec3& C);
		};
	}
}

using namespace Physics;