#include "Fixed.hpp"
#include <cmath>

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
	if (inum > 8388607 || inum < -8388607)
		std::cerr << "Warning = Will Exceed Max Fixed Point Value" << std::endl;
	this->raw_bits = raw_bits;
}

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

	ret = (float) raw_bits / (1<<8);
	return (ret);
}

int	Fixed::toInt(void) const
{
	int ret = 0;
	int raw_bits = this->raw_bits;

	ret = raw_bits>>(no_frac_bits);
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

std::ostream &operator<<(std::ostream& os, Fixed const &fixed)
{
	os << fixed.toFloat();	
	return (os);
}