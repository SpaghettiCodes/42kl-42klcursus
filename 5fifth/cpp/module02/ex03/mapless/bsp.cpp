#include "Fixed.hpp"
#include "Point.hpp"

void	find_point( Point const a, Point const b, Point const c, Point const &point, bool &val)
{
	Point midp = Point::getmidpoint(b, c);

	if (midp == point)
		val = 1;
	if ( val || ((a == b) && (b == c)) || (midp == a) || (midp == b) || (midp == c))
		return ;
	find_point( midp, a, c, point, val);
	if (!val)
		find_point( midp, a, b, point, val);
}


bool invalid( Point const &a, Point const &b, Point const &c, Point const &point)
{
	if (a == point || b == point || c == point)
		return (1);
	return (0);
}

bool in_sameline( Point const one, Point const two, Point const point)
{
	float	gradient;
	float	intercept;

	if ((one.getX() - two.getX()) == 0)
		return (point.getX() == one.getX());
	gradient = ((one.getY() - two.getY()) / (one.getX() - two.getX())).toFloat();
	intercept = two.getY().toFloat() - (gradient * two.getX().toFloat());
	return ((point.getY().toFloat() - (gradient * point.getX().toFloat())) == intercept);
}

bool in_edge( Point const a, Point const b, Point const c, Point const point)
{
	return (in_sameline(a, b, point) || in_sameline(b, c, point) || in_sameline(c, a, point));
}

// a, b, c vertices of triangle, point -> to search
bool bsp( Point const a, Point const b, Point const c, Point const point)
{	
	bool val;
	std::cout << "In bsp" << std::endl;
	if (invalid(a, b, c, point) || in_edge(a, b, c, point))
		return 0;
	find_point(a, b, c, point, val);
	if (!val)
		find_point(c, b, a, point, val);
	if (!val)
		find_point(b, a, c, point, val);
	return (val);
}