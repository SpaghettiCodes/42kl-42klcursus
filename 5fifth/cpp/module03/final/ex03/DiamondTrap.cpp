#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->name = "Unnamed";

	hitpoint = FragTrap::hitpoint; // 100
	erpoint = ScavTrap::erpoint; // 50
	atkdmg = FragTrap::atkdmg; // 30
	ClapTrap::name = std::string(DiamondTrap::name).append("_clap_name");

	std::cout << "A Rare Diamond Trap named " << DiamondTrap::name << " appeared!"  << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name)
{
	this->name = new_name;

	hitpoint = FragTrap::hitpoint;
	erpoint = ScavTrap::erpoint;
	atkdmg = FragTrap::atkdmg;
	ClapTrap::name = std::string(DiamondTrap::name).append("_clap_name");

	std::cout << "A Rare Diamond Trap named " << DiamondTrap::name << " appeared!"  << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &ori) : ClapTrap(), FragTrap(), ScavTrap()
{
	(*this) = ori;
	std::cout << "A duplicate of " << this->name << " is created!" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &ori)
{
	this->name = ori.name;
	hitpoint = ori.hitpoint;
	erpoint = ori.erpoint;
	atkdmg = ori.atkdmg;

	std::cout << "Duplicated " << this->name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << DiamondTrap::name << " was fired from being a DiamondTrap" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name is = " << DiamondTrap::name << " ---- ClapTrap::name is = " << ClapTrap::name << std::endl;
}