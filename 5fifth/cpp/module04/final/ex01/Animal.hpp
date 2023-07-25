#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "Brain.hpp"
#include <string>
#include <iostream>

class Animal
{
	public :
		Animal();
		virtual ~Animal();
		Animal &operator=(Animal &ori);
		Animal(Animal &ori);

		void virtual makeSound() const;
		std::string getType() const;
	protected :
		std::string type;
};

#endif