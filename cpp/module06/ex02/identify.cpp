#include "Identify.hpp"

void identify(Base *p)
{
	if (!p)
	{
		std::cout << "that was a null pointer bro" << std::endl;
		return ;
	}

	std::cout << "That pointer is pointing to an object of Type ";
	if (dynamic_cast<A *> (p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *> (p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *> (p))
		std::cout << "C" << std::endl;
	else
		std::cout << "wtf did you give me" << std::endl;
}

static bool identitry(Base &p, char class_type)
{
	try
	{
		switch (class_type)
		{
			case 'A':
			{
				A &test = dynamic_cast<A &> (p);
				(void) test;
				break;
			}
			case 'B':
			{
				B &test = dynamic_cast<B &> (p);
				(void) test;
				break;
			}
			default :
			{
				C &test = dynamic_cast<C &> (p);
				(void) test;
				break;
			}
		};
		return (1);
	}
	catch (std::exception &e)
	{
		return (0);
	}
}

void identify(Base &p)
{
	std::cout << "That reference is referencing to an object of Type ";
	if (identitry(p, 'A'))
		std::cout << "A" << std::endl;
	else if (identitry(p, 'B'))
		std::cout << "B" << std::endl;
	else if (identitry(p, 'C'))
		std::cout << "C" << std::endl;
	else
		std::cout << "wtf did you give me" << std::endl;
}