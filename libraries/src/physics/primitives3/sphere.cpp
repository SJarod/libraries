#include "physics/primitives3/sphere.hpp"

Physics::Primitives3::Sphere::Sphere(const vec3& center, const float& radius)
	:omega(center), radius(radius)
{
}

void Physics::Primitives3::Sphere::getAttribs(std::vector<float>& vertices, std::vector<unsigned int>& indices) const
{
    float r = radius;

    float angleLon = 2.f * M_PI / M_LON;
    float angleLat = M_PI / M_LAT;

    for (int i = 0; i < M_LAT; ++i)
    {
        for (int j = 0; j < M_LON; ++j)
        {
            vertices.push_back(r * cosf(j * angleLon) * sinf(i * angleLat));
            vertices.push_back(r * cosf(i * angleLat));
            vertices.push_back(r * sinf(j * angleLon) * sinf(i * angleLat));
        }
    }

    for (int i = 0; i < vertices.size() / 3 - M_LON; ++i)
    {
        // disposition of vertex
        // i            i + 1
        // i + M_LON    i + M_LON + 1

        indices.push_back(i);
        indices.push_back(i + 1);
        indices.push_back(i + M_LON);

        if (i == vertices.size() / 3 - M_LON - 1)
            continue;

        indices.push_back(i + 1);
        indices.push_back(i + M_LON);
        indices.push_back(i + M_LON + 1);
    }
}