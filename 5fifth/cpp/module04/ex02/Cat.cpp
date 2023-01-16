#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain;
	std::cout << "Cat was made" << std::endl;
}

Cat::Cat(Cat &ori) : Animal(ori)
{
	*this = ori;
}

Cat &Cat::operator=(Cat &ori)
{
	this->type = ori.type;
	this->brain = new Brain;
	*(this->brain) = *(ori.brain);
	std::cout << "Cat was duplicated" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain()
{
	return (brain);
}