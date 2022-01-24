#include "physics/referential2.hpp"

Physics::Referential2::Referential2(const vec2& origin)
	: origin(origin)
{
	i = { 1.f, 0.f };
	j = { 0.f, 1.f };
}

void Physics::Referential2::rotate(const float& angle)
{
	this->angle = angle;
	i = Math2::rotate(i, angle);
	j = Math2::rotate(j, angle);
}

vec2 Physics::Referential2::posLocalGlobal(const vec2& lPos) const
{
	vec2 gPos;
	gPos = origin + (lPos.x * i);
	gPos = gPos + (lPos.y * j);
	return gPos;
}

vec2 Physics::Referential2::posGlobalLocal(const vec2& gPos) const
{
	vec2 temp = gPos - origin;
	return { Math2::dotProduct(temp, i), Math2::dotProduct(temp, j) };
}

vec2 Physics::Referential2::vectorLocalGlobal(const vec2& lVect) const
{
	return (lVect.x * i) + (lVect.y * j);
}

vec2 Physics::Referential2::vectorGlobalLocal(const vec2& gVect) const
{
	return { Math2::dotProduct(gVect, i), Math2::dotProduct(gVect, j) };
}