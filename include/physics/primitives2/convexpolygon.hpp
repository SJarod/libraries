#pragma once

#include <vector>

#include "math/math.hpp"

namespace Physics
{
    namespace Primitives2
    {
        class ConvexPolygon
        {
        public:
            std::vector<vec2>   points;    //array of points
            vec2                center = { 0.f, 0.f };

            float               angle = 0.f;

            void addPoint(const vec2& pt);
        };
    }
}

using namespace Physics;