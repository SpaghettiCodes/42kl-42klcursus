#include "easyfind.hpp"
#include <vector>
#include <iostream>

template<class X>
void tryfind(X container, int tofind)
{
	try
	{
		easyfind(container, tofind);
		std::cout << "Found " << tofind << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	std::vector<int> amogus;

	for (int i = 0; i < 5; i++)
		amogus.push_back(i);

	for (int i = 0; i < 10; i++)
		tryfind(amogus, i);
}