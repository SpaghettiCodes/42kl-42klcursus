#include "DiamondTrap.hpp"
#include <iostream>

// halleluyah, i think i did it wrong;
int main()
{
	DiamondTrap diamond("test");
	diamond.print_stats();
	diamond.beRepaired(10);
	diamond.attack("amongus");
	diamond.guardGate();
	diamond.takeDamage(69);
	diamond.whoAmI();
}