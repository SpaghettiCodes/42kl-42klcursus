#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "Unnamed";
	FragTrap::hitpoint = 100;
	FragTrap::erpoint = 100;
	FragTrap::atkdmg = 30;

	ClapTrap::hitpoint = FragTrap::hitpoint;
	ClapTrap::erpoint = FragTrap::erpoint;
	ClapTrap::atkdmg = FragTrap::atkdmg;

	std::cout << "For some reason, " << this->name << " became a FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name)
{
	this->name = name;
	FragTrap::hitpoint = 100;
	FragTrap::erpoint = 100;
	FragTrap::atkdmg = 30;

	ClapTrap::hitpoint = FragTrap::hitpoint;
	ClapTrap::erpoint = FragTrap::erpoint;
	ClapTrap::atkdmg = FragTrap::atkdmg;

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
	FragTrap::hitpoint = ori.hitpoint;
	FragTrap::erpoint = ori.erpoint;
	FragTrap::atkdmg = ori.atkdmg;

	ClapTrap::hitpoint = FragTrap::hitpoint;
	ClapTrap::erpoint = FragTrap::erpoint;
	ClapTrap::atkdmg = FragTrap::atkdmg;

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