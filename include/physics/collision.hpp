#pragma once

#include "math/math.hpp"

//primitives2
#include "physics/primitives2/rectangle.hpp"
#include "physics/primitives2/circle.hpp"
#include "physics/primitives2/convexpolygon.hpp"
#include "physics/primitives2/concavepolygon.hpp"

//primitives3
#include "physics/primitives3/segment.hpp"
#include "physics/primitives3/plane.hpp"
#include "physics/primitives3/sphere.hpp"
#include "physics/primitives3/cylinder.hpp"
#include "physics/primitives3/box.hpp"
#include "physics/primitives3/capsule.hpp"

namespace Physics
{
	namespace Collision
	{
		/**
		 * Output for 3D collisions.
		 */
		struct Collision3Info
		{
			vec3 intersection;
			vec3 normal;
		};

		namespace Collision2
		{
			using namespace Primitives2;

			/**
			 * Collision between 2 points.
			 */
			bool pointPoint(const vec2& a, const vec2& b);

			/**
			 * Collision between a point and a rectangle.
			 */
			bool pointRect(const vec2& v, const Rectangle& rect);

			/**
			 * Collision between a point and a circle.
			 */
			bool pointCircle(const vec2& v, const Circle& cl);

			/**
			 * Collision between 2 rectangles.
			 */
			bool rectRect(const Rectangle& rect1, const Rectangle& rect2);

			/**
			 * Collision between a circle and a rectangle.
			 */
			bool circleRect(const Circle& cl, const Rectangle& rect);

			/**
			 * Collision between 2 circles.
			 */
			bool circleCircle(const Circle& cl1, const Circle& cl2);

			/**
			 * Collision between a convex polygon and a rectangle.
			 */
			bool convexRect(const ConvexPolygon& cx, const Rectangle& rect);

			/**
			 * Collision between a convex polygon and a circle.
			 */
			bool convexCircle(const ConvexPolygon& cx, const Circle& cl);

			/**
			 * Collision between 2 convex polygons.
			 */
			bool convexConvex(const ConvexPolygon& cx1, const ConvexPolygon& cx2);

			/**
			 * Collision between 2 concave polygons.
			 */
			bool concaveConcave(const ConcavePolygon& cv1, const ConcavePolygon& cv2);
		}

		namespace Collision3
		{
			using namespace Primitives3;

			/**
			 * Collision between a segment and a plane.
			 */
			bool segmentPlane(const Segment& seg, const Plane& pl, Collision3Info& cinfo);

			/**
			 * Collision between a segment and a sphere.
			 */
			bool segmentSphere(const Segment& seg, const Sphere& sph, Collision3Info& cinfo);

			/**
			 * Collision between a segment and a infinite cylinder.
			 */
			bool segmentCylinderInf(const Segment& seg, const Cylinder& cy, Collision3Info& cinfo);

			/**
			 * Collision between a segment and a finite cylinder.
			 */
			bool segmentCylinder(const Segment& seg, const Cylinder& cy, Collision3Info& cinfo);

			/**
			 * Collision between a segment and a capsule.
			 */
			bool segmentCapsule(const Segment& seg, const Capsule& caps, Collision3Info& cinfo);

			/**
			 * Collision between a segment and a quad.
			 */
			bool segmentQuad(const Segment& seg, const Quad& qu, Collision3Info& cinfo);

			/**
			 * Collision between a segment and a box.
			 * Radius is an offset for box's faces.
			 */
			bool segmentBox(const Segment& seg, const Box& bx, Collision3Info& cinfo, const float& radius = 0.f);

			/**
			 * Collision between a segment and a rounded box.
			 */
			bool segmentRoundedBox(const Segment& seg, const RoundedBox& rbx, Collision3Info& cinfo);

			/**
			 * Collision between a box and a sphere.
			 */
			bool boxSphere(const Box& bx, const Sphere& sph);

			/**
			 * Collision between 2 boxes.
			 */
			bool boxBox(const Box& bx1, const Box& bx2);
		}
	}
}