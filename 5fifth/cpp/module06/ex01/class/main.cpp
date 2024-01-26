#include "Serializer.hpp"
#include <iostream>

// why is ex01 easier than ex00

// int main()
// {
// 	Data *ptr;
// 	Data data;
// 	data.data = 1;
// 	data.message = "Hello World!";
// 	ptr = &data;
// 	uintptr_t serial_num = Serializer::serialize(ptr);

// 	std::cout << "Data address of ptr: " << ptr << std::endl;
// 	std::cout << "Value of serial number: " << serial_num << std::endl;
// 	std::cout << "Value of serial number in hex: " << std::hex << serial_num << std::dec << std::endl;

// 	Data *ptr2;
// 	ptr2 = Serializer::deserialize(serial_num);
// 	std::cout << "Data in pt2 - int : " << ptr2->data << " -- Message : " << ptr2->message << std::endl;
// }

// cool shit #1

// int main()
// {
// 	using namespace std;
// 	char stuff[4];

// 	stuff[0] = 0x45; // 0100 0101
// 	stuff[1] = 0x12; // 0001 0010
// 	stuff[2] = 0x0b; // 0000 1011
// 	stuff[3] = 0x00; // 0000 0000

// 	// 0 0 0 b 1 2 4 5
// 	// 0000 0000 0000 1011 0001 0010 0100 0101
// 	// 725573

// 	// cout << std::hex << reinterpret_cast<uintptr_t> (stuff) << endl;
// 	// cout << std::hex << reinterpret_cast<uintptr_t> (stuff + 1) << endl;
// 	// cout << std::hex << reinterpret_cast<uintptr_t> (stuff + 2) << endl;
// 	// cout << std::hex << reinterpret_cast<uintptr_t> (stuff + 3) << endl;

// 	int	*test;

// 	test = reinterpret_cast<int *> (stuff);

// 	std::cout << std::dec << "Binary: " << *(test) << std::endl; // 1
// 	std::cout << std::hex << "Hexa: " << *(test) << std::endl; // 1
// }

// cool shit #2

// int main()
// {
// 	int x;
	
// 	x = 0xabcde012;
// 	std::cout << std::hex << x << std::endl << std::endl;

// 	unsigned char *stuff = reinterpret_cast<unsigned char *> (&x);

// 	for (int x = 0; x < 4; ++x)
// 	{
// 		int y = stuff[x];
// 		std::cout << std::dec << "Dec: " << y << std::endl;
// 		std::cout << std::hex << "Hex: " << y << std::endl;

// 		std::cout << std::endl;
// 	}
// }
