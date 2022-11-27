#include "pipex.h"
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdarg.h>

// ./pipex infile cmd cmd outfile

void	debug_print(int	fd, char *format, ...)
{
	va_list ptr;
	va_start(ptr, format);
	char *test;
	for (int i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			test = va_arg(ptr, char *);
			if (!test)
				write(fd, "NULL", 4);
			else
				debug_print(fd, test);
		}
		else
			write(fd, &format[i], 1);
	}
	va_end(ptr);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int	count;
	int	index;
	int	test;
	int	status;

	if (ac < 5)
		return (5);
	
	// debug purposes lmao
	pipex.debug_1 = open("debug_child_1", O_RDWR | O_TRUNC | O_CREAT);

	if (ft_strcmp(av[1], "here_doc"))
		here_doc(&pipex, av, ac);
	else
	{
		if (!get_fd(&pipex, av, ac))
		{
			perror("Cant Find File");
			exit(1);
		}
	}
	if (pipex.infile == STDIN_FILENO)
	{
		index = 1;
		count = 3;
	}
	else
	{
		index = 0;
		count = 2;
	}
	while (count <= (ac - 2))
	{
		printf("Forked %dth!\n", index);
		test = fork();
		if (test == 0)
		{
			child(pipex, av[count], envp, index);
		}
		printf("Childpid = %d\n", test);
		index++;
		count++;
	}

	if (pipex.infile == STDIN_FILENO)
		count = 3;
	else
		count = 2;
	while (count <= (ac - 2))
		printf("Someone is done %d\n", 	waitpid(-1, &status, 0));
	return (0);
}