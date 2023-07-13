#ifndef __FragTrap_HPP__
#define __FragTrap_HPP__

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &ori);
		FragTrap	&operator=(const FragTrap &ori);
		~FragTrap();

		void highFivesGuys(void);
	protected:
		int			hitpoint;
		int			erpoint;
		int			atkdmg;
};

#endif