#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat &ori);
		Cat &operator=(Cat &ori);
		virtual ~Cat();

		void makeSound() const;
	private:
};

#endif