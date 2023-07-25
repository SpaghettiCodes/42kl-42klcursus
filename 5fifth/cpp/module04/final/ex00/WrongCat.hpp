#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat &ori);
		WrongCat &operator=(WrongCat &ori);
		virtual ~WrongCat();

		void makeSound() const;
	private:
};

#endif