#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	public:
		// constructor
		HumanA(std::string name, Weapon &weapon);
		// destructor
		~HumanA();
		void attack(void);
	private:
		std::string name;
		Weapon &weapon;
};

#endif