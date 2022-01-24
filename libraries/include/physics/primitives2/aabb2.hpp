#pragma once

#include "math/math.hpp"

namespace Physics
{
	namespace Primitives2
	{
		//TODO : add to the collision detection (SAT)
		class AABB2
		{
		public:
			vec2 min = { FLT_MAX, FLT_MAX };
			vec2 max = { FLT_MIN, FLT_MIN };
		};
	}
}

using namespace Physics;