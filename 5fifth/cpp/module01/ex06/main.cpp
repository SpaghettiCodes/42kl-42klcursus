#include "Harl.hpp"

// i actually dont know what does this exercise wants soooooooooo
int main(int ac, char **av)
{
	Harl harl;
	int	 option = 0;

	if (ac == 1)
		std::cout << "No parameter, default filter assumed" << std::endl;
	else
	{
		std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		for (option = 0; option < 4; ++option)
		{
			if (!options[option].compare(av[1]))
				break;
		}
	}
	// https://stackoverflow.com/questions/45129741/gcc-7-wimplicit-fallthrough-warnings-and-portable-way-to-clear-them
	// thanks stackoverflow very cool!
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
