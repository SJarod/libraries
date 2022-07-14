#include <iostream>

#include "utils/memleaks.hpp"

#include "mathematics.hpp"

int main()
{
	std::cout << "Hello world !" << std::endl;

	vec<mat4, 2> v = { mat4::id, mat4::zo };

	std::cout << v << std::endl;

	vec<double, 4> d = { 1.f, 2, 3.f, 4.f };

	std::cout << d << std::endl;

	getchar();
	return 0;
}