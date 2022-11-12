#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int test(int fd)
{
	static fd_list *list;
	printf("\nin function\n");

	if (!list)
	{
		printf("first time\n");
		list = (fd_list *) malloc (sizeof(list));
		list->fd = fd;
		list->next = NULL;
		list->readuntil = 0;
		return (0);
	}
	list->readuntil++;
	printf("%d\n", list->readuntil);
	fd_list *current;
	current = list;
	while (1)
	{
		if (current->fd == fd)
		{
			printf("ayo it exists\n");
			return (current->fd);
		}
		if (current->next == NULL)
		{
			printf("cant find it");
			break ;
		}
		printf("\nfd here = %d\n", current->fd);
		printf("\nnot here, going to check next node\n");
		current = current->next;
	}
	printf("doesnt exists\n");
	current->next = (fd_list *) malloc (sizeof(list));
	current = current->next;
	current->fd = fd;
	current->next = NULL;
	printf("made one\n");
	return (0);
}


int main()
{
	int	fd;

	fd = 1;
	test(fd);
	test(fd);
	test(fd);
	test(fd);
}
