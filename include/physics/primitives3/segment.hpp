#pragma once

#include "mathematics.hpp"

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

			/**
			 * Create a 3D segment using 2 points.
			 * 
			 * @param s
			 * @param e
			 */
			Segment(const vec3& s, const vec3& e);
		};
	}
}