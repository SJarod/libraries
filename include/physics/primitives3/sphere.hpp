#pragma once

#include <vector>

#include "mathematics.hpp"

#define M_LON 50
#define M_LAT 25

namespace Physics
{
	namespace Primitives3
	{
		class Sphere
		{
		public:
			vec3	omega;
			float	radius;

			Sphere() = default;

			/**
			 * Create a sphere.
			 * 
			 * @param center
			 * @param radius
			 */
			Sphere(const vec3& center, const float& radius);

			/**
			 * Get sphere's vertices and indices for a sphere shaped mesh.
			 *
			 * @param vertices
			 * @param indices
			 */
			void getAttribs(std::vector<float>& vertices, std::vector<uint>& indices) const;
		};
	}
}