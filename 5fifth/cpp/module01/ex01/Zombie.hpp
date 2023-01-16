#pragma once
#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie
{
	public:
		// constructor
		Zombie(std::string name);
		Zombie();
		// destory
		~Zombie();
		void setname(std::string name);
		void annouce(void);
	private:
		std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif