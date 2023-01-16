#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include "Weapon.hpp"
#include <string>

class HumanB
{
	public:
		// constructor
		HumanB(std::string name, Weapon &weapon);
		HumanB(std::string name);
		// destructor
		~HumanB();
		void attack(void);
		void setWeapon(Weapon &new_weapon);
	private:
		std::string name;
		Weapon *weapon;
};

#endif