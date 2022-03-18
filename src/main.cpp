#include <iostream>

#include "utils/memleaks.hpp"

#include "mathematics.hpp"

int main()
{
	initMemleaksDebug();
	std::cout << "Hello world !" << std::endl;

	vec<double, 4> v = { 1.f, 2, 3.f, 4.f };

	getchar();
	return 0;
}