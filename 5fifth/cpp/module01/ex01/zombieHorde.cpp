#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *ret;
	int	i = 0;

	// i have no idea how to use parametralize contructor for this
	// ok so there is no way of doing it aw :(
	if (N < 0)
	{
		std::cout << "Brother you want negative zombies???" << std::endl;
		return (NULL);
	}
	ret = new Zombie[N];
	while (i < N)
	{
		ret[i].setname(name);
		i++;
	}
	return (ret);
}