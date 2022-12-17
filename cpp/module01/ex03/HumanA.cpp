#include "HumanA.hpp"

// we pass by reference for the weapon here so it is always referencing the same original weapon

// weapon is a reference, so inintialize it at constructor initialize list (weapon HAS to be assigned to something)

// Initializer List - used to initialize the data member of a class
// i think its used specifically by constructors? not sure

// list of memebrs to be initialize is indicated with constructor as a comma-seperated list followed by a colon

/*
** Example: 
** Point(int i = 0, int j = 0):x(i), y(j) {}
** same thing as
** x = i;
** y = j;
*/

// Since references HAVE to be initialized, we hav eto use the constructor initliaze list
// other variables that have to be initialize
// - const data members;
// - member object which does not have default constructor (no Constructor(void))
// - initialization of base class members (parameterized constructor can only be called using inittializier list)
// - constructor parameter name is same as data_member (or you can just use this->)
// - performance reason LMAO

HumanA::HumanA(std::string name, Weapon &new_weapon) : weapon(new_weapon)
{
	this->name = name;
	
	// Human will store the weapon's memory address
	// now any changes in weapon will be reflected on Human's weapon
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
}