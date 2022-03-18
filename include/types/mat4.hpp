#pragma once

struct float4;

struct mat4
{
	union
	{
		float4	row[4];
		float	elem[16];
	};

	//zero
	static const mat4 zo;
	//identity
	static const mat4 id;

	/**
	 * Access this matrix's row with [].
	 * 
	 * \param i
	 * \return row
	 */
	inline float4& operator[](const uint i);

	/**
	 * Access this matrix's row with [].
	 * 
	 * \param i
	 * \return row
	 */
	inline const float4& operator[](const uint i) const;
};

/**
 * mat4 * float4.
 */
inline float4 operator*(const mat4& m, const float4& f);

/**
 * mat4 * mat4.
 */
inline mat4 operator*(const mat4& m1, const mat4& m2);

#include "types/mat4.inl"