#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitCoinExchange	calculator;
	std::string		in_file;

	if (ac < 2)
	{
		std::cerr << "Error: Unable To Open" << std::endl;
		return (2);
	}
	else if (ac > 2)
		std::cerr << "More than one parameter given! Will only process the first!" << std::endl;

	calculator.generate_dictionary();
	calculator.make_calc(av[1]);
}
