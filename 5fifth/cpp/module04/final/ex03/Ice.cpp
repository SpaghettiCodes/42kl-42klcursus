#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice &ori) : AMateria()
{
	*this = ori;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice &ori)
{
	this->materia_type = ori.getType();
	return (*this);
}

AMateria *Ice::clone() const
{
	AMateria *ret = new Ice();
	return (ret);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}