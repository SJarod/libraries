#include <cmath>
#include <cassert>

#include "types/float2.hpp"

inline const float2 float2::zo = {  0.f,  0.f };
inline const float2 float2::up = {  0.f,  1.f };
inline const float2 float2::dn = {  0.f, -1.f };
inline const float2 float2::le = { -1.f,  0.f };
inline const float2 float2::ri = {  1.f,  0.f };

inline float float2::sqrMag() const
{
	return x * x + y * y;
}

inline float float2::mag() const
{
	return sqrtf(sqrMag());
}

inline float2 float2::normalized() const
{
	return (*this) / mag();
}

inline float& float2::operator[](const uint i)
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline const float& float2::operator[](const uint i) const
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline float2 operator+(const float2& a, const float2& f)
{
	return { a.x + f.x, a.y + f.y };
}

float2 operator-(const float2& a, const float2& f)
{
	return { a.x - f.x, a.y - f.y };
}

inline float2 operator*(const float& f, const float2& a)
{
	return { f * a.x, f * a.y };
}

inline float2 operator/(const float2& a, const float& f)
{
	if (f == 0)
		return a;

	return { a.x / f, a.y / f };
}