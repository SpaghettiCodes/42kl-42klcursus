#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitCoinExchange	calculator;
	std::string		in_file;

	if (ac != 2)
	{
		std::cout << "Error: Unable To Open" << std::endl;
		return (2);
	}
	calculator.generate_dictionary();
	// calculator.print_dictionary();
	calculator.make_calc(av[1]);
}
