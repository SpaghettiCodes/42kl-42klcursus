#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const &ori);
		Fixed(int const inum);
		Fixed(float const fnum);
		~Fixed();
		Fixed &operator=(Fixed const &fixed);

		bool operator<(Fixed const &comparing) const;
		bool operator>(Fixed const &comparing) const;
		bool operator>=(Fixed const &comparing) const;
		bool operator<=(Fixed const &comparing) const;
		bool operator==(Fixed const &comparing) const;
		bool operator!=(Fixed const &comparing) const;

		Fixed operator+(Fixed const &toadd) const;
		Fixed operator-(Fixed const &tominus) const;
		Fixed operator*(Fixed const &tomulti) const;
		Fixed operator/(Fixed const &todiv) const;

		// prefix
		Fixed &operator++();
		Fixed &operator--();
		// postfix
		// that int is just to distinguish between pre and postfix increment
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &max(Fixed &one, Fixed &two);
		static Fixed &min(Fixed &one, Fixed &two);
		// return a constant reference because
			// - the parameters are constant, if you return a non-constant reference, you are telling the system you
			// MIGHT change the content, which is not what const want
			// - constant reference tell the system that you want a reference to that variable and you will not change anything
		static Fixed const &max(Fixed const &one, Fixed const &two);
		static Fixed const &min(Fixed const &one, Fixed const &two);

		float toFloat(void) const;
		int	toInt(void) const;
		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int raw_bits;
		// btw, static means all Fixed class share this number
		static const int no_frac_bits =  8;
};

std::ostream &operator<<(std::ostream& os, Fixed const &fixed);
#define INTBITS 32

#endif