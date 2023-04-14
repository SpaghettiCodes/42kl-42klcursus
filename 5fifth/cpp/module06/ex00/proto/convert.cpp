#include "convert.hpp"

/*
** std::fixed – Fixed Floating-point notation : 
** It write floating-point values in fixed-point notation. 
** The value is represented with exactly as many digits in
** the decimal part as specified by the precision field 
** (precision) and with no exponent part.
*/

static void print_vals(char cval, int ival, float fval, double dval)
{
	if (dval <= char_limits::max() && dval >= char_limits::min())
	{
		if (isprint(cval))
			std::cout << "char : '" << cval << "'" << std::endl;
		else
			std::cout << "char : \"Non displayable\"" << std::endl;
	}
	else
		std::cout << "char : yeah bud no" << std::endl;

	if (dval <= int_limits::max() && dval >= int_limits::min())
		std::cout << "int : " << ival << std::endl;
	else
		std::cout << "int : yeah bud no" << std::endl;

	if (dval == (double) ival)
	{
		std::cout << "float : " << std::fixed << std::setprecision(1) << fval << "f" << std::endl;
		std::cout << "double : " << std::fixed << std::setprecision(1) << dval << std::endl;
	}
	else
	{
		std::cout << "float : " << fval << "f" << std::endl;
		std::cout << "double : " << dval << std::endl;
	}
}

void	conv_char(char *input)
{
	char val = input[0];
	print_vals(val, static_cast<int> (val), static_cast<float> (val), static_cast<double> (val));
}

void	conv_int(char *input)
{
	int val = atoi(input);
	print_vals(static_cast<char> (val), val, static_cast<float> (val), static_cast<double> (val));
}

void	conv_float(char *input)
{
	float val = strtof(input, 0);
	print_vals(static_cast<char> (val), static_cast<int> (val), val, static_cast<double> (val));
}

void	conv_double(char *input)
{
	double val = strtod(input, 0);
	print_vals(static_cast<char> (val), static_cast<int> (val), static_cast<float> (val), val);
}

void	error()
{
	std::cout << "char : huh?" << std::endl;
	std::cout << "int : huh?" << std::endl;
	std::cout << "float : huh?" << std::endl;
	std::cout << "double : huh?" << std::endl;
}