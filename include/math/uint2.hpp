#pragma once

typedef unsigned int uint;

struct uint2
{
	union
	{
		struct { uint x; uint y; };
		uint   elem[2];
	};

	/**
	 * Access uint2 elements.
	 */
	inline uint& operator[](const unsigned int i);

	/**
	 * Access uint2 elements.
	 */
	inline const uint& operator[](const unsigned int i) const;
};

#include "math/uint2.hpp"