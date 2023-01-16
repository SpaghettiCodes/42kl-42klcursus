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

// this function returns the const reference to type
// const -> anyone who uses this can only see the value, but not change it
// reference -> pass by refenrence, returns the alias of the weapon.type (basically returns types, not a copy of type)
const std::string &Weapon::getType(void)
{
	return (type);
}