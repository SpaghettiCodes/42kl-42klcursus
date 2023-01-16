#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(Point const &ref);
		Point(Fixed const &x_val, Fixed const &y_val);
		Point &operator=(Point const &ref);

		bool operator==(Point const &ref) const;

		static Point getmidpoint(Point const &a, Point const &b);
		bool isleft(Point const &ref) const;

		Fixed getX() const;
		Fixed getY() const;
		~Point();

	private:
		Fixed x;
		Fixed y;
};

std::ostream &operator<<(std::ostream &os, Point const &point);

#endif