#include "Fixed.hpp"
#include <cmath>

// floats

/* Floating point numbers (the point can float around the damn number)
** How does it work :
** this guy explains it pretty well ->
** https://fabiensanglard.net/floating_point_visually_explained/

** TL:DR
** The exponents seperates it into "Windows" of 1 - 2 - 4 - 8
** The mantissa represents the "Offsets from the window"
** So a "Window" of 2^(4) = 16 would be seperated to 8388608 (2^23) sections
** the mantissa shows where would the point be in the sections

(something like how in scientific notations m * (10 ^ n), m shows where the value would be within 10^n and 10^(n + 1))

** Floating points are represented by
** 			- 1 bit for the sign
**			- 8 bits for the exponents
**			- 23 bits for the mantissa (the actual binary digit of the floating point number)
**
** numbers are interpreted with (-1)^(S) * 1.(M) * 2^(E - 127)
** 
** Exponents
** everything below 01111111 (127) is considered negative (while 127 itself is 0)
** 10000000 (128) is considered to be 1
**			- 3 would be 0 10000000 10000000000000000000000
** 			- 0 in floating point has a special value and is set to be all bits 0
**			- there is a -0, which is the same as 0 but with the sign set to 1
** above is considered positive (255 - 128)
** this is so that we can express 2^(128 to -127)
**
** Mantissa
** that 23 bits allocated
** value from left to right is 2^(-1) -> 2^(-23)
** Matrissa is calculated with = 1 + (value);
** so 10000000000000000000000 would be 1 + (2^(-1)) = 1.5
** 10000000000000000000001 would be 1 + (2^(-1) + 2^(-23)) = 1.5000001192 +-
** 11000000000000000000000 would be 1 + (2^(-1) + 2^(-2)) = 1.75
*/

Fixed::Fixed() : raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &ori)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ori;
}

Fixed::Fixed(int const inum)
{
	std::cout << "Int constructor called" << std::endl;
	int raw_bits = inum<<(no_frac_bits);
	// if number is negative, put a 1 at the sign num;
	if (inum < 0)
		raw_bits = raw_bits | (1<<31);
	if (inum > 8388607 || inum < -8388607)
		std::cout << "Warning = Will Exceed Max Fixed Point Value" << std::endl;
	this->raw_bits = raw_bits;
	// thats about it
}

// no bitwise operation needed to convert float point to fixed
// since float point represents numbers in terms of
// N * 2^(E)
// and since we technically represent our numbers in the form of
// raw_bits / 2^(8)
// all we gotta do to convert a float point to fixed point is
// N * 2^(E) * 2^(8);
// then convert that value into integer to get the raw_bits
Fixed::Fixed(float const fnum)
{
	std::cout << "Float constructor called" << std::endl;
	raw_bits = roundf((fnum * (1<<8)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor Called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &ori)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_bits = ori.getRawBits();
	return (*this);
}

float Fixed::toFloat(void) const
{
	float	ret;

	// convert raw_bits into a float format N * 2^(0)
	// then divide 2^(8)
	// raw_bits * 2^(0) / 2^(8) = raw_bits * 2^(-8)
	ret = (float) raw_bits / (1<<8);
	return (ret);
}

int	Fixed::toInt(void) const
{
	int ret = 0;
	// this should make a copy of raw_bits (not affecting the original raw bits (well we technically have const already))
	int raw_bits = this->raw_bits;

	// check negative
	if (raw_bits & (1<<31))
	{
		// 511 = 111111111
		ret = (511<<(INTBITS - no_frac_bits - 1));
		// since we "saved" the negative integer value as its 2s complement, we can just yank that in
		ret = ret | raw_bits>>(no_frac_bits);
	}
	else
	{
		// bit shift to the right by 8 bits
		ret = raw_bits>>(no_frac_bits);
	}
	return (ret);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	raw_bits = raw;
}

// overloading << operator to support muh class
std::ostream &operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();	
	return (os);
}