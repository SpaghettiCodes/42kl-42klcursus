#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN			reverse_polish;
	std::string	input;

	if (ac < 2)
		return (2);
	input = av[1];
	reverse_polish.run(input);
}