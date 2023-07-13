#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int main()
{
	int turn;
	turn = 0;

	ScavTrap claptrap1("ScavTrap1");
	ClapTrap claptrap2("ClapTrap2");
	FragTrap claptrap3("FragTrap3");

	std::cout << "Turn " << turn << " : " ;
	claptrap1.attack("ClapTrap2");
	std::cout << "But it missed!" << std::endl;
	claptrap3.attack("ScavTrap1");
	claptrap1.takeDamage(30);
	claptrap2.takeDamage(10);
	claptrap3.takeDamage(69);
	turn++;

	std::cout << "Turn " << turn << " : " ;
	claptrap2.attack("ScavTrap1");
	claptrap1.takeDamage(10);
	turn++;

	for (int i = 0; i < 8; i++, turn++)
	{
		std::cout << "Turn " << turn << " : " ;
		claptrap1.beRepaired(5);
	}

	for (int i = 0; i < 8; i++, turn++)
	{
		std::cout << "Turn " << turn << " : " ;
		claptrap3.beRepaired(5);
	}

	std::cout << "Turn " << turn << " : " ;
	claptrap1.attack("ClapTrap2");
	std::cout << "But it missed!" << std::endl;
	turn++;

	std::cout << "Turn " << turn << " : " ;
	claptrap1.attack("ClapTrap2");
	claptrap2.takeDamage(20);
	turn++;

	claptrap3.highFivesGuys(); 
	turn++;
}