#include "Fixed.hpp"

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl; 
}

Fixed &Fixed::operator=(const Fixed &ori)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->raw_val = ori.getRawBits();
	return (*this);
}

Fixed::Fixed() : raw_val(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ori)
{
	std::cout << "Copy constructor called" << std::endl;
	raw_val = ori.getRawBits();
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (raw_val);
}

void	Fixed::setRawBits(int const raw)
{
	raw_val = raw;
}