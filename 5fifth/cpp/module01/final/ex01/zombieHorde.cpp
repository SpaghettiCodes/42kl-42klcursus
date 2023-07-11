#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *ret;

	if (N < 0)
	{
		std::cerr << "Brother you want negative zombies???" << std::endl;
		return (NULL);
	}
	ret = new Zombie[N];
	for (int i = 0; i < N; ++i)
		ret[i].setname(name);
	return (ret);
}