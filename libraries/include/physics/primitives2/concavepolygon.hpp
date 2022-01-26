#pragma once

#include <vector>

#include "physics/primitives2/convexpolygon.hpp"

namespace Physics
{
	namespace Primitives2
	{
		class ConcavePolygon
		{
		public:
			std::vector<ConvexPolygon>	polygons;	//array of convex polygons

			void addPolygon(const ConvexPolygon& convex);
		};
	}
}

using namespace Physics;