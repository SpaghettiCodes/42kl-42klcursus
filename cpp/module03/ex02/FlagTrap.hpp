#ifndef __FLAGTRAP_HPP__
#define __FLAGTRAP_HPP__

#include "ScavTrap.hpp"

class FlagTrap : public ClapTrap
{
	public:
		FlagTrap();
		FlagTrap(std::string name);
		~FlagTrap();

		void highFivesGuys(void);
	private:
};

#endif