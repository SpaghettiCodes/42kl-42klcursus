#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog &ori);
		Dog &operator=(Dog &ori);
		virtual ~Dog();

		void makeSound() const;
		Brain *getBrain();
	private:
		Brain *brain;
};

#endif