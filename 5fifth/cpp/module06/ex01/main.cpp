#include <iostream>
#include <string>
#include <stdint.h>

// why is ex01 easier than ex00

struct Data
{
	int			data;
	std::string	message;
};

// takes a pointer and converts it to unsigned integer
uintptr_t serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t> (ptr));
}

// takes an unsigned integer parameter and converts it to a pointer to Data;
Data *deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *> (raw));
}

int main()
{
	Data *ptr;
	Data data;
	data.data = 1;
	data.message = "Hello World!";
	ptr = &data;
	uintptr_t serial_num = serialize(ptr);

	std::cout << "Data address of ptr: " << ptr << std::endl;
	std::cout << "Value of serial number: " << serial_num << std::endl;

	Data *ptr2;
	ptr2 = deserialize(serial_num);
	std::cout << "Data in pt2 - int : " << ptr2->data << " -- Message : " << ptr2->message << std::endl;
}