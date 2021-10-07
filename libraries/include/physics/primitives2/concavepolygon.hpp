#pragma once

#include "physics/primitives2/convexpolygon.hpp"

#include <vector>

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

using namespace Physics::Primitives2;