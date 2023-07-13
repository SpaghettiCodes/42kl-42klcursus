#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>
#include <iostream>

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
	private:
		std::string	name;
		int			hitpoint;
		int			erpoint;
		int			atkdmg;
};

#endif