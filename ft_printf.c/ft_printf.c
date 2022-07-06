#include "ft_printf.h"
#include "le_flag_functions.c"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	//figure out how the fuck do you use va_start
}

#include <stdio.h>
int main()
{
	char letter = 'a';
	char *string = "pizza hut";
	int	number = 9;
	unsigned int number2 = 123;
	int number3 = 12312312;
	int number4 = -12312;
	unsigned int number5 = -12312;
	printf("Letter = %c\n", letter);
	printf("String = %s\n", string);
	printf("Number = %d\n", number);
	printf("Unsigned Int Number = %u\n", number2);
	printf("hexadecimal = %x\n%X\n", number3, number3);
	printf("does it handle negatives?\nIn int = %x\nIn Unsigned int = %x\nNo, %%x accepts unsigned ints\n", number4, number5);
	printf("Not enough variables: \"%s\", \"%d\", \"%c\", will leave empty spaces\n", string, letter);
	printf("%d\n", printf("Printf returns number of bytes written: "));
	printf("%d\n", printf("Printf returns number of bytes written %c: ", letter));
	printf("%d\n", printf("Printf returns number of bytes written %d: ", number2));
	printf("%%d and %%i do the same shit %d, %i\n", number3, number3);
	printf("and %%p is confusing %p\n", &number3);
	printf("Flags:\n\n");
	printf("what %-8d what\n", number);
	printf("what %08d what\n", number);
	printf("flag 0 pads the number to the right with 0s, flag - pads the number to the left with spaces\n");
	printf("not specifying does nothing (i think)\n");
	printf("what % d what\n", number);
	printf("flag (space) adds a space before the number\n");
	printf("what %.12d what\n", number3);
	printf(". flag is apparantly same with 0?\n");
}
