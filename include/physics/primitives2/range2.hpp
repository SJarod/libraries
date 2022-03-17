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

			/**
			 * Create a range with both min and max to the same value.
			 * 
			 * @param val
			 */
			Range2(const float& val);

			/**
			 * Create a range.
			 * 
			 * @param min
			 * @param max
			 */
			Range2(const float& min, const float& max);

			/**
			 * Projection of a point on a 2D segment.
			 * 
			 * @param pt
			 * @param dir
			 */
			Range2(const vec2& pt, const vec2& dir);

			/**
			 * Projection of a rectangle on a 2D segment.
			 * 
			 * @param rect
			 * @param dir
			 */
			Range2(const Rectangle& rect, const vec2& dir);

			/**
			 * Projection of a circle on a 2D segment.
			 * 
			 * @param cl
			 * @param dir
			 */
			Range2(const Circle& cl, const vec2& dir);

			/**
			 * Projection of a convex polygon on a 2D segment.
			 * 
			 * @param cx
			 * @param dir
			 */
			Range2(const ConvexPolygon& cx, const vec2& dir);

			/**
			 * Add a value to the range and adapt it.
			 * 
			 * @param val
			 */
			void add(const float& val);

			/**
			 * Length of the range.
			 * 
			 * @return 
			 */
			float length() const;

			/**
			 * Check if the range overriding with the specified range.
			 * 
			 * @param r
			 * @return 
			 */
			bool isCollidingWith(const Range2& r);
		};

		/**
		 * Merge 2 ranges.
		 */
		inline Range2 mergeRange2(const Range2& r1, const Range2& r2);
	}
}

inline Physics::Primitives2::Range2 Physics::Primitives2::mergeRange2(const Range2& r1, const Range2& r2)
{
	return Range2(Math::min(r1.min, r2.min), Math::max(r1.max, r2.max));
}