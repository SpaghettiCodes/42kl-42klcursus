#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("Unidentified")
{
	std::cout << "WrongAnimal was made" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &ori) : type(ori.type)
{
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &ori)
{
	this->type = ori.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal was destroyed" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Made a Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}
