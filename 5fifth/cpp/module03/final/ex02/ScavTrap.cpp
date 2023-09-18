#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : gatekeep(0)
{
	this->name = "Unamed";
	hitpoint = 100;
	erpoint = 50;
	atkdmg = 20;

	std::cout << name << " upgraded to a ScavTrap" << std::endl;
}

// derived classes has no initialization list
ScavTrap::ScavTrap(std::string name) : gatekeep(0)
{
	this->name = name;
	hitpoint = 100;
	erpoint = 50;
	atkdmg = 20;

	std::cout << this->name << " upgraded to a ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ori) : ClapTrap(), gatekeep(0)
{
	(*this) = ori;
	std::cout << "A duplicate of " << this->name << " is created!" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &ori)
{
	this->name = name;
	this->hitpoint = ori.hitpoint;
	this->erpoint = ori.erpoint;
	this->atkdmg = ori.atkdmg;
	this->gatekeep = ori.gatekeep;

	std::cout << "Duplicated " << this->name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " decided to stop being a ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitpoint <= 0 || erpoint <= 0)
	{
		std::cout << name <<  " cant do that" << std::endl;
		return ;
	}
	erpoint--;
	if (gatekeep)
		std::cout << name << " threw a gate at " << target << ", causing " << atkdmg << " points of damage" << std::endl;
	else
		std::cout << name << " scratched " << target << ", causing " << atkdmg << " points of damage" << std::endl;
}

void ScavTrap::guardGate()
{
	if (!gatekeep)
	{
		std::cout << name << " is in gatekeeping mode" << std::endl;
		gatekeep = 1;
	}
	else
		std::cout << name << " is already in gatekeeping mode" << std::endl;
}