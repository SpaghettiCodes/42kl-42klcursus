#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitpoint(10), erpoint(10), atkdmg(0)
{
	this->name = "Unnamed";
	std::cout << "Unnamed ClapTrap has arrived!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hitpoint(10), erpoint(10), atkdmg(0)
{
	this->name = name;
	std::cout << this->name << " has arrived!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &ori) : hitpoint(ori.hitpoint), erpoint(ori.erpoint), atkdmg(ori.atkdmg)
{
	(*this) = ori;
	std::cout << "A duplicate of " << this->name << " is created!" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &ori)
{
	this->name = ori.name;
	this->hitpoint = ori.hitpoint;
	this->erpoint = ori.erpoint;
	this->atkdmg = ori.atkdmg;

	std::cout << "Duplicated " << this->name << std::endl;
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
	if (hitpoint <= 0)
	{
		std::cout << name << " is already dead" << std::endl;
		return ;
	}
	hitpoint -= amount;
	if (hitpoint < 0)
		hitpoint = 0;
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