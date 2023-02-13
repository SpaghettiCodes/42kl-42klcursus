#include <unistd.h>
#include <string.h>

#include <stdlib.h>
#include <errno.h>

int main(int ac, char **av, char **envp)
{
	char **arg;

	arg = malloc(sizeof(char *) * 2);
	arg[0] = "ls";
	arg[1] = NULL;
	if (execve("/usr/bin/ls", arg, envp) == -1)
		perror(strerror(errno));
}