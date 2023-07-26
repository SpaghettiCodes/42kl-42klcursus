#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("Unnamed"), equipped(0), dropped(NULL)
{
	init_invet();
}

Character::Character(Character &ori) : equipped(0)
{
	init_invet();
	*this = ori;
}

Character::Character(std::string new_name) : name(new_name), equipped(0), dropped(NULL)
{
	init_invet();
}

Character &Character::operator=(Character &ori)
{
	this->name = ori.name;
	clear_invent();
	copy_invent(ori);
	this->equipped = ori.equipped;
	this->dropped = ori.dropped;
	return (*this);
}

Character::~Character()
{
	if (dropped)
		delete dropped;
	clear_invent();
}

std::string const &Character::getName() const
{
	return (name);
}

void Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < invent_size; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			// shallow copy
			// any changes on m would be reflected in here
			// since no changes can be applied on AMateriaaaa
			++equipped;
			return ;
		}
	}
	std::cout << "No more inventory Spaces" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= invent_size || idx < 0 || !inventory[idx])
	{
		std::cout << "Nothing equipped there" << std::endl;
		return ;
	}
	dropped = inventory[idx];
	inventory[idx] = NULL;
	equipped--;
}

AMateria	*Character::drop()
{
	AMateria	*store;

	store = dropped;
	dropped = NULL;
	return (store);
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= invent_size || idx < 0 || !inventory[idx])
	{
		std::cout << "Nothing equipped there" << std::endl;
		return ;
	}
	inventory[idx]->use(target);
}

void Character::init_invet()
{
	for (int i = 0; i < invent_size; i++)
		inventory[i] = NULL;
	equipped = 0;
}

void Character::clear_invent()
{
	for (int i = 0; i < invent_size && equipped; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			equipped--;
		}
	}
}

// what
// not like 2 character can share the same materia also
void Character::copy_invent(Character &ori)
{
	for (int i = 0; i < invent_size; i++)
	{
		if (ori.inventory[i])
			inventory[i] = ori.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}