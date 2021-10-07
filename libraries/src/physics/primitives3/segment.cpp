#include "physics/primitives3/segment.hpp"

Physics::Primitives3::Segment::Segment(const vec3& s, const vec3& e)
{
	start = s;
	end = e;
	dir = end - start;
}