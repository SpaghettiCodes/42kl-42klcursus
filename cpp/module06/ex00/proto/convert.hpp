#ifndef __CONVERT_HPP__
#define __CONVERT_HPP__

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

#define CHARMAX 255
#define INTMAX 2147483647
#define INTMIN -2147483648

void	conv_char(char *input);
void	conv_int(char *input);
void	conv_float(char *input);
void	conv_double(char *input);
void	error();

#endif