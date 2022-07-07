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
	// printf("Letter = %c\n", letter);
	// printf("String = %s\n", string);
	// printf("Number = %d\n", number);
	// printf("Unsigned Int Number = %u\n", number2);
	// printf("hexadecimal = %x\n%X\n", number3, number3);
	// printf("does it handle negatives?\nIn int = %x\nIn Unsigned int = %x\nNo, %%x accepts unsigned ints\n", number4, number5);
	// printf("Not enough variables: \"%s\", \"%d\", \"%c\", will leave empty spaces\n", string, letter);
	// printf("%d\n", printf("Printf returns number of bytes written: "));
	// printf("%d\n", printf("Printf returns number of bytes written %s : ", NULL));
	// printf("%d\n", printf("Printf returns number of bytes written %c: ", letter));
	// printf("%d\n", printf("Printf returns number of bytes written %d: ", number2));
	// printf("%%d and %%i do the same shit %d, %i\n", number3, number3);
	// printf("and %%p is confusing %p\n", &number3);


	// int nbr = -12312;
	// char *test = "ipsum lioem or something";
	// printf("Flags:\n\n");
	// printf("Flags in printf are: -0.#(space)+\n");
	// printf("what %-8d what\n", number);
	// printf("what %08d what\n", number);
	// printf("%.3s\n", test);
	// printf("flag 0 pads the number to the left with 0s, flag - pads the number to the right with spaces\n");
	// printf("flag + pads number to the left with spaces\n");
	// printf("not specifying does nothing (i think)\n");
	// printf("what % 8d what\n", number);
	// printf("flag (space) pads the number to the right with (space)\n");
	// printf("what %.3d what\n", number3);
	// printf(". im big idot, . flag specifies the precision\n");
	// printf("if length of the value is lesser than digits, it will pad with zeroes only\n");
	// printf("if done on string, will only print out the number of character stated\n");
	// printf("I think it overides all other flags? not sure\n");
	// printf("%d %#x %#u\n", nbr, nbr, nbr);
	// printf("what % .30i what \n", nbr);
	// printf("%%(space) gets overriden by everything (i think) %%0 overides %%+, %%- overides %%0 and %%+ and %%. overides %%-\n");
	// [..]
	// If the 0 and - flags both appear, the 0 flag is ignored.
	// If a precision is given with a numeric conversion (d, i, o, u, x, and X)
	// the 0 flag is ignored.
	// [..]
	// printf("# converts it from digit to whatever is specified (if its to hexadecimal , a 0x is added in the fornt)\n");
	// overall syntax of a conversion specification is : %[$][flags][width][.precision][length modifier]conversion
	char *a = "aa";
	printf("%p\n", a);
}
