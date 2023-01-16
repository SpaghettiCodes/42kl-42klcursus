#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : raw_bits(0) {}

Fixed::Fixed(Fixed const &ori)
{
	*this = ori;
}

Fixed::Fixed(int const inum)
{
	int raw_bits = inum<<(no_frac_bits);
	if (inum < 0)
		raw_bits = raw_bits | (1<<31);

	this->raw_bits = raw_bits;
}

Fixed::Fixed(float const fnum)
{
	raw_bits = roundf((fnum * (1<<8)));
}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(Fixed const &ori)
{
	this->raw_bits = ori.getRawBits();
	return (*this);
}

bool Fixed::operator<(Fixed const &comparing) const
{
	return (raw_bits < comparing.raw_bits);
}

bool Fixed::operator>(Fixed const &comparing) const
{
	return (raw_bits > comparing.raw_bits);
}

bool Fixed::operator<=(Fixed const &comparing) const
{
	return (raw_bits <= comparing.raw_bits);
}

bool Fixed::operator>=(Fixed const &comparing) const
{
	return (raw_bits >= comparing.raw_bits);
}

bool Fixed::operator==(Fixed const &comparing) const
{
	return (raw_bits == comparing.raw_bits);
}

bool Fixed::operator!=(Fixed const &comparing) const
{
	return (raw_bits != comparing.raw_bits);
}

Fixed Fixed::operator+(Fixed const &toadd) const
{
	Fixed ret;

	ret.setRawBits(raw_bits + toadd.raw_bits);
	return (ret);
}

Fixed Fixed::operator-(Fixed const &tominus) const
{
	Fixed ret;

	ret.setRawBits(raw_bits - tominus.raw_bits);
	return (ret);
}

// why cant we just multiply the raw_bits 
// unlike addition and subtraction, multiplication and division is VERY different if you have decimals
Fixed Fixed::operator*(Fixed const &tomulti) const
{
	Fixed ret = (toFloat() * tomulti.toFloat());
	return (ret);
}

Fixed Fixed::operator/(Fixed const &todiv) const
{
	Fixed ret = (toFloat() / todiv.toFloat());
	return (ret);
}

Fixed &Fixed::operator++()
{
	this->raw_bits++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->raw_bits--;
	return (*this);
}

// postfix operator works by incrememnting the initial value
// then return the original value
Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++*this;
	return (temp);
}

Fixed Fixed::operator--(int) 
{
	Fixed temp = *this;
	--*this;
	return (temp);
}

float Fixed::toFloat(void) const
{
	return ((float) raw_bits / (float) (1<<8));
}

int	Fixed::toInt(void) const
{
	int ret = 0;

	if (raw_bits & (1<<31))
		ret = (511<<(INTBITS - no_frac_bits - 1));
	ret = ret | raw_bits>>(no_frac_bits);
	return (ret);
}

int		Fixed::getRawBits(void) const
{
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

Fixed &Fixed::max(Fixed &one, Fixed &two)
{
	if (one > two)
		return (one);
	return (two);
}

Fixed &Fixed::min(Fixed &one, Fixed &two)
{
	if (one < two)
		return (one);
	return (two);
}

Fixed const &Fixed::max(Fixed const &one, Fixed const &two)
{
	if (one > two)
		return (one);
	return (two);
}

Fixed const &Fixed::min(Fixed const &one, Fixed const &two)
{
	if (one < two)
		return (one);
	return (two);
}