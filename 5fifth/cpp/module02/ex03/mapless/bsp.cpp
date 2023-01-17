#include "Fixed.hpp"
#include "Point.hpp"
#include <fstream>

void	find_point( Point const a, Point const b, Point const c, Point const &point, bool &val)
{
	Point midp = Point::getmidpoint(b, c);

	if (midp == point)
		val = 1;
	if (((a == b) && (b == c)) || (midp == a) || (midp == b) || (midp == c) || val)
		return ;
	find_point( midp, a, c, point, val);
	find_point( midp, a, b, point, val);
}


bool invalid( Point const &a, Point const &b, Point const &c, Point const &point)
{
	if (a == point || b == point || c == point)
		return (1);
	return (0);
}

// a, b, c vertices of triangle, point -> to search
bool bsp( Point const a, Point const b, Point const c, Point const point)
{	
	bool val;
	std::cout << "In bsp" << std::endl;
	if (invalid(a, b, c, point))
		return 0;
	find_point(a, b, c, point, val);
	return (val);
}