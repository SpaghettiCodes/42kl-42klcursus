#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN			reverse_polish;
	std::string	input;

	if (ac < 2)
		return (2);
	input = av[1];
	try {
		reverse_polish.run(input);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
}