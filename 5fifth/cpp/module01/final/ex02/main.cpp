#include <iostream>
#include <string>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR;
	std::string &stringREF = brain;

	stringPTR = &brain;
	std::cout << "Memory Address of string var = " << &brain << std::endl;
	std::cout << "Memory Address held by stringPTR = " << stringPTR << std::endl;
	std::cout << "Memory Address held by stringREF = " << &stringREF << std::endl << std::endl;

	std::cout << "Value of string var = " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR = " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF = " << stringREF << std::endl << std::endl;
}