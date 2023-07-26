#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <string>
#include <iostream>

class Animal
{
	public :
		Animal();
		Animal(const Animal &ori);
		// https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
		virtual ~Animal();
		Animal &operator=(const Animal &ori);

		void virtual makeSound() const;
		std::string getType() const;
	protected :
		std::string type;
};

#endif