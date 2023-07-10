#include <iostream>
#include <string>

void capitalize(std::string &str)
{
	for (long unsigned int i = 0; i < str.size(); ++i)
		str[i] = std::toupper(str[i]);
	return ;
}

int main(int ac, char **av)
{
	std::string print;

	if (ac < 2)
		std::cout << "* LOUD AND UNBREARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < ac; ++i)
			print.append(av[i]);
		capitalize(print);
		std::cout << print << std::endl;
	}
	return (0);
}