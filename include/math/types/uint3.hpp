#pragma once

typedef unsigned int uint;

struct uint2;

struct uint3
{
	union
	{
		struct { uint x; uint y; uint z; };
		uint2  xy;
		uint   elem[3];
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

#include "math/types/uint3.inl"