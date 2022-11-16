#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h> 
#include <sys/wait.h>

// ok idk what fuck im doing wahooooo

typedef struct STATUS
{
	int written;
	int readed;
} status;

int	parent_process(int counter, int pipe[2], status *rwstatus, int pipe2[2])
{
	char BUFF[100];
<<<<<<< HEAD
	int check;
	while (1)
	{
		check = read(pipe[0], BUFF, 100);
		if (check)
		{
			BUFF[check] = '\0';
			printf("from child to parent = ");
			printf("%s", BUFF);
			printf("\n");
			break;
		}
	}
	close(pipe[0]);
	write(pipe2[1], "TEST", 4);
	printf("written to child\n");
	close(pipe2[1]);
=======
	int check = read(pipe[0], BUFF, 100);
	BUFF[check] = '\0';
	printf("from child to parent = ");
	printf("%s", BUFF);
	printf("\n");
	waitpid();
	printf("Parent wrote stuff\n");
	write(pipe[1], "SUS", 3);
>>>>>>> f132ff0ba39778a27cc0eb686c43d07b7e4edaf6
}

int	child_process(int counter, int pipe[2], status *rwstatus, int pipe2[2])
{
<<<<<<< HEAD
	int check;
	char BUFF[100];

	printf("child wrote stuff\n");
	write(pipe[1], "AMOGUS", 7);
	close(pipe[1]);
	while (1)
	{
		check = read(pipe2[0], BUFF, 100);
		if (check)
		{
			BUFF[check] = 0;
			printf("From parent to child = ");
			printf("%s\n", BUFF);
		}
	}
	close(pipe2[0]);
	exit(0);
=======
	char BUFF[100];
	printf("child wrote stuff\n");
	write(pipe[1], "AMOGUS", 7);
	int check = read(pipe[0], BUFF, 100);
	BUFF[check] = '\0';
	printf("From parent");
	printf("%s\n", BUFF);
	read(pipe[0], BUFF, 100);
>>>>>>> f132ff0ba39778a27cc0eb686c43d07b7e4edaf6
}

int main(int ac, char **av)
{
	int	fd[2]; //0 = read, 1 = write
	int	killme[2]; // 0 read  1 write
	status rwstatus;
	int	counter;
	int	check;

	pipe(fd);
	pipe(killme);
	check = fork();
	counter = 1;
	if (check < 0)
		printf("Failed\n");
	else if (check == 0) //child
	{
		child_process(counter, fd, &rwstatus, killme);
	}
	else //parent
	{
		parent_process(counter, fd, &rwstatus, killme);
	}
}