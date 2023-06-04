#include <stdio.h>

#include <unistd.h>
#include <string.h>

#include <stdlib.h>
#include <errno.h>

// fsanitize=address will not detect valgrind still-reachable leaks

int main()
{
	char	*stuff;

	stuff = malloc(2);
	printf("Malloced stuff\n");
	exit (1);
	// return (1);
}
