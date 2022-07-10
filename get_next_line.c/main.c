#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int fd;
	int	i;
	char *test;
	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i < 10)
	{
		test = get_next_line(fd);
		printf("from file 1: %s\n",test);
		i++;
	}
}
