#include "Serializer.hpp"
#include <iostream>

// why is ex01 easier than ex00

int main()
{
	Data *ptr;
	Data data;
	data.data = 1;
	data.message = "Hello World!";
	ptr = &data;
	uintptr_t serial_num = Serializer::serialize(ptr);

	std::cout << "Data address of ptr: " << ptr << std::endl;
	std::cout << "Value of serial number: " << serial_num << std::endl;
	std::cout << "Value of serial number in hex: " << std::hex << serial_num << std::dec << std::endl;

	Data *ptr2;
	ptr2 = Serializer::deserialize(serial_num);
	std::cout << "Data in pt2 - int : " << ptr2->data << " -- Message : " << ptr2->message << std::endl;
}