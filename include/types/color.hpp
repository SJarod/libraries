#pragma once

struct float4;
struct float3;

/**
 * Include mathematics.hpp before including types/color.hpp.
 */
struct Color
{
	union
	{
		struct { float r; float g; float b; float a; };
		float4   rgba;
		float3   rgb;
	};

	static const Color white;
	static const Color silver;
	static const Color gray;
	static const Color black;
	static const Color red;
	static const Color maroon;
	static const Color yellow;
	static const Color olive;
	static const Color lime;
	static const Color green;
	static const Color aqua;
	static const Color teal;
	static const Color blue;
	static const Color navy;
	static const Color fuchsia;
	static const Color purple;
};

#include "types/color.inl"