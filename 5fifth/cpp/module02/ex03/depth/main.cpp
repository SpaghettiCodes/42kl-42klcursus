#include <iostream>
#include "bsp.hpp"

using namespace std;

int main( void ) 
{
	Point a(2, 1);
	// Point e(2, 1);
	Point b(3, 1);
	Point c(2.5f, 2);
	Point tofind(2.36f,1.4f);

	// Point d;

	// d = a;

	// Point midp = Point::getmidpoint(a, b);

	// std::cout << "Mid point: " << midp << std::endl;
	// std::cout << e << std::endl;
	// std::cout << (a == e) << std::endl;
	// std::cout << (b == a) << std::endl;


	// std::cout << "d should be (2 , 1) : " << d << " --- Probably isnt thanks to const" << std::endl;

	// std::cout << "Launching bsp" << std::endl;
	bool val = bsp(a, b, c, tofind);
	std::cout << "Point is in triangle: " << val << std::endl;
}