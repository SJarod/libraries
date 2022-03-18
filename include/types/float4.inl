#include <cmath>
#include <cassert>

#include "types/float4.hpp"

inline const float4 float4::zo = { 0.f, 0.f, 0.f, 0.f };

inline float float4::sqrMag() const
{
	return x * x + y * y + z * z + w * w;
}

inline float float4::mag() const
{
	return sqrtf(sqrMag());
}

inline float4 float4::normalized() const
{
	return (*this) / mag();
}

inline float& float4::operator[](const uint i)
{
	assert(("out of range", i < 4));
	return i == 3 ? w : xyz[i];
}

inline const float& float4::operator[](const uint i) const
{
	assert(("out of range", i < 4));
	return i == 3 ? w : xyz[i];
}

inline float4 operator/(const float4& a, const float& f)
{
	if (f == 0)
		return a;

	return { a.x / f, a.y / f, a.z / f, a.w / f };
}