#include <iostream>
#include <string>

void capitalize(std::string &str)
{
	long unsigned int	i;

	i = 0;
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
		int	i = 0;
		while (++i < ac)
			print.append(av[i]);
		capitalize(print);
		std::cout << print << std::endl;
	}
	return (0);
}