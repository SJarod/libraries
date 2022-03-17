#include <cassert>

#include "math/int2.hpp"

inline int& int2::operator[](const unsigned int i)
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}

inline const int& int2::operator[](const unsigned int i) const
{
	assert(("out of range", i < 2));
	return i == 0 ? x : y;
}