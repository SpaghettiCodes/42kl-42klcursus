#include "array.hpp"
#include <iostream>

using namespace std;

class amogus
{
	public:
		amogus()
		{
			std::cout << "made" << std::endl;
		}

		~amogus()
		{
			std::cout << "gone" << std::endl;
		}

		amogus(amogus &ori) : x(ori.x), y(ori.y) 
		{
			std::cout << "dup" << std::endl;
		}

		amogus &operator=(amogus &ori)
		{
			this->x = ori.y;
			this->y = ori.y;

			return (*this);
		}

	int x;
	int y;
};

int main()
{
	int	array[] = {2,4,6,8,10};
	ft::array<int, 5> test = array;
	int array2[] = {4,8,12,16,20};
	ft::array<int, 5> ehe = array2;

	// ft::array<amogus, 2> aaa;

	// amogus testt;

	// testt.x = 1;
	// testt.y = 2;

	// aaa[0] = testt;
	// testt.~amogus();

	// std::cout << aaa[0].x << std::endl;

	ft::array<int, 5>::iterator iter1;
	ft::array<int, 5>::iterator iter2;

	iter1 = test.begin();
	iter2 = test.end();

	// (*iter1) = 12;

	
	// for (int i = 0; (iter1 + i) != iter2; i++)
	// 	std::cout << (*(iter1 + i)) << " ";
	// std::cout << std::endl;

	test.swap(ehe);

	std::cout << "in test" << std::endl;
	for (int i = 0; (iter1 + i) != iter2; i++)
		std::cout << (*(iter1 + i)) << " ";
	std::cout << std::endl;

	ehe[0] = 2;
}