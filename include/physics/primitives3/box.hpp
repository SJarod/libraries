#pragma once

#include <vector>

#include "mathematics.hpp"
#include "physics/primitives3/aabb3.hpp"

namespace Physics
{
	namespace Primitives3
	{
		class Quad
		{
		public:
			vec3 center;
			//width, height
			vec2 extensions;

			Quaternion q;

			bool reverse = false;

			Quad() = default;

			/**
			 * Create a quad.
			 * 
			 * @param center
			 * @param extensions
			 * @param q
			 * @param reverse : quad's normal direction
			 */
			Quad(const vec3& center, const vec2& extensions, const Quaternion& q, bool reverse);

			/**
			 * Get quad's normal.
			 * 
			 * @return vec3
			 */
			vec3 getNormal() const;
		};

		class Box
		{
		public:
			vec3 center;
			//width, height, length
			vec3 extensions;

			Quaternion q;

			Box() = default;

			/**
			 * Create a cube/box.
			 * 
			 * @param center
			 * @param extensions
			 * @param q
			 */
			Box(const vec3& center, const vec3& extensions, const Quaternion& q);

			/**
			 * Get box's AABB.
			 * 
			 * @return 
			 */
			AABB3	getAABB() const;

			/**
			 * Get box's vertices and indices for a cube shaped mesh.
			 * 
			 * @param vertices
			 * @param indices
			 */
			void	getAttribs(std::vector<float>& vertices, std::vector<uint>& indices) const;
		};

		class RoundedBox
		{
		public:
			vec3 center;
			//width, height, length, radius
			vec4 extensions;

			Quaternion q;

			RoundedBox() = default;

			/**
			 * Create a rounded box.
			 * 
			 * @param center
			 * @param extensions
			 * @param q
			 */
			RoundedBox(const vec3& center, const vec4& extensions, const Quaternion& q);
		};
	}
}