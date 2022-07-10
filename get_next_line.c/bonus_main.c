#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	int fd2;
	char *test;
	char *test2;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (1)
	{
		test = get_next_line(fd);
		test2 = get_next_line(fd2);
		if (!test || !test2)
			break;
		printf("from file 1: %s",test);
		printf("from file 2: %s",test2);
	}
}
