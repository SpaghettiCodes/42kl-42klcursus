#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	// pdf code

	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	// return 0;

	Fixed a;
	Fixed b;

	a = 25.1213f;
	b = 2;
	std::cout << "a : " << a << std::endl;
	std::cout << "b : " << b << std::endl;

	std::cout << "a add b : " << a + b << std::endl;
	std::cout << "a minus b : " << a - b << std::endl;
	std::cout << "a multliply b : " << a * b << std::endl;
	std::cout << "a divide b : " << a / b << std::endl;

	std::cout << "pre plus plus before : " << ++a << std::endl;
	std::cout << "pre plus plus after : " << a << std::endl;
	std::cout << "post plus plus before : " << a++ << std::endl;
	std::cout << "post plus plus after : " << a << std::endl;
	std::cout << "pre min min before : " << --a << std::endl;
	std::cout << "pre min min after : " << a << std::endl;
	std::cout << "post min min before : " << a-- << std::endl;
	std::cout << "post min min after : " << a << std::endl;

	std::cout << "max : " << Fixed::max(a, b) << std::endl;
	std::cout << "min : " << Fixed::min(a, b) << std::endl;

	std::cout << "a is larger than b : " << (a > b) << std::endl;
	std::cout << "a is smaller than b : " << (a < b) << std::endl;
	std::cout << "a is larger or equal than b : " << (a >= b) << std::endl;
	std::cout << "a is smaller or equal than b : " << (a <= b) << std::endl;
	std::cout << "a is equal than b : " << (a == b) << std::endl;
	std::cout << "a is not equal than b : " << (a != b) << std::endl;
}