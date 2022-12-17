#include <iostream>
#include "bsp.hpp"

using namespace std;


// pros - very accurate
// cons - very resource eating
//		- there is a very small chance that the point would not be found (Thanks fixed point)
// and fucking finding the area // using vectors is WAYY easier
// also there is the CONST problem, did i not mention the CONST problem

int main( void ) 
{
	Point a(5, 10);
	Point b(1, 2);
	Point c(3, 1);
	Point tofind(3.17f,4.33f);

	std::cout << "Launching bsp" << std::endl;
	std::cout << "Point to find = " << tofind << std::endl;
	bool val = bsp(a, b, c, tofind);
	std::cout << "Point is in triangle: " << val << std::endl;
}