#include <cmath>
#include <cassert>

#include "math/quaternion.hpp"

#include "math/float3.hpp"

inline const float3 float3::zo = {  0.f,  0.f,  0.f };
inline const float3 float3::up = {  0.f,  1.f,  0.f };
inline const float3 float3::dn = {  0.f, -1.f,  0.f };
inline const float3 float3::le = { -1.f,  0.f,  0.f };
inline const float3 float3::ri = {  1.f,  0.f,  0.f };
inline const float3 float3::fw = {  0.f,  0.f, -1.f };
inline const float3 float3::bw = {  0.f,  0.f,  1.f };

inline Quaternion float3::q() const
{
	Quaternion q = { 0, x, y, z };
	return q;
}

inline float float3::sqrMag() const
{
	return x * x + y * y + z * z;
}

inline float float3::mag() const
{
	return sqrtf(sqrMag());
}

inline float3 float3::normalized() const
{
	return (*this) / mag();
}

inline float& float3::operator[](const unsigned int i)
{
	assert(("out of range", i < 3));
	return i == 2 ? z : xy[i];
}

inline const float& float3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 3));
	return i == 2 ? z : xy[i];
}

inline float3 operator-(const float3& a)
{
	return { -a.x, -a.y, -a.z };
}

inline float3 operator-(const float3& a, const float3& f)
{
	return { a.x - f.x, a.y - f.y, a.z - f.z };
}

inline float3 operator*(const float& f, const float3& a)
{
	return { f * a.x, f * a.y, f * a.z };
}

inline float3 operator/(const float3& a, const float& f)
{
	if (f == 0)
		return a;

	return { a.x / f, a.y / f, a.z / f };
}

inline void operator+=(float3& a, const float3& f)
{
	a.x += f.x;
	a.y += f.y;
	a.z += f.z;
}