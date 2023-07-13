#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int main()
{
	ScavTrap s("scav");

	s.attack("random");
	s.guardGate();
	s.attack("random");
	s.takeDamage(20);
	s.beRepaired(20);
	s.guardGate();
}