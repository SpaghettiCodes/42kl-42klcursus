#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : hitpoint(10), erpoint(10), atkdmg(10)
{
	std::cout << "Unnamed ClapTrap has arrived!" << std::endl;
	this->name = "\"Unnamed\"";
}

ClapTrap::ClapTrap(std::string name) : hitpoint(10), erpoint(10), atkdmg(10)
{
	this->name = name;
	std::cout << this->name << " has arrived!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &ori) : hitpoint(10), erpoint(10), atkdmg(10)
{
	this->name = ori.name;
	std::cout << "A duplicate of " << this->name << " is created!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &ori)
{
	this->name = ori.name;
	this->hitpoint = ori.hitpoint;
	this->erpoint = ori.erpoint;
	this->atkdmg = ori.atkdmg;
	std::cout << "A duplicate of " << this->name << " is created!" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " disappears" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitpoint <= 0 || erpoint <= 0)
	{
		std::cout << name <<  " cant do that" << std::endl;
		return ;
	}
	erpoint--;
	std::cout << name << " attacks " << target << ", causing " << atkdmg << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	// i have decided to allow negative healths
	hitpoint -= amount;
	std::cout << name << " taken " << amount << " damage!" << std::endl;
	if (hitpoint > 0)
		std::cout << name << " health is now " << hitpoint << std::endl;
	else
		std::cout << name << " broke down!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitpoint <= 0 || erpoint <= 0 )
	{
		std::cout << name <<  " cant do that" << std::endl;
		return ;
	}
	erpoint--;
	hitpoint += amount;
	std::cout << name << " repairs itself for " << amount << " of hitpoints, for a total of " << hitpoint << std::endl;
}