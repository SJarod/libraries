#pragma once

#include "math/math.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Cylinder
		{
		public:
			vec3	center;
			float	height;
			float	radius;

			Quaternion q;

			Cylinder() = default;

			/**
			 * Create a cylinder.
			 * 
			 * @param center
			 * @param height
			 * @param radius
			 * @param q
			 */
			Cylinder(const vec3& center, const float& height, const float& radius, const Quaternion& q);
		};
	}
}