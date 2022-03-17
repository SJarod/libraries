#include <cassert>

#include "math/types/uint3.hpp"

inline uint& uint3::operator[](const unsigned int i)
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}

inline const uint& uint3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}