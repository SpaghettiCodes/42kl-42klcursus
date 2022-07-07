#include "ft_printf.h"
#include <stdio.h>

// int main()
// {
// 	// char letter = 'a';
// 	// char *string = "pizza hut";
// 	// int	number = 9;
// 	// unsigned int number2 = 123;
// 	// int number3 = 123123123;
// 	// int number4 = -12312;
// 	// unsigned int number5 = -12312;
// 	// ft_printf("Letter = %c\n", letter);
// 	// ft_printf("String = %s\n", string);
// 	// ft_printf("Number = %d\n", number);
// 	// ft_printf("Unsigned Int Number = %u\n", number2);
// 	// ft_printf("hexadecimal = %x\n%X\n", number3, number3);
// 	// ft_printf("this is a negative number %d\n", number4);
// 	// ft_printf("does it handle negatives?\nIn int = %x\nIn Unsigned int = %x\nNo, %%x accepts unsigned ints\n", number4, number5);
// 	// ft_printf("Not enough variables: \"%s\", \"%d\", \"%c\", will leave empty spaces\n", string, letter);
// 	// ft_printf("%d\n", ft_printf("Printf returns number of bytes written: "));
// 	// ft_printf("%d\n", printf("Printf returns number of bytes written %s : ", NULL));
// 	// ft_printf("%d\n", ft_printf("Printf returns number of bytes written %c: ", letter));
// 	// ft_printf("%d\n", ft_printf("Printf returns number of bytes written %d: ", number2));
// 	// ft_printf("%%d and %%i do the same shit %d, %i\n", number3, number3);
// 	char *a;
// 	char	b = 'f';
// 	unsigned long c;
// 	a = &b;
// 	c = (unsigned long long)&b;
// 	printf("\nTest (%d)\n", ft_printf("%p", a));
// 	printf("test: %p\n", a);
// 	// ft_printf("and %%p is confusing %p\n", &number3);
// 	// ft_printf("Flags:\n\n");
// 	// ft_printf("what %-8d what\n", number);
// 	// ft_printf("what %08d what\n", number);
// 	// ft_printf("flag 0 pads the number to the right with 0s, flag - pads the number to the left with spaces\n");
// 	// ft_printf("not specifying does nothing (i think)\n");
// 	// ft_printf("what % d what\n", number);
// 	// ft_printf("flag (space) adds a space before the number\n");
// 	// ft_printf("what %.12d what\n", number3);
// 	// ft_printf(". flag is apparantly same with 0?\n");
// }

int main()
{
	int a = 123;
	printf("\nNumber printed: %d\n", ft_printf("%d", 123));
}
