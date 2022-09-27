#include "ft_printf_bonus.h"
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

// int main()
// {
// 	int a = 123;
// 	printf("\nNumber printed: %d\n", ft_printf("%d", 123));
// }


#include <stdio.h>
int main()
{
	int		x = 123123;
	int		cmp1, cmp2;
	char *s = "helpme";
	printf("\nTHE BASICS:\n");
	printf("------------------------------------------------------------\n");
	printf("|                        Test 1                            |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%-012dend\n", x);
	cmp2 = printf("%-012dend\n", x);
	printf("\n                     Diff in values                     \n");
	printf("            My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                       Test 1.1                           |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%dsxXcend\n", x);
	cmp2 = printf("%dsxXcend\n", x);
	printf("\n                     Diff in values                     \n");
	printf("            My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                        Test 2                            |\n");
	printf("------------------------------------------------------------\n");
	char *string = "Lorem ipsum dolor sit amet";
	int		number = 13;
	cmp1 = ft_printf("%s %d %x \"%d\" end\n", string, number, number);
	cmp2 = printf("%s %d %x \"%d\" end\n", string, number, number);
	printf("\n                     Diff in values                     \n");
	printf("            My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("\nFLAGS: \n");
	printf("------------------------------------------------------------\n");
	printf("|                        Test 3                            |\n");
	printf("------------------------------------------------------------\n");
	string = "Lorem ipsum dolor sit amet";
	cmp1 = ft_printf("%.2send\n", string);
	cmp2 = printf("%.2send\n", string);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                       Test 4.1                           |\n");
	printf("------------------------------------------------------------\n");
	number = 13;
	cmp1 = ft_printf("%-20.13dend\n", number);
	cmp2 = printf("%-20.13dend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                       Test 4.2                           |\n");
	printf("------------------------------------------------------------\n");
	number = 213123123;
	cmp1 = ft_printf("%9.5dend\n", number);
	cmp2 = printf("%9.5dend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                        Test 5                            |\n");
	printf("------------------------------------------------------------\n");
	number = 13;
	cmp1 = ft_printf("%- +012.10dend\n", number);
	cmp2 = printf("%- +012.10dend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);


	printf("------------------------------------------------------------\n");
	printf("|                        Test 6                            |\n");
	printf("------------------------------------------------------------\n");
	number = 13;
	cmp1 = ft_printf("%.10dend\n", number);
	cmp2 = printf("%.10dend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	// printf("------------------------------------------------------------\n");
	// printf("|                        Test 7                            |\n");
	// printf("------------------------------------------------------------\n");
	// string = "abcdefg";
	// cmp1 = ft_printf("%-0+12.10send\n", string);
	// cmp2 = printf("%-0+12.10send\n", string);
	// printf("\n                     Diff in values                     \n");
	// printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                        Test 8                            |\n");
	printf("------------------------------------------------------------\n");
	number = 0x213;
	cmp1 = ft_printf("%#xend\n", number);
	cmp2 = printf("%#xend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	// printf("------------------------------------------------------------\n");
	// printf("|                        Test 9                            |\n");
	// printf("------------------------------------------------------------\n");
	char *test = "abcdefghijklmnopqrstuvwxyz";
	// cmp1 = ft_printf("%023send\n", test);
	// cmp2 = printf("%023send\n", test);
	// printf("\n                     Diff in values                     \n");
	// printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                       Test 9.1                           |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%-23.9send\n", test);
	cmp2 = printf("%-23.9send\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                       Test 9.2                           |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%23.9send\n", test);
	cmp2 = printf("%23.9send\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                       Test 9.3                           |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%23.29send\n", test);
	cmp2 = printf("%23.29send\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                       Test 9.4                           |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%8.3send\n", test);
	cmp2 = printf("%8.3send\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test 9.4.1                          |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%-8.3send\n", test);
	cmp2 = printf("%-8.3send\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	// printf("------------------------------------------------------------\n");
	// printf("|                      Test 10                             |\n");
	// printf("------------------------------------------------------------\n");
	// cmp1 = ft_printf("%#-+ 08.3send\n", test);
	// cmp2 = printf("%#-+ 08.3send\n", test);
	// printf("\n                     Diff in values                     \n");
	// printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	// printf("------------------------------------------------------------\n");
	// printf("|                      Test 11                             |\n");
	// printf("------------------------------------------------------------\n");
	int	hexa = 0x1230adef;
	// cmp1 = ft_printf("%#-+ 08.3Xend\n", hexa);
	// cmp2 = printf("%#-+ 08.3Xend\n", hexa);
	// printf("\n                     Diff in values                     \n");
	// printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("\nI FORGOT TO TEST %% FLAGS IN BASICS: \n");
	printf("------------------------------------------------------------\n");
	printf("|                      Test 11                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%%end\n");
	cmp2 = printf("%%end\n");
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test 11.1                            |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%%%%%%%%%%end\n");
	cmp2 = printf("%%%%%%%%%%end\n");
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test 11.2                            |\n");
	printf("------------------------------------------------------------\n");
	number = 123123;
	cmp1 = ft_printf("%%%d%%%%%%end\n", number);
	cmp2 = printf("%%%d%%%%%%end\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);


	printf("------------------------------------------------------------\n");
	printf("|                      Test 12                             |\n");
	printf("------------------------------------------------------------\n");
	number = 123123;
	cmp1 = ft_printf("%-+0123.213wend\n", number);
	cmp2 = printf("%-+0123.213wend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("\nWE ARE BACK TO FLAGS: \n");
	printf("------------------------------------------------------------\n");
	printf("|                     Test 12.1                            |\n");
	printf("------------------------------------------------------------\n");
	number = 123123;
	cmp1 = ft_printf("%-+012d.213wend\n", number);
	cmp2 = printf("%-+012d.213wend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test 12.2                            |\n");
	printf("------------------------------------------------------------\n");
	number = 675;
	cmp1 = ft_printf("%-+012d.2-13wend\n", number);
	cmp2 = printf("%-+012d.2-13wend\n", number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("\nWHAT IN THE BULLSHIT IS THIS: \n");
	printf("------------------------------------------------------------\n");
	printf("|                     Test 12.3                            |\n");
	printf("------------------------------------------------------------\n");
	number = 904;
	cmp1 = ft_printf("%-+01- +-+-+-  +-+2d.2-13wend\n", number);
	cmp2 = printf("%-+01- +-+-+-  +-+2d.2-13wend\n", number);
	printf("Editors note: what the fuck printf? how the fuck would you still work???\n");
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test 12.4                            |\n");
	printf("------------------------------------------------------------\n");
	number = 904;
	cmp1 = ft_printf("%-+01-   4    +-+d.2-13wend\n", number);
	cmp2 = printf("%-+01-   4    +-+d.2-13wend\n", number);
	printf("Editors note: what the fuck printf? how the fuck would you still work???\n");
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test 12.5                            |\n");
	printf("------------------------------------------------------------\n");
	number = 904;
	cmp1 = ft_printf("%-+01-  www4    +-+d.2-13wend\n", number);
	cmp2 = printf("%-+01-  www4    +-+d.2-13wend\n", number);
	printf("Editors note: oh thank got it dies here\n");
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test 12.6                            |\n");
	printf("------------------------------------------------------------\n");
	number = 904;
	cmp1 = ft_printf("%-+01-  &*^*($4    +-+d.2-13wend\n", number);
	cmp2 = printf("%-+01-  &*^*($4    +-+d.2-13wend\n", number);
	printf("Editors note: oh thank got it dies here\n");
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test 12.7                            |\n");
	printf("------------------------------------------------------------\n");
	test = "0123456789";
	cmp1 = ft_printf("%.0   + -5swend\n", test);
	cmp2 = printf("%.0   + -5swend\n", test);
	printf("Editors note: GOOD! janky ass atoi in the PRECISION SPECIFIER AS WELL\n");
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("UNSIGNED INT: \n");
	printf("------------------------------------------------------------\n");
	printf("|                      Test 13                             |\n");
	printf("------------------------------------------------------------\n");
	unsigned int u_number = 12312312;
	cmp1 = ft_printf("%u\n", u_number);
	cmp2 = printf("%u\n", u_number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test 14                             |\n");
	printf("------------------------------------------------------------\n");
	u_number = 12312312;
	cmp1 = ft_printf("%12uend\n", u_number);
	cmp2 = printf("%12uend\n", u_number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test 15                             |\n");
	printf("------------------------------------------------------------\n");
	u_number = 12312312;
	cmp1 = ft_printf("%12.4uend\n", u_number);
	cmp2 = printf("%12.4uend\n", u_number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test 16                             |\n");
	printf("------------------------------------------------------------\n");
	u_number = 12312312;
	cmp1 = ft_printf("%4.12uend\n", u_number);
	cmp2 = printf("%4.12uend\n", u_number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test 17                             |\n");
	printf("------------------------------------------------------------\n");
	u_number = 12312312;
	cmp1 = ft_printf("% -020.10uend\n", u_number);
	cmp2 = printf("% -020.10uend\n", u_number);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	// printf("THE * FIELD THINGY: \n");
	// printf("------------------------------------------------------------\n");
	// printf("|                      Test 13                             |\n");
	// printf("------------------------------------------------------------\n");
	// number = 123;
	// cmp1 = ft_printf("%*d\n", 5, number);
	// cmp2 = printf("%0*d\n", 5, number);
	// printf("\n                     Diff in values                     \n");
	// printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);


	// printf("------------------------------------------------------------\n");
	// printf("|                      Test 14                             |\n");
	// printf("------------------------------------------------------------\n");
	// number = 123;
	// cmp1 = ft_printf("%.*d\n", 5, number);
	// cmp2 = printf("%-10.*dend\n", 5, number);
	// printf("\n                     Diff in values                     \n");
	// printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	// printf("------------------------------------------------------------\n");
	// printf("|                      Test 14                             |\n");
	// printf("------------------------------------------------------------\n");
	// number = 123;
	// cmp1 = ft_printf("%.*d\n", 5, number);
	// cmp2 = printf("%-*.*dend\n", 10, 5, number);
	// printf("\n                     Diff in values                     \n");
	// printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("POINTERS:\n");
	printf("------------------------------------------------------------\n");
	printf("|                      Test p1                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%p\n", test);
	cmp2 = printf("%p\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test p2                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%#x\n", test);
	cmp2 = printf("%#x\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test p3                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%20p\n", test);
	cmp2 = printf("%20p\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test p4                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%12p\n", test);
	cmp2 = printf("%12p\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);


	printf("------------------------------------------------------------\n");
	printf("|                     Test p4.1                            |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%4p\n", test);
	cmp2 = printf("%4p\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test p5                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%.12p\n", test);
	cmp2 = printf("%.12p\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test p6                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%.4p\n", test);
	cmp2 = printf("%.4p\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                      Test p7                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%.30p\n", test);
	cmp2 = printf("%.30p\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);
	// remaining work = pointers, and i think only pointers WOOO

	printf("------------------------------------------------------------\n");
	printf("|                      Test p9                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%17.23pend\n", test);
	cmp2 = printf("%17.23pend\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test p10                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%23pend\n", test);
	cmp2 = printf("%23pend\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test p11                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%#pend\n", test);
	cmp2 = printf("%#pend\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);

	printf("------------------------------------------------------------\n");
	printf("|                     Test p12                             |\n");
	printf("------------------------------------------------------------\n");
	cmp1 = ft_printf("%#.16pend\n", test);
	cmp2 = printf("%#.16pend\n", test);
	printf("\n                     Diff in values                     \n");
	printf("             My Funct = %d | Sys funct = %d            \n", cmp1, cmp2);


	ft_printf("MOTHHHHHHHHHHHHHHHHHHAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAFUAWKDHOIAWHDIOAWBOIDBAWBDAWIIOWAD");
}

