#include <cassert>

#include "math/float3.hpp"

#include "math/mat3.hpp"

inline const mat3 mat3::zo = { float3::zo, float3::zo, float3::zo };
inline const mat3 mat3::id = { float3::ri, float3::up, float3::bw };

inline float3& mat3::operator[](const unsigned int i)
{
	assert(("out of range", i < 3));
	return row[i];
}

inline const float3& mat3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 3));
	return row[i];
}