#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &ori);
		~Fixed();

		Fixed &operator=(const Fixed &ori);

		int	getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int raw_val;
		static const int no_frac_bits = 8;
};

#endif