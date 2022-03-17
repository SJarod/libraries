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
	 * Access uint3 elements.
	 */
	inline uint& operator[](const unsigned int i);

	/**
	 * Access uint3 elements.
	 */
	inline const uint& operator[](const unsigned int i) const;
};

#include "math/types/uint3.inl"