#include <iostream>
#include <string>
#include <stdlib.h>
#include "ScalarConverter.hpp"


int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Not Enough Arguments";
		return(1);
	}

	std::string	input(av[1]);
	ScalarConverter::convert(input);
}