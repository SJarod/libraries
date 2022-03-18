#pragma once

#include "mathematics.hpp"

namespace Physics
{
	class Referential3
	{
	public:
		vec3 origin;
		vec3 i, j, k;

		Referential3() = default;

		/**
		 * Create a 3D referential at the specified origin.
		 * 
		 * @param origin
		 */
		Referential3(const vec3& origin);

		/**
		 * Rotate the referential using a quaternion.
		 * 
		 * @param q
		 */
		void rotate(const Quaternion& q);
	};
}