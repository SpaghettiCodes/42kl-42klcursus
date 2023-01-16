#include <iostream>
#include "bsp.hpp"

using namespace std;

// its way faster now

int main( void ) 
{
	Point a(5, 10);
	Point b(1, 2);
	Point c(3, 1);
	Point tofind(3.6f,5.4f);

	std::cout << "Launching bsp" << std::endl;
	bool val = bsp(a, b, c, tofind);
	std::cout << "Point is in triangle: " << val << std::endl;
}