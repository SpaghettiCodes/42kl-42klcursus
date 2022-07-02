#include <stdio.h>
#include "toupper.c"
#include <ctype.h>
#include "tolower.c"

void test(char c){
	printf("My Fucn: %c -> %c ---", c, ft_toupper(c));
	printf(" Sys Func: %c -> %c\n", c, toupper(c));
}

void test2(char c){
	printf("My Fucn: %c -> %c ---", c, ft_tolower(c));
	printf(" Sys Func: %c -> %c\n", c, tolower(c));
}

int main() {
	printf("------TOUPPERTEST------\n");
	for (int i = 32; i != 127; i++)
		test(i);
	printf("------TOLOWERTEST------\n");
	for (int i = 32; i != 127; i++)
		test2(i);
}
