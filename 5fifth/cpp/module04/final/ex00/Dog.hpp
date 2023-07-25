#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog &ori);
		Dog &operator=(Dog &ori);
		~Dog();

		void makeSound() const;
	private:
};

#endif