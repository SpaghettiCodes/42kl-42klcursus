#include <iostream>
#include "bsp.hpp"

using namespace std;

// its way faster now

int main( void ) 
{
	Point a(5, 10);
	Point b(1, 2);
	Point c(3, 1);
	Point tofind(3, 6);

	std::cout << "To find = " << tofind << std::endl;

	// Point tofind(2.6f, 4.2f);
	// Point tofind(4, 6);
	// // Point tofind(3.6f,5.4f);
	// // Point tofind(2.6f, 4.3f); 


	// Point a(100, 100);
	// Point b(1, 1);
	// Point c(5, 5);
	// Point tofind(2, 2);

	std::cout << "Launching bsp" << std::endl;
	bool val = bsp(a, b, c, tofind);
	std::cout << "Point is in triangle: " << val << std::endl;
}