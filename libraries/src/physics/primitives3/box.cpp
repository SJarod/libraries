#include "physics/primitives3/box.hpp"
#include "physics/primitives3/range3.hpp"

Physics::Primitives3::Quad::Quad(const vec3& center, const vec2& extensions, const Quaternion& q, bool reverse)
	:center(center), extensions(extensions), q(q), reverse(reverse)
{
}

vec3 Physics::Primitives3::Quad::getNormal() const
{
	vec3 normal = rotateQ({ 0.f, 1.f, 0.f }, q);
	return reverse ? -normal : normal;
}

Physics::Primitives3::Box::Box(const vec3& center, const vec3& extensions, const Quaternion& q)
	:center(center), extensions(extensions), q(q)
{
}

AABB3 Physics::Primitives3::Box::getAABB() const
{
    //TODO sans les range mais avec vec3 min et vec3 max
    //min = vec3::min(vec3 a, vec3 b);
    //max = vec3::max(vec3 a, vec3 b);
    //ensuite on peut avoir les length :
    //lengthX = max.x - min.x
    //lengthY = max.y - min.y
    //lengthZ = max.z - min.z
    Range3 X(FLT_MAX, -FLT_MAX);
    Range3 Y(FLT_MAX, -FLT_MAX);
    Range3 Z(FLT_MAX, -FLT_MAX);

    vec3 p[8];
    p[0] = { 0.f + extensions.x / 2, 0.f + extensions.y / 2, 0.f + extensions.z / 2 };
    p[1] = { 0.f + extensions.x / 2, 0.f + extensions.y / 2, 0.f - extensions.z / 2 };
    p[2] = { 0.f + extensions.x / 2, 0.f - extensions.y / 2, 0.f - extensions.z / 2 };
    p[3] = { 0.f + extensions.x / 2, 0.f - extensions.y / 2, 0.f + extensions.z / 2 };
    p[4] = { 0.f - extensions.x / 2, 0.f + extensions.y / 2, 0.f + extensions.z / 2 };
    p[5] = { 0.f - extensions.x / 2, 0.f + extensions.y / 2, 0.f - extensions.z / 2 };
    p[6] = { 0.f - extensions.x / 2, 0.f - extensions.y / 2, 0.f - extensions.z / 2 };
    p[7] = { 0.f - extensions.x / 2, 0.f - extensions.y / 2, 0.f + extensions.z / 2 };

    p[0] = rotateQ(p[0], q);
    p[1] = rotateQ(p[1], q);
    p[2] = rotateQ(p[2], q);
    p[3] = rotateQ(p[3], q);
    p[4] = rotateQ(p[4], q);
    p[5] = rotateQ(p[5], q);
    p[6] = rotateQ(p[6], q);
    p[7] = rotateQ(p[7], q);

    p[0] += center;
    p[1] += center;
    p[2] += center;
    p[3] += center;
    p[4] += center;
    p[5] += center;
    p[6] += center;
    p[7] += center;

    for (int i = 0; i < 8; ++i)
    {
        X.min = min(X.min, p[i].x);
        X.max = max(X.max, p[i].x);

        Y.min = min(Y.min, p[i].y);
        Y.max = max(Y.max, p[i].y);

        Z.min = min(Z.min, p[i].z);
        Z.max = max(Z.max, p[i].z);
    }

    AABB3 aabb(center, { X.length(), Y.length(), Z.length() });
    return aabb;
}

void Physics::Primitives3::Box::getAttribs(std::vector<float>& vertices, std::vector<unsigned int>& indices) const
{
    float ver[] = {
        center.x + -extensions.x, center.y +  extensions.y, center.z +  extensions.z,
        center.x +  extensions.x, center.y +  extensions.y, center.z +  extensions.z,
        center.x +  extensions.x, center.y + -extensions.y, center.z +  extensions.z,
        center.x + -extensions.x, center.y + -extensions.y, center.z +  extensions.z,
        center.x + -extensions.x, center.y + -extensions.y, center.z + -extensions.z,
        center.x + -extensions.x, center.y +  extensions.y, center.z + -extensions.z,
        center.x +  extensions.x, center.y +  extensions.y, center.z + -extensions.z,
        center.x +  extensions.x, center.y + -extensions.y, center.z + -extensions.z,
    };

    for (int i = 0; i < 24; ++i)
    {
        vertices.push_back(ver[i]);
    }

    unsigned int ind[] = {
        0, 1, 3,
        1, 2, 3,
        5, 6, 4,
        6, 4, 7,
        0, 1, 5,
        1, 5, 6,
        2, 3, 4,
        2, 4, 7,
        0, 3, 4,
        0, 4, 5,
        1, 2, 7,
        1, 6, 7,
    };

    for (int i = 0; i < 36; ++i)
    {
        indices.push_back(ind[i]);
    }
}

Physics::Primitives3::RoundedBox::RoundedBox(const vec3& center, const vec4& extensions, const Quaternion& q)
    :center(center), extensions(extensions), q(q)
{
    float m = min(extensions.x, min(extensions.y, extensions.z));
    clamp(this->extensions.w, 0.f, m / 2);
}