#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// i love getting fucked by my own test cases :)
int main()
{
	// // this 2 will not work now
	// Animal abc;
	// Animal def(abc);

	// // no mem leaks :D
	// Animal *doggo = new Dog;
	// Animal *catto = new Cat;

	// delete doggo; 
	// delete catto;

	// ex01
	// // funny pdf assignment
	// int i = 0;
	// int arr_len = 10;
	// Animal *Animal_Arr[arr_len];

	// for ( ; i < (arr_len / 2); i++)
	// 	Animal_Arr[i] = new Dog;
	// for ( ; i < arr_len; i++)
	// 	Animal_Arr[i] = new Cat;

	// for (i = 0 ; i < arr_len; i++)
	// 	delete (Animal_Arr[i]);

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