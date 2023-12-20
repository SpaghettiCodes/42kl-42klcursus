#include <unistd.h>
#include <stdio.h>

int main()
{
	printf("%d\n", access("./test", R_OK));
	printf("%d\n", access("./fuck", R_OK));
}