#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain;
	std::cout << "Dog was made" << std::endl;
}

Dog::Dog(Dog &ori) : Animal(ori)
{
	*this = ori;
}

Dog &Dog::operator=(Dog &ori)
{
	this->type = ori.type;
	this->brain = new Brain;
	*(this->brain) = *(ori.brain);
	std::cout << "Dog was duplicated" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog was destroyed" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

Brain *Dog::getBrain()
{
	return (brain);
}