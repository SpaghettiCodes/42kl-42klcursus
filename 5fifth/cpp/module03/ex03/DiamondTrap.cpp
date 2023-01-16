#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	priv_name = "Unnamed";
	hitpoint = FragTrap::hitpoint;
	erpoint = ScavTrap::erpoint;
	atkdmg = ScavTrap::atkdmg;
	ClapTrap::name = std::string(priv_name).append("_clap_name");

	std::cout << "A Rarw Diamond Trap named " << priv_name << " appeared!"  << std::endl;
}

DiamondTrap::DiamondTrap(std::string new_name)
{
	priv_name = new_name;
	hitpoint = FragTrap::hitpoint;
	erpoint = ScavTrap::erpoint;
	atkdmg = ScavTrap::atkdmg;
	ClapTrap::name = std::string(priv_name).append("_clap_name");

	std::cout << "A Rarw Diamond Trap named " << priv_name << " appeared!"  << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << priv_name << " reverted back into its boring form" << std::endl;
}

// that ScavTrap::attack() tells the program to run the ScavTrap version of attack
void DiamondTrap::attack(const std::string atk_name)
{
	ScavTrap::attack(atk_name);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name is = " << priv_name << " ---- ClapTrap::name is = " << ClapTrap::name << std::endl;
}