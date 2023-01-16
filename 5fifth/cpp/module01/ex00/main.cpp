#include "Zombie.hpp"

int main()
{
	std::cout << "Zombie amogus allocated in heap" << std::endl;
	Zombie *amongus = newZombie("Amogus");
	std::cout << "Zombie sussy allocated in stack" << std::endl;
	randomChump("Sussy");
	amongus->annouce();
	delete amongus;
	return (1);
}