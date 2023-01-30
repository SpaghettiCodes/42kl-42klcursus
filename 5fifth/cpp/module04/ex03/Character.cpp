#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("Unnamed"), invent_size(4), equipped(0)
{
	init_invet();
}

Character::Character(Character &ori) : invent_size(4), equipped(0)
{
	init_invet();
	*this = ori;
}

Character::Character(std::string new_name) : name(new_name), invent_size(4)
{
	init_invet();
}

Character &Character::operator=(Character &ori)
{
	this->name = ori.name;
	clear_invent();
	copy_invent(ori);
	this->equipped = ori.equipped;
	return (*this);
}

Character::~Character()
{
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

void Character::unequip(int idx)
{
	// TODO: figure out how to delete the unequiped thing without deleting it
	// i guess i can return the dropped item?
	// maybemaybemaybe
	if (idx >= invent_size || idx < 0 || !inventory[idx])
	{
		std::cout << "Nothing equipped there" << std::endl;
		return ;
	}
	delete inventory[idx];
	inventory[idx] = NULL;
	equipped--;
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