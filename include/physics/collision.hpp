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
		struct Collision3Info
		{
			vec3 intersection;
			vec3 normal;
		};

		namespace Collision2
		{
			using namespace Primitives2;

			bool pointPoint(const vec2& a, const vec2& b);
			bool pointRect(const vec2& v, const Rectangle& rect);
			bool pointCircle(const vec2& v, const Circle& cl);

			bool boxRect(const Rectangle& rect1, const Rectangle& rect2);

			bool circleRect(const Circle& cl, const Rectangle& rect);
			bool circleCircle(const Circle& cl1, const Circle& cl2);

			bool convexRect(const ConvexPolygon& cx, const Rectangle& rect);
			bool convexCircle(const ConvexPolygon& cx, const Circle& cl);
			bool convexConvex(const ConvexPolygon& cx1, const ConvexPolygon& cx2);
			bool concaveConcave(const ConcavePolygon& cv1, const ConcavePolygon& cv2);
		}

		namespace Collision3
		{
			using namespace Primitives3;

			bool segmentPlane(const Segment& seg, const Plane& pl, Collision3Info& cinfo);
			bool segmentSphere(const Segment& seg, const Sphere& sph, Collision3Info& cinfo);

			bool segmentCylinderInf(const Segment& seg, const Cylinder& cy, Collision3Info& cinfo);
			bool segmentCylinder(const Segment& seg, const Cylinder& cy, Collision3Info& cinfo);
			bool segmentCapsule(const Segment& seg, const Capsule& caps, Collision3Info& cinfo);

			bool segmentQuad(const Segment& seg, const Quad& qu, Collision3Info& cinfo);
			//radius is an offset for box's faces
			bool segmentBox(const Segment& seg, const Box& bx, Collision3Info& cinfo, const float& radius = 0.f);
			bool segmentRoundedBox(const Segment& seg, const RoundedBox& rbx, Collision3Info& cinfo);

			bool boxSphere(const Box& bx, const Sphere& sph);
			bool boxBox(const Box& bx1, const Box& bx2);
		}
	}
}

using namespace Physics::Collision;