#include "FlagTrap.hpp"

FlagTrap::FlagTrap()
{
	this->name = "Unnamed";
	hitpoint = 100;
	erpoint = 100;
	atkdmg = 30;

	std::cout << "For some reason, " << this->name << " became a FlagTrap" << std::endl;
}

FlagTrap::FlagTrap(std::string name)
{
	this->name = name;
	hitpoint = 100;
	erpoint = 100;
	atkdmg = 30;
	
	std::cout << "For some reason, " << this->name << " became a FlagTrap" << std::endl;
}

FlagTrap::~FlagTrap()
{
	std::cout << name << " sadly, retires being a FlagTrap" << std::endl;
}

void FlagTrap::highFivesGuys()
{
	std::cout << name << " gave a group high five with everyone!" << std::endl;
}