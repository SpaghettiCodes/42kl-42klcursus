#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat was made" << std::endl;
}

Cat::Cat(Cat &ori) : Animal(ori)
{
	type = ori.type;
	std::cout << "Cat was duplicated" << std::endl;
}

Cat &Cat::operator=(Cat &ori)
{
	this->type = ori.type;
	std::cout << "Cat was duplicated" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat was destroyed" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
