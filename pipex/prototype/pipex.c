#include "pipex.h"
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


char	*append(char *str1, char *str2)
{
	char	*ret;
	int	i;
	int	j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	free(str1);
	return (ret);
}

int		ft_strcmp(char *str1, char *str2)
{
	int	i;
	
	i = 0;
	while (str1 && str2 && str1[i] == str2[i])
	{
		if (!str2[i + 1])
			return (1);
		i++;
	}
	return (0);
}

char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "PATH\0"))
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

char	*get_binarypath(char **envp, char *command, t_pipex fl_desc)
{
	char	*test;
	int		i;
	char	**paths;

	paths = ft_split(get_paths(envp), ':');
	i = -1;
	while (paths[++i])
	{
		paths[i] = append(paths[i], "/\0");
		paths[i] = append(paths[i], command);
		test = paths[i];
		if (access(test, F_OK) == 0)
			return (test);
		free(test);
	}
	return (NULL);
}

void	childone(t_pipex fl_desc, char **av, char **envp)
{
	char	*path;
	char	**command;

	close(fl_desc.outfile);
	close(fl_desc.pipefd[0]);
	close(STDIN_FILENO);
	if (dup2(fl_desc.infile, STDIN_FILENO) == -1)
		perror("Failed\n");
	close(STDOUT_FILENO);
	if (dup2(fl_desc.pipefd[1], STDOUT_FILENO) == -1)
		perror("Failed\n");
	command = ft_split(av[2], ' ');
	path = get_binarypath(envp, command[0], fl_desc);
	debug_print(fl_desc.debug_1, "PATH: %s\n", path);	
	if (path)
	{
		if (execve(path, command, envp) == -1)
			perror(strerror(errno));
	}
	else
		write(2, "\nError: Command Doesn't Exists\n", 32);
}

void	childtwo(t_pipex fl_desc, char **av, char **envp)
{
	char	**command;
	char	*path;
	char	*buff;

	close(fl_desc.infile);
	close(fl_desc.pipefd[1]);
	close(STDIN_FILENO);
	dup2(fl_desc.pipefd[0], STDIN_FILENO);
	close(STDOUT_FILENO);
	dup2(fl_desc.outfile, STDOUT_FILENO);
	command = ft_split(av[3], ' ');
	path = get_binarypath(envp, command[0], fl_desc);
	debug_print(fl_desc.debug_2, "PATH: %s\n", path);
	if (path)
	{
		if (execve(path, command, envp) == -1)
			perror(strerror(errno));
	}
	else
		write(2, "\nError: Command Doesn't Exists\n", 32);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	fl_desc;
	int	childfd;
	int	child2fd;

	if (ac != 5)
		return (5);
	
	if (!access("debug_child_1", F_OK))
		unlink("debug_child_1");
	fl_desc.debug_1 = open("debug_child_1", O_RDWR);
	if (!access("debug_child_2", F_OK))
		unlink("debug_child_2");
	fl_desc.debug_2 = open("debug_child_2", O_RDWR);

	fl_desc.infile = open(av[1], O_RDONLY);
	if (fl_desc.infile == -1)
		return (1);
	fl_desc.outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	pipe(fl_desc.pipefd);

	childfd = fork();
	if (childfd == 0)
		childone(fl_desc, av, envp);
	else
	{
		child2fd = fork();
		if (child2fd == 0)
			childtwo(fl_desc, av, envp);
	}
	// doesnt work in windows
	// waitpid(childfd, &status, 0);
	// waitpid(child2fd, &status, 0);
	return (0);
}