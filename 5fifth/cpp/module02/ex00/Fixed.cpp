#include "Fixed.hpp"

// const int Fixed::no_frac_bits = 8;

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl; 
}

/* https://stackoverflow.com/questions/3105798/why-must-the-copy-assignment-operator-return-a-reference-const-reference
** Strictly speaking, the result of a copy assignment operator 
** doesn't need to return a reference, though to mimic the default 
** behavior the C++ compiler uses, it should return a non-const
** reference to the object that is assigned to (an implicitly
** generated copy assignment operator will return a non-const 
** reference - C++03: 12.8/10). I've seen a fair bit of code that 
** returns void from copy assignment overloads, and I can't recall 
** when that caused a serious problem. Returning void will prevent 
** users from 'assignment chaining' (a = b = c;), and will prevent 
** using the result of an assignment in a test expression, for example.
*/

/*
** Also, cant return a Fixed object because it will cause destructor and constructor to be called
*/

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
	// to recreate the pdf output, do this instead
	// *this = ori;
	// .. you know this miiiiight be a better idea
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