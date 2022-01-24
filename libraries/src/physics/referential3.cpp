#include "physics/referential3.hpp"

Physics::Referential3::Referential3(const vec3& origin)
	: origin(origin)
{
	i = { 1.f, 0.f, 0.f };
	j = { 0.f, 1.f, 0.f };
	k = { 0.f, 0.f, 1.f };
}

void Physics::Referential3::rotate(const Quaternion& q)
{
	i = Math::rotateQ(i, q);
	j = Math::rotateQ(j, q);
	k = Math::rotateQ(k, q);
}