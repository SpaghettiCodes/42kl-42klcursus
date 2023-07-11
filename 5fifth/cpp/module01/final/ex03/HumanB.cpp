#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB()
{
	this->name = "Default man";
	this->weapon = NULL;
}

void HumanB::setWeapon(Weapon &new_weapon)
{
	weapon = &new_weapon;
}

void	HumanB::attack(void)
{
	if (weapon == NULL)
		std::cout << name << " has no weapon" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}