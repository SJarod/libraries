#include "physics/primitives3/sphere.hpp"

Physics::Primitives3::Sphere::Sphere(const vec3& center, const float& radius)
	:omega(center), radius(radius)
{
}