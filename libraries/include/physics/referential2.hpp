#pragma once

#include "math/math.hpp"

namespace Physics
{
	class Referential2
	{
	public:
		vec2 origin;
		vec2 i, j;

		float angle = 0.f;

		Referential2() = default;
		Referential2(const vec2& origin);

		//angle in degrees
		void rotate(const float& angle);

		//changes referential
		vec2 posLocalGlobal(const vec2& lPos) const;
		vec2 posGlobalLocal(const vec2& gPos) const;

		vec2 vectorLocalGlobal(const vec2& lVect) const;
		vec2 vectorGlobalLocal(const vec2& gVect) const;
	};
}

using namespace Physics;