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
	 * Access int3 elements.
	 */
	inline int& operator[](const unsigned int i);

	/**
	 * Access int3 elements.
	 */
	inline const int& operator[](const unsigned int i) const;
};

#include "math/types/int3.inl"