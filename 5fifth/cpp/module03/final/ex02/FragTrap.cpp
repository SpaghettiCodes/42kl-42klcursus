#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "Unnamed";
	hitpoint = 100;
	erpoint = 100;
	atkdmg = 30;

	std::cout << "For some reason, " << this->name << " became a FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	hitpoint = 100;
	erpoint = 100;
	atkdmg = 30;
	
	std::cout << "For some reason, " << this->name << " became a FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap &ori) : ClapTrap()
{
	(*this) = ori;
	std::cout << "A duplicate of " << this->name << " is created!" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &ori)
{
	this->name = ori.name;
	hitpoint = ori.hitpoint;
	erpoint = ori.erpoint;
	atkdmg = ori.atkdmg;

	std::cout << "Duplicated " << this->name << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << name << " sadly, retires being a FragTrap" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << name << " wants to high-five with you guys!" << std::endl;
}