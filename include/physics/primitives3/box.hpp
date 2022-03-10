#pragma once

#include <vector>

#include "math/math.hpp"
#include "math/quaternion.hpp"

#include "physics/primitives3/aabb3.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Quad
		{
		public:
			vec3 center;
			vec2 extensions; //width, height

			Quaternion q;

			bool reverse = false;

			Quad() = default;
			Quad(const vec3& center, const vec2& extensions, const Quaternion& q, bool reverse);

			vec3 getNormal() const;
		};

		class Box
		{
		public:
			vec3 center;
			vec3 extensions; //width, heigth, length

			Quaternion q;

			Box() = default;
			Box(const vec3& center, const vec3& extensions, const Quaternion& q);

			AABB3	getAABB() const;
			void	getAttribs(std::vector<float>& vertices, std::vector<unsigned int>& indices) const;
		};

		class RoundedBox
		{
		public:
			vec3 center;
			vec4 extensions; //width, heigth, length, radius

			Quaternion q;

			RoundedBox() = default;
			RoundedBox(const vec3& center, const vec4& extensions, const Quaternion& q);
		};
	}
}

using namespace Physics;