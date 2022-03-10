#pragma once

#include "math/math.hpp"

#include "physics/primitives2/rectangle.hpp"
#include "physics/primitives2/circle.hpp"
#include "physics/primitives2/convexpolygon.hpp"

namespace Physics
{
	namespace Primitives2
	{
		class Range2
		{
		public:
			float min;
			float max;

			Range2() = default;
			//init min and max to same value
			Range2(const float& val);
			Range2(const float& min, const float& max);
			//projection of a vec2 on a vector
			Range2(const vec2& pt, const vec2& dir);
			//projection of a rectangle on a vector
			Range2(const Rectangle& rect, const vec2& dir);
			//projection of a circle on a vector
			Range2(const Circle& cl, const vec2& dir);
			//projection of a convex polygon on a vector
			Range2(const ConvexPolygon& cx, const vec2& dir);

			void	add(const float& val);
			float	length() const;

			bool	isCollidingWith(const Range2& r);
		};

		inline Range2 mergeRange2(const Range2& r1, const Range2& r2);
	}
}

using namespace Physics;

inline Physics::Primitives2::Range2 Physics::Primitives2::mergeRange2(const Range2& r1, const Range2& r2)
{
	return Range2(Math::min(r1.min, r2.min), Math::max(r1.max, r2.max));
}