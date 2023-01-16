#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	init_stored();
}

MateriaSource::MateriaSource(MateriaSource &ori)
{
	init_stored();
	replace_stored(ori);
}

MateriaSource::~MateriaSource()
{
	clear_stored();
}

MateriaSource &MateriaSource::operator=(MateriaSource &ori)
{
	clear_stored();
	replace_stored(ori);
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *ori)
{
	for (int i = 0; i < 4; i++)
	{
		if (!storedmateria[i])
		{
			storedmateria[i] = ori->clone();
			delete ori;
			return;
		}
	}
	std::cout << "Not enough Space" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (storedmateria[i] && !(storedmateria[i]->getType().compare(type)))
		{
			return (storedmateria[i]->clone());
		}
	}
	std::cout << "Materia Does Not Exist!" << std::endl;
	return (NULL);
}

void MateriaSource::init_stored()
{
	for (int i = 0; i < 4; i++)
		storedmateria[i] = NULL;
}

void	MateriaSource::replace_stored(MateriaSource &ori)
{
	for (int i = 0; i < 4; i++)
	{
		if (ori.storedmateria[i])
			this->storedmateria[i] = ori.storedmateria[i]->clone();
		else
			this->storedmateria[i] = NULL;
	}
}

void MateriaSource::clear_stored()
{
	for (int i = 0; i < 4; i++)
	{
		if (storedmateria[i])
			delete storedmateria[i];
	}
}