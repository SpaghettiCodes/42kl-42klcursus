#include <stdio.h>

int main()
{
	int test[] = {1,2,3,4};
	printf("%d\n", *test);
	printf("%d\n", *(test + 2));
}