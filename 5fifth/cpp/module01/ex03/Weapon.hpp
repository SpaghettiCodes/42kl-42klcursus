#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>
#include <iostream>

class Weapon
{
	public:
		// constructor
		Weapon(void);
		Weapon(std::string name);
		// destructor
		~Weapon(void);

		const std::string &getType(void);
		void	setType(std::string newtype);
	private:
		std::string type;
};

#endif