#ifndef __FragTrap_HPP__
#define __FragTrap_HPP__

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &ori);
		FragTrap	&operator=(const FragTrap &ori);
		~FragTrap();

		void highFivesGuys(void);
	private:
};

#endif