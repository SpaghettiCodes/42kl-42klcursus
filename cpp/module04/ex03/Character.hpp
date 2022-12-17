#ifndef __CHARACTER_HPP__
#define __CHARACTER_HPP__

#include "ICharacter.hpp"

class Character : public ICharacter
{
	public :
		Character();
		Character(Character &ori);
		Character(std::string new_name);
		~Character();

		Character &operator=(Character &ori);

		std::string const &getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private :
		void	init_invet();
		void	clear_invent();
		void	copy_invent(Character &ori);

		std::string name;
		AMateria *inventory[4];
		const int invent_size;
		int		equipped;
	protected :

};

#endif