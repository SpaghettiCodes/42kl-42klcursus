#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// i love getting fucked by my own test cases :)
int main()
{
	// // no mem leaks :D
	// Animal *doggo = new Dog;
	// Animal *catto = new Cat;

	// delete doggo; 
	// delete catto;

	// funny pdf assignment
	int i = 0;
	int arr_len = 10;
	Animal *Animal_Arr[arr_len];

	for ( ; i < (arr_len / 2); i++)
		Animal_Arr[i] = new Dog;
	for ( ; i < arr_len; i++)
		Animal_Arr[i] = new Cat;

	for (i = 0 ; i < arr_len; i++)
		delete (Animal_Arr[i]);

	// // prove that the copy of cat // dog is not shallow and is a deep copy
	// Cat cata;

	// Brain *braingetter;

	// braingetter = cata.getBrain();
	// braingetter->setIdeas("Test1", 0);
	// braingetter->setIdeas("Test2", 1);

	// std::cout << "Cat A Brain 0 = " << cata.getBrain()->getIdeas(0) << std::endl;
	// std::cout << "Cat A Brain 1 = " << cata.getBrain()->getIdeas(1) << std::endl;

	// Cat catb = cata;
	// std::cout << "Cat B Brain 0 = " << catb.getBrain()->getIdeas(0) << std::endl;
	// std::cout << "Cat B Brain 1 = " << catb.getBrain()->getIdeas(1) << std::endl;

	// std::cout << std::endl << "Here are the brains address ---" << std::endl;
	// std::cout << "Cat A Brain address = " << cata.getBrain() << std::endl;
	// std::cout << "Cat B brain address = " << catb.getBrain() << std::endl << std::endl;

	// std::cout << std::endl << "Changing Cat B's brain..." << std::endl;
	// braingetter = catb.getBrain();
	// braingetter->setIdeas("Test3", 0);
	// braingetter->setIdeas("Test4", 1);
	// std::cout << "Changed!" << std::endl << std::endl;

	// std::cout << "Cat A Brain 0 = " << cata.getBrain()->getIdeas(0) << std::endl;
	// std::cout << "Cat A Brain 1 = " << cata.getBrain()->getIdeas(1) << std::endl;
	// std::cout << "Cat B Brain 0 = " << catb.getBrain()->getIdeas(0) << std::endl;
	// std::cout << "Cat B Brain 1 = " << catb.getBrain()->getIdeas(1) << std::endl << std::endl;

}