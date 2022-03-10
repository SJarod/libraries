#include "physics/primitives2/rectangle.hpp"

Physics::Primitives2::Rectangle::Rectangle(const float& x, const float& y, const float& width, const float& height)
	: width(width), height(height)
{
	center = { x, y };
}