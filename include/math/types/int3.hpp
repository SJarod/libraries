#pragma once

struct int2;

struct int3
{
	union
	{
		struct { int x; int y; int z; };
		int2   xy;
		int    elem[3];
	};

	/**
	 * Access this vector's elements with [].
	 */
	inline int& operator[](const unsigned int i);

	/**
	 * Access this vector's elements with [].
	 */
	inline const int& operator[](const unsigned int i) const;
};

#include "math/types/int3.inl"