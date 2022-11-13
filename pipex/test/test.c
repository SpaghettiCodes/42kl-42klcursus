#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// ok idk what fuck im doing wahooooo

typedef struct STATUS
{
	int written;
	int readed;
} status;

int	parent_process(int counter, int pipe[2], status *rwstatus)
{
	char BUFF[100];
	int check = read(pipe[0], BUFF, 100);
	BUFF[check] = '\0';
	printf("from child to parent = ");
	printf("%s", BUFF);
	printf("\n");
}

int	child_process(int counter, int pipe[2], status *rwstatus)
{
	printf("child wrote stuff\n");
	write(pipe[1], "AMOGUS", 7);
}

int main(int ac, char **av)
{
	int	fd[2]; //0 = read, 1 = write
	status rwstatus;
	int	counter;
	int	check;

	pipe(fd);
	check = fork();
	counter = 1;
	if (check == -1)
		printf("Failed\n");
	else if (check == 0) //child
	{
		child_process(counter, fd, &rwstatus);
	}
	else //parent
	{
		parent_process(counter, fd, &rwstatus);
	}
	close(fd[0]);
	close(fd[1]);
}