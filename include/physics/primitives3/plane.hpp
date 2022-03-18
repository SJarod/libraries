#pragma once

#include "mathematics.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Plane
		{
		public:
			vec3	normal;
			//scalar offset to origin
			float	d;

			Plane() = default;

			/**
			 * Create a plane using a normal vector and the scalar offset.
			 * 
			 * @param n
			 * @param d
			 */
			Plane(const vec3& n, const float& d);

			/**
			 * Create a plane using a normal vector and a point from the plane.
			 * 
			 * @param n
			 * @param A
			 */
			Plane(const vec3& n, const vec3& A);

			/**
			 * Create a plane using 3 points from the plane.
			 * 
			 * @param A
			 * @param B
			 * @param C
			 */
			Plane(const vec3& A, const vec3& B, const vec3& C);
		};
	}
}