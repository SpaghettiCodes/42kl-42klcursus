#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ScavTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string new_name);
		~FragTrap();

		void highFivesGuys(void);
	protected:
		std::string	name;
		int			hitpoint;
		int			erpoint;
		int			atkdmg;
};

#endif