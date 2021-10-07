#pragma once

#include "math/math.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Segment
		{
		public:
			vec3 start, end;
			vec3 dir;

			Segment() = default;
			Segment(const vec3& s, const vec3& e);
		};
	}
}

using namespace Physics::Primitives3;