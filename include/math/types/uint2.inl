#include <cassert>

#include "math/types/uint2.hpp"

inline uint& uint2::operator[](const unsigned int i)
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline const uint& uint2::operator[](const unsigned int i) const
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}