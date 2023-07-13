#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string new_name);
		DiamondTrap(const DiamondTrap &ori);
		DiamondTrap &operator=(const DiamondTrap &ori);
		~DiamondTrap();

		void whoAmI();

		// // special code to print out the stats of the diamond trap
		// void print_stats()
		// {
		// 	std::cout << std::endl;
		// 	std::cout << hitpoint << std::endl;
		// 	std::cout << erpoint << std::endl;
		// 	std::cout << atkdmg << std::endl;
		// 	std::cout << std::endl;
		// }
		// using ScavTrap::attack;

	protected:
		std::string	name;
		using ClapTrap::hitpoint;
		using ClapTrap::erpoint;
		using ClapTrap::atkdmg;
};

// oh, -Wshadow doesnt like it when your variable name is the exact same with another variable
// "when a variable declaration hides a previous declaration."

// -Wno-shadow basically silences this warning

#endif