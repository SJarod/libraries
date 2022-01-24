#pragma once

#include "math/math.hpp"

#include <vector>

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
			Sphere(const vec3& center, const float& radius);

			void getAttribs(std::vector<float>& vertices, std::vector<unsigned int>& indices) const;
		};
	}
}

using namespace Physics;