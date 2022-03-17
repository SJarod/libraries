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

		/**
		 * Create a 2D referential at the specified origin.
		 * 
		 * @param origin
		 */
		Referential2(const vec2& origin);

		/**
		 * Rotate the referential.
		 * 
		 * @param angle in degrees
		 */
		void rotate(const float& angle);

		/**
		 * Get the position of a local point in the global referential.
		 * 
		 * @param lPos
		 * @return 
		 */
		vec2 posLocalGlobal(const vec2& lPos) const;

		/**
		 * Get the position of a global point in the local referential.
		 * 
		 * @param gPos
		 * @return 
		 */
		vec2 posGlobalLocal(const vec2& gPos) const;

		/**
		 * Get a local vector in the global referential.
		 * 
		 * @param lVect
		 * @return 
		 */
		vec2 vectorLocalGlobal(const vec2& lVect) const;

		/**
		 * Get a global vector in the local referential.
		 * 
		 * @param gVect
		 * @return 
		 */
		vec2 vectorGlobalLocal(const vec2& gVect) const;
	};
}