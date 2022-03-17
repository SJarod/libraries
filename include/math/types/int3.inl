#include <cassert>

#include "math/types/int3.hpp"

inline int& int3::operator[](const unsigned int i)
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}

inline const int& int3::operator[](const unsigned int i) const
{
	assert(("out of range", i < 3));
	return i == 0 ? i == 1 ? y : x : z;
}