#pragma once

#include <vector>

#include "physics/primitives2/convexpolygon.hpp"

namespace Physics
{
	namespace Primitives2
	{
		/**
		 * A concave polygon will always have at least one interior angle.
		 */
		class ConcavePolygon
		{
		public:
			//array of convex polygons
			std::vector<ConvexPolygon>	polygons;

			/**
			 * Add a polygon to the array of convex polygons.
			 * 
			 * @param ConvexPolygon
			 */
			void addPolygon(const ConvexPolygon& convex);
		};
	}
}