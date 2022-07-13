#include "get_next_line.h"

int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	char *buff;
	buff = (char *) malloc (BUFF_SIZE + 1);
	int	i;
	int check;
	check = read(fd, buff, BUFF_SIZE);
	buff[check] = 0;
	printf("read %d bytes \nbuff = %s\n",check,  buff);
	check = read(fd, buff, BUFF_SIZE);
	buff[check] = 0;
	printf("read %d bytes \nbuff = %s\n",check,  buff);
}
