#include "ScalarConverter.hpp"

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
		std::cout << "char : Impossible" << std::endl;

	if (dval <= int_limits::max() && dval >= int_limits::min())
		std::cout << "int : " << ival << std::endl;
	else
		std::cout << "int : Impossible" << std::endl;

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

static void conv_char(std::string &input)
{
	char val = input[0];
	print_vals(val, static_cast<int> (val), static_cast<float> (val), static_cast<double> (val));
}

static void conv_int(std::string &input)
{
	int val = atoi(input.c_str());
	print_vals(static_cast<char> (val), val, static_cast<float> (val), static_cast<double> (val));
}

static void conv_float(std::string &input)
{
	float val = strtof(input.c_str(), 0);
	print_vals(static_cast<char> (val), static_cast<int> (val), val, static_cast<double> (val));
}

static void conv_double(std::string &input)
{
	double val = strtod(input.c_str(), 0);
	print_vals(static_cast<char> (val), static_cast<int> (val), static_cast<float> (val), val);
}

static void	error()
{
	std::cout << "char : huh?" << std::endl;
	std::cout << "int : huh?" << std::endl;
	std::cout << "float : huh?" << std::endl;
	std::cout << "double : huh?" << std::endl;
}

static bool	issign(char	in)
{ return (in == '+' || in == '-'); }

static bool	onlynumeric(std::string &str)
{
	bool has_dot = false;
	int end = str.length() - (str[str.length() - 1] == 'f');

	for (int i = issign(str[0]); i < end; i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (has_dot)
					return (false);
				has_dot = true;
			}
			else
				return (false);
		}
	}
	return (true);
}

static bool	isdouble(std::string &input)
{
	// // im too lazy to reimplement atoi MAN PLEASE
	double check = strtod(input.c_str(), 0);

	if (check > int_limits::max() || check < int_limits::min())
		return (1);
	if (input.find('.') != std::string::npos)
		return (1);
	return (0);
}

static int	pseudo_lit(std::string &input)
{
	if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (FLOAT);
	if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		return (DOUBLE);
	return (0);
}

static int	parse_input(std::string &input, int pseudo)
{
	if (pseudo)
		return pseudo;
	else if (input.length() == 1 && isalpha(input[0]))
		return CHAR;
	else if (!onlynumeric(input))
		return ERROR;
	else if (input[input.length() - 1] == 'f')
		return FLOAT;
	else if (isdouble(input))
		return DOUBLE;
	else
		return INT;
}

void	ScalarConverter::convert(std::string &input)
{
	switch (parse_input(input, pseudo_lit(input)))
	{
		case (CHAR):
			std::cout << "char" << std::endl;
			conv_char(input);
			break;
		case (INT):
			std::cout << "int" << std::endl;
			conv_int(input);
			break;
		case (FLOAT):
			std::cout << "float" << std::endl;
			conv_float(input);
			break;
		case (DOUBLE):
			std::cout << "double" << std::endl;
			conv_double(input);
			break;
		default :
			std::cout << "error" << std::endl;
			error();
			break;
	}
}