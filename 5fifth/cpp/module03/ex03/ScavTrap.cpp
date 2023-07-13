#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->name = "Unamed";
	ScavTrap::hitpoint = 100;
	ScavTrap::erpoint = 50;
	ScavTrap::atkdmg = 20;

	std::cout << name << " upgraded to a ScavTrap" << std::endl;
}

// derived classes has no initialization list
ScavTrap::ScavTrap(std::string name)
{
	this->name = name;
	ScavTrap::hitpoint = 100;
	ScavTrap::erpoint = 50;
	ScavTrap::atkdmg = 20;

	std::cout << this->name << " upgraded to a ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ori) : ClapTrap()
{
	(*this) = ori;
	std::cout << "A duplicate of " << this->name << " is created!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ori)
{
	this->name = name;
	ScavTrap::hitpoint = ori.hitpoint;
	ScavTrap::erpoint = ori.erpoint;
	ScavTrap::atkdmg = ori.atkdmg;

	std::cout << "Duplicated " << this->name << std::endl;
	return (*this);
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
