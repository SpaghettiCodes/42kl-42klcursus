#include <iostream>
#include <string>
#include <stdlib.h>
#include "convert.hpp"

int	eprint(std::string error_msg)
{
	std::cout << error_msg << std::endl;
	return (error_msg.length());
}

bool	issign(char	in)
{ return (in == '+' || in == '-'); }

bool	onlynumeric(std::string &str)
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

bool	isdouble(std::string &input)
{
	// // im too lazy to reimplement atoi MAN PLEASE
	double check = strtod(input.c_str(), 0);

	if (check > int_limits::max() || check < int_limits::min())
		return (1);
	if (input.find('.') != std::string::npos)
		return (1);
	return (0);
}

int	pseudo_lit(std::string &input)
{
	if (!input.compare("-inff") || !input.compare("+inff") || !input.compare("nanf"))
		return (FLOAT);
	if (!input.compare("-inf") || !input.compare("+inf") || !input.compare("nan"))
		return (DOUBLE);
	return (0);
}

int	parse_input(std::string &input, int pseudo)
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

int main(int ac, char **av)
{
	if (ac < 2)
		return (eprint("Not Enough Arguments"));

	// conv_double(av[1]);
	std::string input = av[1];
	switch (parse_input(input, pseudo_lit(input)))
	{
		case (CHAR):
			std::cout << "char" << std::endl;
			conv_char(av[1]);
			break;
		case (INT):
			std::cout << "int" << std::endl;
			conv_int(av[1]);
			break;
		case (FLOAT):
			std::cout << "float" << std::endl;
			conv_float(av[1]);
			break;
		case (DOUBLE):
			std::cout << "double" << std::endl;
			conv_double(av[1]);
			break;
		default :
			std::cout << "error" << std::endl;
			error();
			break;
	}
}