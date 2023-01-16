#include "Harl.hpp"

// who the hell is harl


// error logging in c++ poggers no more printfs everywhere
// will still use printf tho

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
		std::string level;
		level = av[1];
		harl.complain(level);
	}
}