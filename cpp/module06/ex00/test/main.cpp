#include <iostream>
#include <string>
#include <stdlib.h>

int	eprint(std::string error_msg)
{
	std::cout << error_msg << std::endl;
	return (error_msg.length());
}

#define ERROR 0
#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4

bool	onlynumeric(std::string &str, bool &is_double, int end)
{
	for (int i = 0; i < end; i++)
	{
		if (!isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
		{
			if (is_double)
				return (false);
			is_double = true;
		}
	}
	return (true);
}

int	parse_input(std::string input)
{
	bool is_double = false;

	if (input.length() == 1)
		return CHAR;

	if (input[input.length() - 1] == 'f')
	{
		if (onlynumeric(input, is_double, input.length() - 1))
			return FLOAT;		
		else
			return ERROR;
	}

	if (!onlynumeric(input, is_double, input.length()))
		return ERROR;

	if (is_double)
		return DOUBLE;
	else
		return INT;
}

int main(int ac, char **av)
{
	if (ac < 2)
		return (eprint("Not Enough Arguments"));


	std::cout << parse_input(av[1]) << std::endl;

	// switch (parse_input(av[1]))
	// {
	// 	case (CHAR):

	// 	case (INT):

	// 	case (FLOAT):

	// 	case (DOUBLE):

	// 	default :

	// }
}