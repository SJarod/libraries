#include <iostream>

#include "utils/memleaks.hpp"

#include "math/math.hpp"

int main()
{
	initMemleaksDebug();
	std::cout << "Hello world !" << std::endl;

	getchar();
	return 0;
}