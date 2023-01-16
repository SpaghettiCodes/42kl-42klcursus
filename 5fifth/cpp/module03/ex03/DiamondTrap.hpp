#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

// multiple inheritance

// thanks https://www.cprogramming.com/tutorial/multiple_inheritance.html very cool
class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string new_name);
		~DiamondTrap();

		void attack(const std::string name);
		void whoAmI();
	private:
		std::string priv_name;
};

// oh, -Wshadow doesnt like it when your variable name is the exact same with another variable
// "when a variable declaration hides a previous declaration."

// -Wno-shadow basically silences this warning

#endif