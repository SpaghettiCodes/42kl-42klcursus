#include "ClapTrap.hpp"

#include <iostream>

int main()
{
	int turn;
	turn = 0;
	ClapTrap claptrap1("claptrap1");
	ClapTrap claptrap2("claptrap2");

	std::cout << "Turn " << turn << " : " ;
	claptrap1.attack("claptrap2");
	claptrap2.takeDamage(10);
	turn++;

	std::cout << "Turn " << turn << " : " ;
	claptrap2.attack("claptrap1");
	claptrap1.takeDamage(5);
	turn++;

	for (int i = 0; i < 8; i++, turn++)
	{
		std::cout << "Turn " << turn << " : " ;
		claptrap1.beRepaired(5);
	}

	std::cout << "Turn " << turn << " : " ;
	claptrap1.attack("claptrap2");
	claptrap2.takeDamage(10);
	turn++;

	std::cout << "Turn " << turn << " : " ;
	claptrap1.attack("claptrap2");
	// beautiful, taking damage even when claptrap1 isnt doing anything, classic
	claptrap2.takeDamage(10);
	turn++;

}