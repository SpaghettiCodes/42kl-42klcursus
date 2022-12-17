#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>

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
	// HAS to be protected, or else child members CANNOT access these members
	protected:
		std::string	name;
		int			hitpoint;
		int			erpoint;
		int			atkdmg;
};

#endif