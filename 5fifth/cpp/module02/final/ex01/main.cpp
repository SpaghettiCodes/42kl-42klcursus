#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}

// int main(void)
// {
// 	// for (float i = -10; i < 10; i += 0.01)
// 	// {
// 	// 	Fixed a(i);
// 	// 	std::cout << "value = " << a << std::endl;
// 	// }

// 	for (int i = -88607; i < 88607; ++i)
// 	{
// 		Fixed a(i);
// 		std::cout << "value = " << a << std::endl;
// 	}
// }

// int main(void)
// {
// 	Fixed a(8388607);
// 	std::cout << "a = " << a.toInt() << std::endl;
// }