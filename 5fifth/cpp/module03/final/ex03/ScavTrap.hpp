#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &ori);
		ScavTrap &operator=(const ScavTrap &ori);
		~ScavTrap();

		void attack(const std::string &target);
		void guardGate();
	protected:
		int			hitpoint;
		int			erpoint;
		int			atkdmg;

		bool		gatekeep;
};

#endif