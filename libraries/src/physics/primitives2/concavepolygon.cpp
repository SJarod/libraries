#include "physics/primitives2/concavepolygon.hpp"

void Physics::Primitives2::ConcavePolygon::addPolygon(const ConvexPolygon& convex)
{
	polygons.push_back(convex);
}