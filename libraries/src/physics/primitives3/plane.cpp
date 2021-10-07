#include "physics/primitives3/plane.hpp"

Physics::Primitives3::Plane::Plane(const vec3& n, const float& d)
{
	normal = n.normalized();
	this->d = d;
}

Physics::Primitives3::Plane::Plane(const vec3& n, const vec3& A)
{
	normal = n.normalized();
	d = dotProduct(A, normal);
}

Physics::Primitives3::Plane::Plane(const vec3& A, const vec3& B, const vec3& C)
{
	vec3 AB = B - A;
	vec3 AC = C - A;
	normal = crossProduct(AB, AC).normalized();
	d = dotProduct(A, normal);
}