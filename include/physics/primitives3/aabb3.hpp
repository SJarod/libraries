#pragma once

#include "mathematics.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class AABB3
		{
		public:
			vec3 center;
			vec3 extensions;

			AABB3() = default;

			/**
			 * Create an axis aligned bounding box.
			 * 
			 * @param center
			 * @param extensions
			 */
			AABB3(const vec3& center, const vec3& extensions);
		};
	}
}