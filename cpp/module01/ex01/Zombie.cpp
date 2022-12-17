#include "Zombie.hpp"

void	Zombie::annouce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	return ;
}

void	Zombie::setname(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << " was bullied by his mates" << std::endl;
}