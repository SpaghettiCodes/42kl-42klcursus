#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// i love getting fucked by my own test cases :)
int main()
{
	// // this 2 will not work now
	// Animal abc;
	// Animal def(abc);

	// ex02;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	delete i;
	delete j;
}