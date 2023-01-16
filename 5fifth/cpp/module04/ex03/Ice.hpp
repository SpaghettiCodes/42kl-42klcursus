#ifndef __ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice &ori);
		~Ice();
		
		Ice &operator=(Ice &ori);
		AMateria *clone() const;
		void use(ICharacter &target);
};

#endif