#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->materia_type = "cure";
}

Cure::Cure(Cure &ori) : AMateria()
{
	*this = ori;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure &ori)
{
	this->materia_type = ori.getType();
	return (*this);
}

AMateria *Cure::clone() const
{
	AMateria *ret = new Cure();
	return (ret);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}