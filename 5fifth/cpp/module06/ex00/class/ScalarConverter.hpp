#ifndef __SCALAR_CONVERTER_HPP__
#define __SCALAR_CONVERTER_HPP__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <limits>

typedef	std::numeric_limits<int> int_limits;
typedef	std::numeric_limits<char> char_limits;

enum {
	ERROR = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4
};

class ScalarConverter
{
	public:
	static	void convert(std::string &input);

	private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &other); // do i REALLY need this?
	ScalarConverter &operator=(ScalarConverter &other); // we SERIOUSLY dont need this
};

#endif