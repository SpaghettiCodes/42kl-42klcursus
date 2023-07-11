#include "Zombie.hpp"
#include <stdlib.h>

int main(int ac, char **av)
{
	Zombie *zombie_hoard;
	int i = 0, zombie_num;

	if (ac == 1)
		zombie_num = 10;
	else
		zombie_num = atoi(av[1]);
	zombie_hoard = zombieHorde(zombie_num, "One of the zombies in the hoard");

	if (zombie_hoard)
	{
		while (i < zombie_num)
		{
			std::cout << "Number " << i << ": ";
			zombie_hoard[i].annouce();
			i++;
		}
		// this one function deletes all the memory allocated
		delete []zombie_hoard;
	}
	// very cool
}