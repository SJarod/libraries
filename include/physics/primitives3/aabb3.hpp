#pragma once

#include "math/math.hpp"

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
			AABB3(const vec3& center, const vec3& extensions);
		};
	}
}

using namespace Physics;