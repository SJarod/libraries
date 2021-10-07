#include "physics/primitives3/range3.hpp"

Physics::Primitives3::Range3::Range3(const float& min, const float& max)
	: min(min), max(max)
{
}

float Physics::Primitives3::Range3::length() const
{
	return max - min;
}