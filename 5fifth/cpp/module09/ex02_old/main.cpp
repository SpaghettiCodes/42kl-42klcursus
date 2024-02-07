#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	PmergeMe	stuff;

	if (ac < 2)
		return (0);

	try {
		stuff.runner(ac, av);
	}
	catch (std::exception &e) {
		std::cerr << "Error whoops" << std::endl;
		std::cerr << e.what() << std::endl;
		return (69);
	}
}