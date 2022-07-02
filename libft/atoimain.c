#include <stdio.h>
#include <stdlib.h>
#include "ft_atoi.c"

void test(char *str){
	printf("| My Function: %i |", ft_atoi(str));
	printf(" Sys Function: %i | \n", atoi(str));
}

int main(){
	test("123123");
	test("-23123");
	test("           \n -12312");
	test("----123123");
	test("++123123");
	test("    daa       \n -123123");
	test("           \n -123ada123");
	test("           \n +7920");
}
