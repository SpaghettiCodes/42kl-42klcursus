#include "Harl.hpp"

// who the hell is harl
int main(int ac, char **av)
{
	Harl harl;

	if (ac == 1)
	{
		std::cout << "DEBUG = ";
		harl.complain("DEBUG");
		std::cout << "INFO = ";
		harl.complain("INFO");
		std::cout << "WARNING = ";
		harl.complain("WARNING");
		std::cout << "ERROR = ";
		harl.complain("ERROR");
	}
	else
	{	
		harl.complain(std::string(av[1]));
	}
}