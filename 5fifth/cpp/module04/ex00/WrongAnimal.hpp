#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

/*
	To ensure you understood how it works, implement a WrongCat class that inherits
	from a WrongAnimal class. If you replace the Animal and the Cat by the wrong ones
	in the code above, the WrongCat should output the WrongAnimal sound.

	wtf does this mean
*/

#include <string>

class WrongAnimal
{
	public :
		WrongAnimal();
		// https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors
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