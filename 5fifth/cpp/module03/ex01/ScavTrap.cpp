#include "ScavTrap.hpp"
#include <iostream>

// derived classes has no initialization list
ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	hitpoint = 100;
	erpoint = 50;
	atkdmg = 20;

	std::cout << this->name << " upgraded to a ScavTrap" << std::endl;
}

ScavTrap::ScavTrap()
{
	this->name = "Unamed";
	hitpoint = 100;
	erpoint = 50;
	atkdmg = 20;

	std::cout << name << " upgraded to a ScavTrap" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " downgraded back to a ClapTrap" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitpoint <= 0 || erpoint <= 0)
	{
		std::cout << name <<  " cant do that" << std::endl;
		return ;
	}
	erpoint--;
	std::cout << name << " threw a gate at " << target << ", causing " << atkdmg << " points of damage" << std::endl;

}

void ScavTrap::guardGate()
{
	std::cout << name << " is in gatekeeping mode" << std::endl;
}
