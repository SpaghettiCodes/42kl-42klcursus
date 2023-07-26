/*
Interfaces allow you to specify what methods a class should implement.
	- a description of the actions that an object can do.

Interfaces only have prototype
Interfaces cannot have properties, while abstract classes can
All interface methods must be public, while abstract class methods is public or protected
Classes can implement an interface while inheriting from another class at the same time

Interfaces make it easy to use a variety of different classes in the same way. When one or more classes use the same interface, it is referred to as "polymorphism".
*/

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* tmp;

	// 42 test
	{
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(0, *bob);
		me->use(1, *bob);
	}

	{
		// Character test("test");
		// tmp = src->createMateria("cure");
		// test.equip(tmp);
		// test.use(0, test);
		// std::cout << "Duplicating using = .." << std::endl;
		// Character test2 = test;
		// std::cout << "Duplicated" << std::endl;
		// test2.use(0, test2);
		// std::cout << "Duplicating using () .." << std::endl;
		// Character test3(test);
		// std::cout << "Duplicated" << std::endl;
		// test3.use(0, test2);

		// tmp = src->createMateria("ice");
		// test2.equip(tmp);
		// std::cout << "Copying using = ..." << std::endl;
		// test3 = test2;
		// std::cout << "Copied" << std::endl;
		// test3.use(1, test2);
	}

	// // unaccessable indexes test

	{
		// me->use(69, *bob);
		// me->use(-1, *bob);
		// me->use(2, *bob);

		// // new equpiment test
		// tmp = src->createMateria("ice");
		// me->equip(tmp);
		// me->use(2, *bob);

		// std::cout << "Will now equip a not allocated Ice object (undefined behavior)" << std::endl;
		// Ice test;
		// me->equip(&test);

		// MateriaSource test;
		// test.learnMateria(new Ice());
		// MateriaSource test2(test);
	}

	delete bob;
	delete me;
	delete src;

	return 0;
}