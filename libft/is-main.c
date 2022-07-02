#include <stdio.h>
#include "mainfile.h"
#include <ctype.h>

void test(int f(int), int f2(int)){
	printf("\nTesting...\n\n");
	for (int i = 0; i <= 127; i++){
		if (f(i) != 0){
			printf("[ %c : %d ] ",i, f(i));
			printf("[ %c : %d ]\n", i, f2(i));
		}
	}
	printf("\n");
}

int main()
{
	printf("ft_isalpha\n");
	test(isalpha, ft_isalpha);
	printf("ft_isaldigit\n");
	test(isdigit, ft_isdigit);
	printf("ft_isalnum\n");
	test(isalnum, ft_isalnum);
	printf("ft_isascii\n");
	test(isascii, ft_isascii);
	printf("ft_isprint\n");
	test(isprint, ft_isprint);
}
