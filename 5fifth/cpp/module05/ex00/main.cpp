#include "Bureaucrat.hpp"

// test cases
// Bureaucrat test1("test1", 160);	
// Bureaucrat test2("test2", -10);	
// Bureaucrat test3("test3", 10);	

// std::cout << test1 << std::endl; // should be 150
// std::cout << test2 << std::endl; // should be 1
// std::cout << test3 << std::endl; // should be 10

// test2.decrement();
// test3.increment();
// test3.increment();
// test3.increment();

// std::cout << test2 << std::endl; // should be 2
// std::cout << test3 << std::endl; // should be 7 

// test1.decrement(); // should be error
// test1.decrement(); // should be error 
// std::cout << test1 << std::endl; // should be 150
// test1.increment(); 
// test1.increment();
// std::cout << test1 << std::endl; // should be 148

int main()
{
	try
	{
		Bureaucrat test1("test1", 160);	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat test2("test2", -10);	
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat test3("test3", 10);	

		std::cout << test3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}