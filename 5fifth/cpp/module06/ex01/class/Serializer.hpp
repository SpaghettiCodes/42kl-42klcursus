#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);

	private:
	Serializer();
	Serializer(Serializer &other); // dont need you

	Serializer &operator=(Serializer &other); // dont need you
};

#endif