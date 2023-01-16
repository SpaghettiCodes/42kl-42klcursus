#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "Unnamed";
	hitpoint = 100;
	erpoint = 100;
	atkdmg = 30;

	std::cout << "For some reason, " << this->name << " became a FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string new_name)
{
	name = new_name;
	hitpoint = 100;
	erpoint = 100;
	atkdmg = 30;
	
	std::cout << "For some reason, " << this->name << " became a FragTrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << name << " sadly, retires being a FragTrap" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << name << " gave a group high five with everyone!" << std::endl;
}