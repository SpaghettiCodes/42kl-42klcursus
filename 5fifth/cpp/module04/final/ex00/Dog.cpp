#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog was made" << std::endl;
}

Dog::Dog(Dog &ori) : Animal(ori)
{
	type = ori.type;
	std::cout << "Dog was duplicated" << std::endl;
}

Dog &Dog::operator=(Dog &ori)
{
	this->type = ori.type;
	std::cout << "Dog was duplicated" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog was destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
