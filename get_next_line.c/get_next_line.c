#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	get_next_line(const int fd, char **line)
{

}


int main(){
	int fd;
	char **test;
	fd = open("test.txt", O_RDONLY);
	test = (char **) malloc (1 * sizeof(char *));
	while (get_next_line(fd, test)){
		for (int i = 0; *test[i]; i++)
			printf("%d\n", *test);
	}
}
