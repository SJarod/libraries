#include "physics/primitives2/range2.hpp"

Physics::Primitives2::Range2::Range2(const float& val)
	: min(val), max(val)
{
}

Physics::Primitives2::Range2::Range2(const float& min, const float& max)
	: min(min), max(max)
{
}

Physics::Primitives2::Range2::Range2(const vec2& pt, const vec2& dir)
{
	min = Math2::dotProduct(pt, dir);
	max = min;
}

Physics::Primitives2::Range2::Range2(const Rectangle& rect, const vec2& dir)
{
	vec2 A, B, C, D;   //4 corners of rectangle
	float a, b, c, d;       //dotProduct

	A.x = rect.center.x - rect.width / 2;
	A.y = rect.center.x - rect.height / 2;
	a = Math2::dotProduct(A, dir);

	B.x = rect.center.x + rect.width / 2;
	B.y = rect.center.x - rect.height / 2;
	b = Math2::dotProduct(B, dir);

	C.x = rect.center.x - rect.width / 2;
	C.y = rect.center.x + rect.height / 2;
	c = Math2::dotProduct(C, dir);

	D.x = rect.center.x + rect.width / 2;
	D.y = rect.center.x + rect.height / 2;
	d = Math2::dotProduct(D, dir);

	min = Math::min(Math::min(a, b), Math::min(c, d));
	max = Math::max(Math::max(a, b), Math::max(c, d));
}

Physics::Primitives2::Range2::Range2(const Circle& cl, const vec2& dir)
{
	vec2 A, B;     //2 points of circle

	A.x = cl.center.x - cl.radius;
	A.y = cl.center.y;
	B.x = cl.center.x + cl.radius;
	B.y = cl.center.y;

	min = Math::min(Math2::dotProduct(A, dir), Math2::dotProduct(B, dir));
	max = Math::max(Math2::dotProduct(A, dir), Math2::dotProduct(B, dir));
}

Physics::Primitives2::Range2::Range2(const ConvexPolygon& cx, const vec2& dir)
{
	min = Math::min(Math2::dotProduct(cx.points[0], dir), Math2::dotProduct(cx.points[1], dir));
	max = min;

	for (int i = 0; i < cx.points.size(); ++i)
	{
		vec2 A, B;
		A = cx.points[i];

		int j = i + 1;
		B = cx.points[(int)(j % cx.points.size())];

		add(Math::min(Math2::dotProduct(A, dir), Math2::dotProduct(B, dir)));
		add(Math::max(Math2::dotProduct(A, dir), Math2::dotProduct(B, dir)));
	}
}

void Physics::Primitives2::Range2::add(const float& val)
{
	min = Math::min(val, min);
	max = Math::max(val, max);
}

float Physics::Primitives2::Range2::length() const
{
	return max - min;
}

bool Physics::Primitives2::Range2::isCollidingWith(const Range2& r)
{
	if (min < r.min)
		return r.min <= max;

	if (r.min < min)
		return min <= r.max;

	return min == r.min;
}