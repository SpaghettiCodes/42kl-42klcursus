#ifndef __AMATERIA_HPP__
#define __AMATERIA_HPP__

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria();
		AMateria(AMateria &ori);
		AMateria(std::string const & type);
		virtual ~AMateria();

		AMateria &operator=(AMateria &ori);

		std::string const &getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string materia_type;
};


#endif