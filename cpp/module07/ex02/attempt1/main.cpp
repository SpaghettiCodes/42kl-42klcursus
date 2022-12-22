#include <iostream>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> test(12);
// 	Array<int> test2(12);

// 	test2 = test;

//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     // {
//     //     Array<int> tmp = numbers;
//     //     Array<int> test(tmp);
//     // }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

#define SIZE 10

template <typename Type>
void	printarray(Array<Type> &amogus)
{
	for (unsigned int i = 0; i < amogus.size(); i++)
		std::cout << amogus[i] << " ";
	std::cout << std::endl;
}

template <typename Type>
void	printarray(const Array<Type> &amogus)
{
	for (unsigned int i = 0; i < amogus.size(); i++)
		std::cout << amogus[i] << " ";
	std::cout << std::endl;
}


int main()
{
	Array <int>empray;

	try
	{
		empray[-2] = 69;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		empray[0] = 69;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Array <int>intray(SIZE);

	for (unsigned int i = 0; i < intray.size(); i++)
		intray[i] = i;
	
	std::cout << "In intray = ";
	printarray(intray);

	empray = intray;

	for (unsigned int i = 0; i < empray.size(); i++)
		empray[i] = i * 2;

	std::cout << "In empray = ";
	printarray(empray);

	std::cout << "In intray = ";
	printarray(intray);

	Array<int> dupray = intray;

	for (unsigned int i = 0; i < dupray.size(); i++)
		dupray[i] = i * 10;

	std::cout << "In dupray = ";
	printarray(dupray);

	std::cout << "In intray = ";
	printarray(intray);

	const Array<int> constray = intray;

	std::cout << "In constray = ";
	printarray(constray);

	const Array<int> empray2;
	empray = empray2;
	
	const Array<char> charray;

	intray = charray;
}