#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl harl;
	int	 option;

	option = 0;
	if (ac == 1)
		std::cout << "No parameter, default filter assumed" << std::endl;
	else
	{
		std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		while (option < 4)
		{
			if (!options[option].compare(av[1]))
				break;
			option++;
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
