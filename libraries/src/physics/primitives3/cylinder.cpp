#include "physics/primitives3/cylinder.hpp"

Physics::Primitives3::Cylinder::Cylinder(const vec3& center, const float& height, const float& radius, const Quaternion& q)
    :center(center), height(height), radius(radius), q(q)
{
}