#ifndef __FIXED_HPP__
#define __FIXED_HPP__

// Fixed point number is literally just integer, but all values after a certain point are all decimals
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

#endif