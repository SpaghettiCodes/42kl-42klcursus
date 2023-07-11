#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl;
	int	option;

	if (ac == 1)
		std::cout << "No parameter, default filter assumed" << std::endl;
	else
	{
		// hash the string value for switch
		std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (option = 0; option < 4; ++option)
		{
			if (!options[option].compare(av[1]))
				break;
		}
	}

	switch (option)
	{
		case 0 : 
			std::cout << "[DEBUG]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
			//fall through
		case 1 :
			std::cout << "[INFO]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
			//fall through
		case 2 :
			std::cout << "[WARNING]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
			//fall through
		case 3 : 
			std::cout << "[ERROR]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
