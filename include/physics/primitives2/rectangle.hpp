#pragma once

#include "math/math.hpp"

namespace Physics
{
    namespace Primitives2
    {
        class Rectangle
        {
        public:
            vec2    center = { 0.f, 0.f };
            float   width = 100.f;
            float   height = 100.f;
            float   angle = 0.f;

            Rectangle() = default;
            Rectangle(const float& x, const float& y, const float& width, const float& height);
        };
    }
}

using namespace Physics;