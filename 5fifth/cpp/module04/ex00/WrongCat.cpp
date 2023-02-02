#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat was made" << std::endl;
}

WrongCat::WrongCat(WrongCat &ori) : WrongAnimal(ori)
{
	type = ori.type;
	std::cout << "WrongCat was duplicated" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat &ori)
{
	this->type = ori.type;
	std::cout << "WrongCat was duplicated" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat was destroyed" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "this wont be printed, dont worry about it" << std::endl;
}
