#include "Point.hpp"

// ???? what???
Point::Point() : x(0), y(0)
{
}

Point::Point(Fixed const &x_val, Fixed const &y_val) : x(x_val), y(y_val)
{
}

Point::~Point() {}

Point::Point(Point const &ref) : x(ref.x), y(ref.y)
{
}

// ???? huh??
Point &Point::operator=(Point const &ref)
{
	(void) ref;
	return (*this);
}

bool Point::operator==(Point const &ref) const
{
	return (x == ref.x && y == ref.y);
}

Point Point::getmidpoint(Point const &a, Point const &b)
{
	Point ret((a.x + b.x) / 2, (a.y + b.y) / 2);
	return (ret);
}

// returns 1 if point is located at the left relative to ref, 0 if point is located at the right OR directly above relative to ref
// i dont know if this works
bool Point::isleft(Point const &ref) const
{
	return (ref.x > x);
}

Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}

std::ostream &operator<<(std::ostream &os, Point const &point)
{
	os << "( " << point.getX() << " , " << point.getY() << " )";
	return (os);
}