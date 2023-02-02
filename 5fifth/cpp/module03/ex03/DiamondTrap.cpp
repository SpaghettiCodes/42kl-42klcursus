#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	DiamondTrap::name = "Unnamed";
	hitpoint = FragTrap::hitpoint;
	erpoint = ScavTrap::erpoint;
	atkdmg = ScavTrap::atkdmg;
	ClapTrap::name = std::string(DiamondTrap::name).append("_clap_name");

	std::cout << "A Rare Diamond Trap named " << DiamondTrap::name << " appeared!"  << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name)
{
	DiamondTrap::name = new_name;
	hitpoint = FragTrap::hitpoint;
	erpoint = ScavTrap::erpoint;
	atkdmg = ScavTrap::atkdmg;
	ClapTrap::name = std::string(DiamondTrap::name).append("_clap_name");

	std::cout << "A Rare Diamond Trap named " << DiamondTrap::name << " appeared!"  << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << DiamondTrap::name << " reverted back into its boring form" << std::endl;
}

// that ScavTrap::attack() tells the program to run the ScavTrap version of attack
void DiamondTrap::attack(const std::string atk_name)
{
	ScavTrap::attack(atk_name);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name is = " << DiamondTrap::name << " ---- ClapTrap::name is = " << ClapTrap::name << std::endl;
}