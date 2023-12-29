#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	MutantStack<int> test;

	for (int x = 0; x < 10; ++x)
	{
		test.push(10);
	}

	it = test.begin();
	ite = test.end();

	int	i = 0;
	while (it != ite)
	{
		*(it) = (i * 2);
		++i;
		++it;
	}

	it = test.begin();
	while (it != ite)
	{
		std::cout << " " << *(it);
		++it;
	}
	std::cout << std::endl;

	return 0;
}
