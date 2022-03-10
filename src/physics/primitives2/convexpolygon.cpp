#include "physics/primitives2/convexpolygon.hpp"

void Physics::Primitives2::ConvexPolygon::addPoint(const vec2& pt)
{
	points.push_back(pt);
}