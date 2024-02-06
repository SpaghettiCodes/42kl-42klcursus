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

	std::cout << "Getting data from data.csv..." << std::endl;
	if (!calculator.generate_dictionary())
		return (2);
	std::cout << "Done!\n" << std::endl;
	calculator.make_calc(av[1]);
}
