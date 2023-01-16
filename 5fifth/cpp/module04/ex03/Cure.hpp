#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure &ori);
		~Cure();
		
		Cure &operator=(Cure &ori);
		AMateria *clone() const;
		void use(ICharacter &target);
};


#endif