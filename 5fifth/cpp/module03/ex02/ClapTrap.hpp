#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>
#include <iostream>
// what is a claptrap

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap &ori);
		ClapTrap &operator=(ClapTrap &ori);
		~ClapTrap();

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	protected:
		std::string	name;
		int			hitpoint;
		int			erpoint;
		int			atkdmg;
};

#endif