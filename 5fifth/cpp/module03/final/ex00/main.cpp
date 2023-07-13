#include "ClapTrap.hpp"

#include <iostream>

int main()
{
	// {
	// 	int turn;
	// 	turn = 0;
	// 	ClapTrap claptrap1("claptrap1");
	// 	ClapTrap claptrap2("claptrap2");

	// 	std::cout << "Turn " << turn << " : " ;
	// 	claptrap1.attack("claptrap2");
	// 	claptrap2.takeDamage(0);
	// 	turn++;

	// 	std::cout << "Turn " << turn << " : " ;
	// 	claptrap2.attack("claptrap1");
	// 	claptrap1.takeDamage(0);
	// 	turn++;

	// 	for (int i = 0; i < 8; i++, turn++)
	// 	{
	// 		std::cout << "Turn " << turn << " : " ;
	// 		claptrap1.beRepaired(5);
	// 	}

	// 	std::cout << "Turn " << turn << " : " ;
	// 	claptrap1.attack("claptrap2");
	// 	claptrap2.takeDamage(10);
	// 	turn++;

	// 	std::cout << "Turn " << turn << " : " ;
	// 	claptrap1.attack("claptrap2");
	// 	claptrap2.takeDamage(10);
	// 	turn++;
	// }

	{
		ClapTrap	c("c");

		c.attack("Random");
		c.takeDamage(2);
		for (int i = 0; i < 10; ++i)
			c.beRepaired(2);
		c.takeDamage(999);
		c.beRepaired(10);
	}

}