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
		// destory
		~Zombie();
		void annouce(void);
	private:
		std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif