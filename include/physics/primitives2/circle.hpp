#pragma once

#include "math/math.hpp"

namespace Physics
{
    namespace Primitives2
    {
        class Circle
        {
        public:
            vec2    center;
            float   radius;

            Circle() = default;

            /**
             * Create a circle.
             * 
             * @param center
             * @param radius
             */
            Circle(const vec2& c, const float& r);
        };
    }
}