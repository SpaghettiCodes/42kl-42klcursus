#include "Weapon.hpp"

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string name)
{
	type = name;
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string newtype)
{
	type = newtype;
}

const std::string &Weapon::getType(void)
{
	return (type);
}