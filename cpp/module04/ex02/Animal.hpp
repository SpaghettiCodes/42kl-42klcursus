#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include "Brain.hpp"
#include <string>
#include <iostream>

class Animal
{
	public :
		virtual ~Animal();

		Animal &operator=(Animal &ori);

		// makes Animal an abstract class
		void virtual makeSound() const = 0;
		std::string getType() const;

		// shift all of the constructors to protected
		// child can still create Animal Base class

		// "With a protected constructor you just tell other 
		// developers that your class is only intended to be used as a base."
		protected :
		Animal();
		Animal(Animal &ori);

		std::string type;
};

#endif