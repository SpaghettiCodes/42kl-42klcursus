#ifndef __FIXED_HPP__
#define __FIXED_HPP__

// OH HELLLL NO I DONT WANNA HAVE FIXED POINT NUMBERS :SKULL :SKULL
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed &ori);
		~Fixed();

		Fixed &operator=(Fixed &ori);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int raw_val;
		// btw, static means all Fixed class share this number
		static const int no_frac_bits =  8;
};

#endif