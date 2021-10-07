#include "physics/primitives3/aabb3.hpp"

Physics::Primitives3::AABB3::AABB3(const vec3& center, const vec3& extensions)
	: center(center), extensions(extensions)
{
}