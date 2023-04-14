#ifndef __CONVERT_HPP__
#define __CONVERT_HPP__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <limits>

enum {
	ERROR = 0,
	CHAR = 1,
	INT = 2,
	FLOAT = 3,
	DOUBLE = 4
};

typedef std::numeric_limits<int> int_limits;
typedef std::numeric_limits<char> char_limits;

void	conv_char(char *input);
void	conv_int(char *input);
void	conv_float(char *input);
void	conv_double(char *input);
void	error();

#endif