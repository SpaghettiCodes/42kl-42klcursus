#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(AMateria &ori)
{
	*this = ori;
}

AMateria::AMateria(std::string const & type)
{
	materia_type = type;
}

AMateria::~AMateria()
{
}

AMateria &AMateria::operator=(AMateria &ori)
{
	this->materia_type = ori.materia_type;
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (materia_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "An unkown Materia was used on " << target.getName() << std::endl;
}