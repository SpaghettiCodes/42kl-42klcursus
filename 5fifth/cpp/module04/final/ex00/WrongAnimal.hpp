#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <string>

class WrongAnimal
{
	public :
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal &operator=(WrongAnimal &ori);
		WrongAnimal(WrongAnimal &ori);

		// basically no virtual lmao
		void makeSound() const;
		std::string getType() const;
	protected :
		std::string type;
};

#endif