#include <iostream>

#include "utils/memleaks.hpp"

#include "math/math.hpp"

int main()
{
	initMemleaksDebug();
	std::cout << "Hello world !" << std::endl;

	float3 f = { 1.f, 1.f, 1.f };
	float3 fn = f.normalized();

	vec<float, 3> v(1.f);
	vec<float, 3> vn = v.normalized();

	getchar();
	return 0;
}