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
	i = 0;
	while (str1 && str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2 && str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	free(str1);
	return (ret);
}

int		find_in_string(char *str1, char *str2)
{
	int	i;
	
	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str2[i] && str1[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (find_in_string(envp[i], "PATH\0"))
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

void	child(t_pipex fl_desc, char *command, char **envp)
{
	char	*path;
	char	**splitted_command;

	close(STDIN_FILENO);
	if (dup2(fl_desc.pipefd[0], STDIN_FILENO) == -1)
		perror("Failed\n");
	close(STDOUT_FILENO);
	if (dup2(fl_desc.pipefd[1], STDOUT_FILENO) == -1)
		perror("Failed\n");
	splitted_command = ft_split(command, ' ');
	path = get_binarypath(envp, splitted_command[0], fl_desc);
	debug_print(fl_desc.debug_1, "\nPATH: %s\n", path);	
	if (path)
	{
		if (execve(path, splitted_command, envp) == -1)
			perror(strerror(errno));
	}
	else
		write(2, "\nError: Command Doesn't Exists\n", 32);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i])
		if (!str2[i])
			return (1);
	return (0);
}

void	fill_in_pipe(int	in_file, int	out_fd, char *limiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(in_file);
		if (!line || ft_strcmp(line, limiter))
		{
			if (line)
				free(line);
			break;
		}
		write(out_fd, line, ft_strlen(line));
		free(line);
	}
}

void	fill_to_out(int in_pipe, int out_pipe, int	outfile)
{
	char	buff[100];
	char	*content;
	int		check;
	
	write(in_pipe, "\0", 1);
	content = NULL;
	while (1)
	{
		check = read(out_pipe, buff, 99);
		if (find_in_string(buff, "\0"))
		{
			printf("End\n");
			break;
		}
		buff[check] = 0;
		content = append(content, buff);
	}
	content = append(content, buff);
	write(outfile, content, str_len(content));
}

void	here_doc(t_pipex *fd_list, char **av, int ac)
{
	fd_list->infile = 0;
	fd_list->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	pipe(fd_list->pipefd);
	fill_in_pipe(STDIN_FILENO, fd_list->pipefd[1], av[2]);
}

int	get_fd(t_pipex *fd_list, char **av, int ac)
{
	fd_list->infile = open(av[1], O_RDONLY);
	if (fd_list->infile == -1)
		return (0);
	fd_list->outfile = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	pipe(fd_list->pipefd);
	fill_in_pipe(fd_list->infile, fd_list->pipefd[1], NULL);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	fl_desc;
	int	childfd;
	int	child2fd;
	int	count;

	if (ac < 5)
		return (5);
	
	// debug purposes lmao
	fl_desc.debug_1 = open("debug_child_1", O_RDWR | O_TRUNC | O_CREAT);

	if (ft_strcmp(av[1], "here_doc"))
		here_doc(&fl_desc, av, ac);
	else
	{
		if (!get_fd(&fl_desc, av, ac))
		{
			perror("Cant Find File");
			exit(1);
		}
	}

	count = 2;
	while (count < ((ac - 1)))
	{
		printf("Forked\n");
		childfd = fork();
		if (childfd == 0)
			child(fl_desc, av[count], envp);
		// fuuuuuuuuuuck go test this eventually
		// waitpid(childfd, &status, 0);
		count++;
	}
	printf("Writing to Outfile...\n");
	fill_to_out(fl_desc.pipefd[1], fl_desc.pipefd[0], fl_desc.outfile);
	close(fl_desc.pipefd[0]);
	close(fl_desc.pipefd[1]); 
	return (0);
}