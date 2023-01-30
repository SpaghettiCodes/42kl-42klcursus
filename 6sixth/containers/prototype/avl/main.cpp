#include "avl.hpp"
#include <iostream>

int main()
{
	AVL<int>	test;

	// test.assign_new(8);
	// test.assign_new(3);
	// test.assign_new(1);
	// test.assign_new(6);
	// test.assign_new(4);
	// test.assign_new(7);
	// test.assign_new(10);
	// test.assign_new(14);
	// test.assign_new(13);

	test.assign_new(2);
	// test.assign_new(1);
	test.assign_new(3);
	test.assign_new(4);
	test.print_stuff();
	test.delete_info();
}