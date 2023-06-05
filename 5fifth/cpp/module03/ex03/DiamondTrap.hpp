#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// it changed.
// wtf.
#define	GET_VAR_NAME(var) (#var)

// multiple inheritance

// thanks https://www.cprogramming.com/tutorial/multiple_inheritance.html very cool
class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string new_name);
		~DiamondTrap();

		void whoAmI();

		void print_stats()
		{
			std::cout << std::endl;
			std::cout << DiamondTrap::hitpoint << std::endl;
			std::cout << DiamondTrap::erpoint << std::endl;
			std::cout << DiamondTrap::atkdmg << std::endl;
			std::cout << std::endl;
		}

		using ScavTrap::attack;
	protected:
		std::string	name;
		int			hitpoint;
		int			erpoint;
		int			atkdmg;
};

// oh, -Wshadow doesnt like it when your variable name is the exact same with another variable
// "when a variable declaration hides a previous declaration."

// -Wno-shadow basically silences this warning

#endif