#pragma once

#include "mathematics.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Capsule
		{
		public:
			vec3	center;
			float	height;
			float	radius;

			Quaternion q;

			Capsule() = default;

			/**
			 * Create a capsule.
			 * 
			 * @param center
			 * @param height
			 * @param radius
			 * @param q
			 */
			Capsule(const vec3& center, const float& height, const float& radius, const Quaternion& q);
		};
	}
}