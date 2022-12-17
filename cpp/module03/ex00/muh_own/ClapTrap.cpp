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

ClapTrap::ClapTrap(ClapTrap &ori) : hitpoint(10), erpoint(10), atkdmg(10)
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
	if (hitpoint > 0)
		std::cout << name << " has left" << std::endl;
	else
		std::cout << name << " disintegrated" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!health_check('a') || !er_check())
		return ;
	erpoint--;
	std::cout << name << " attacks " << target << ", causing " << atkdmg << " points of damage" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!health_check('b'))
		return ;
	hitpoint -= amount;
	std::cout << name << " taken " << amount << " damage!" << std::endl;
	std::cout << name << " health is now " << hitpoint << std::endl;
	if (hitpoint < 0)
		std::cout << name << " broke down!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!health_check('a') || !er_check())
		return ;
	erpoint--;
	hitpoint += amount;
	std::cout << name << " repairs itself for " << amount << " of hitpoints, for a total of " << hitpoint << std::endl;
}

void ClapTrap::ShowStats()
{
	std::cout << std::endl << "Name = " << name << std::endl;
	std::cout << "Hit Points = " << hitpoint << std::endl;
	std::cout << "Energy Points = " << erpoint << std::endl;
	std::cout << "Attack Damage = " << atkdmg << std::endl << std::endl;
}

bool	ClapTrap::health_check(char type)
{
	if (hitpoint <= 0)
	{
		if (type == 'a')
			std::cout << name << " is broken " << std::endl;
		else
			std::cout << name << " broken metal sizzles " << std::endl;
		return (0);
	}
	return (1);
}

bool	ClapTrap::er_check()
{
	if (erpoint <= 0)
	{
		std::cout << name << " has no energy point to do that " << std::endl;
		return (0);
	}
	return (1);
}
