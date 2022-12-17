#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

// ayo CYKA BYLAT

#include "ClapTrap.hpp"

// do i need a operator= assignment function?
class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate();
	private:
};

#endif