#include <iostream>
#include <string>

void capitalize(std::string &str)
{
	long unsigned int	i;

	i = 0;
	while (i < str.size())
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return ;
}

int main(int ac, char **av)
{
	std::string print;

	if (ac == 1)
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