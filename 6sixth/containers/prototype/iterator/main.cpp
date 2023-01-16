#include "iterator.hpp"
#include <iterator>
#include <iostream>
#include <vector>

int main()
{
	int	amogus[4] = {1, 2, 3, 4};
	ft::input_iterator<int> test;
	ft::input_iterator<int> test2;
	
	ft::forward_iterator<int> test3;
	ft::forward_iterator<int> test4;

	ft::bidirectional_iterator<int> test5;
	ft::bidirectional_iterator<int> test6;

	test5 = &amogus[3];
	test6 = &amogus[-1];

	test3 = &amogus[1];
	*test3 = 10;

	ft::forward_iterator<int> test8(test3);
	*test8 = 60;
	*(++test8) = 10;
	*(test8++) = 20;
	*(test8) = 10;

	test2 = &amogus[0];
	test = &amogus[4];

	for (; test2 != test; ++test2)
		std::cout << *test2 << std::endl;

	// for (; test5 != test6; --test5)
	// 	std::cout << *test5 << std::endl;	
}


// int main()
// {
// 	int	amogus[5] = {1,2,3,4,5};

// 	// int	x = 4;
// 	// std::cout << (x += 10) << std::endl;

// 	ft::random_iterator<int> iter;
// 	ft::random_iterator<int> iter2;

// 	iter2 = &amogus[5];
// 	ft::random_iterator<int> test(iter);
// 	std::cout << test[-1] << std::endl;


// 	iter = &amogus[1];

// 	for (int i = -1; (iter + i) != iter2; ++i)
// 		std::cout << *(iter + i) << " ";
// 	std::cout << std::endl;

// 	std::cout << *(iter + 1) << std::endl;
// 	std::cout << iter[-1] << std::endl;

// 	std::cout << *(iter += 2) << std::endl;
// 	std::cout << *(iter -= 3) << std::endl;
// }