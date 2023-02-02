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
		using ScavTrap::attack;
	private:
		// using FragTrap::hitpoint;
		// using ScavTrap::erpoint;
		// using ScavTrap::atkdmg;
		std::string name;
};

// oh, -Wshadow doesnt like it when your variable name is the exact same with another variable
// "when a variable declaration hides a previous declaration."

// -Wno-shadow basically silences this warning

#endif