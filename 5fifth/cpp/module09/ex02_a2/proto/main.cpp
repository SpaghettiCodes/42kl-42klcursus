# include "PmergeMe.hpp"
# include <iostream>

int main(int ac, char **av)
{
	PmergeMe	stuff(ac, av);

	if (ac < 2)
		return (0);

	try {
		stuff.run();
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (69);
	}
}