#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "AMateria.hpp"
#include "IMaterialSource.hpp"

class MateriaSource : public IMateriaSource
{
	public :
		MateriaSource();
		MateriaSource(MateriaSource &ori);
		~MateriaSource();

		MateriaSource &operator=(MateriaSource &ori);
	
		void learnMateria(AMateria *ori);
		AMateria* createMateria(std::string const & type);

	private :
		void	init_stored();
		void	replace_stored(MateriaSource &ori);
		void	clear_stored();

		AMateria *storedmateria[4];
};

#endif