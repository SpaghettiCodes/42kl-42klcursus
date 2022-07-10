#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int fd;
	int fd2;
	char *test;
	int	i;
	char *test2;
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		test = get_next_line(fd);
		test2 = get_next_line(fd2);
		printf("from file 1: %s\n",test);
		printf("from file 2: %s\n",test2);
		i++;
	}
}
