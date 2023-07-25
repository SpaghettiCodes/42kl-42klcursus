#include "Animal.hpp"

Animal::Animal() : type("Unidentified")
{
	std::cout << "Animal was made" << std::endl;
}

Animal::Animal(Animal &ori) : type(ori.type)
{
}

Animal &Animal::operator=(Animal &ori)
{
	this->type = ori.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal was destroyed" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "A unidentified sound was made" << std::endl;
}

std::string Animal::getType() const
{
	return (type);
}