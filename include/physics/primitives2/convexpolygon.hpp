#pragma once

#include <vector>

#include "math/math.hpp"

namespace Physics
{
    namespace Primitives2
    {
        /**
         * A polygon is convex if every line that does not contain any edge intersects the polygon in at most two points.
         */
        class ConvexPolygon
        {
        public:
            //array of points
            std::vector<vec2>   points;
            vec2                center = { 0.f, 0.f };

            float               angle = 0.f;

            /**
             * Add a point to the array of points.
             * 
             * @param vec2
             */
            void addPoint(const vec2& pt);
        };
    }
}