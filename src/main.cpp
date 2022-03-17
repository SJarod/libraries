#include <iostream>

#include "utils/memleaks.hpp"

#include "math/math.hpp"

int main()
{
	initMemleaksDebug();
	std::cout << "Hello world !" << std::endl;

	vec<uint, 10> v;
	v[0] = 1;
	v[2] = 21;

	getchar();
	return 0;
}