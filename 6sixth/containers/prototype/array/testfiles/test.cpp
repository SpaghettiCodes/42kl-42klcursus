#include <iostream>
#include <array>
#include <iterator>

using namespace std;

int main()
{
	array<int, 5> test = {5,6,7,8,9};
	array<int, 4> test2 = {1,2,3,4};
	array<int, 0> test3;
	array<int, 5> test4;


	std::cout << std::boolalpha << test4.empty() << "\n";
	std::cout << test3.empty() << std::endl;

	test4.fill(15);

	for (int i = 0; i < 5; i++)
		std::cout << test4.at(i) << " ";
	std::cout << std::endl;

	array<int, 5>::iterator iter;
	array<int, 5>::iterator iter2;

	// this does not work
	// test = test2;

	iter = test.end();
	iter2 = test.begin();

	for (; iter != iter2; iter2++)
		std::cout << (*iter2) << " ";
	std::cout << std::endl;
	// *(iter2) = 2;


	// std::cout << "is empty = " << test.empty() << std::endl;
	// std::cout << "size = " << test.size() << std::endl;
	// std::cout << "capacity = " << test.max_size() << std::endl;
	// std::cout << "last element = " << (*iter) << std::endl;
	// std::cout << "last element but another function = " << test.back() << std::endl;
}