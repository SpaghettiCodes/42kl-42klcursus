#include "ClapTrap.hpp"

#include <iostream>

int main()
{
	int turn;
	turn = 0;
	ClapTrap pizza("pizza");
	ClapTrap burrito("buritto");

	pizza.ShowStats();
	burrito.ShowStats();

	std::cout << "Turn " << turn << " : " ;
	pizza.attack("burrito");
	burrito.takeDamage(10);
	turn++;

	std::cout << "Turn " << turn << " : " ;
	burrito.attack("pizza");
	pizza.takeDamage(5);
	turn++;

	for (int i = 0; i < 8; i++, turn++)
	{
		std::cout << "Turn " << turn << " : " ;
		pizza.beRepaired(5);
	}

	std::cout << "Turn " << turn << " : " ;
	pizza.attack("burrito");
	burrito.takeDamage(10);
	turn++;

	std::cout << "Turn " << turn << " : " ;
	pizza.attack("burrito");
	burrito.takeDamage(10);
	turn++;

	pizza.ShowStats();
	burrito.ShowStats();
}