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
	 * Access this vector's elements with [].
	 */
	inline uint& operator[](const unsigned int i);

	/**
	 * Access this vector's elements with [].
	 */
	inline const uint& operator[](const unsigned int i) const;
};

#include "math/types/uint2.inl"