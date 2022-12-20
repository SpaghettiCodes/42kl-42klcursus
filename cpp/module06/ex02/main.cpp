#include "Identify.hpp"

// so i was researching on casting types
// was checking what is dynamic_cast
// read the official ibm website and tested out the example
// guess what this exercise want us to do
// ...oops

Base *generate(void)
{
	srand(time(NULL) + rand());
	// rand() my beloved
	switch (rand() % 3)
	{
		case 0:
			return (new A);
			break;
		case 1:
			return (new B);
			break;
		case 2:
			return (new C);
			break;
		default:
			// should never occur
			break;
	}
	return (NULL);
}


int main()
{
	Base *test;

	for (int i = 0; i < 10; i++)
	{
		test = generate();
		identify(test); // use pointer
		identify(*test); // use reference
	
		test->printtype(); // the actual type
		delete (test);
	
		std::cout << std::endl;
	}
}