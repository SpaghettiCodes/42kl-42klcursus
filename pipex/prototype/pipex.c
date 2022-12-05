#include "pipex.h"
#include <stdarg.h>
#include <sys/types.h> 
#include <sys/wait.h> 

char	free_all(char *item, char **items)
{
	int	i;

	if (item)
		free(item);
	if (items)
	{
		i = 0;
		while (items[i])
		{
			free(items[i]);
			i++;
		}
		free(items);
	}
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

// like append but DOES NOT free str1
char	*n_append(char *str1, char *str2)
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

char	*get_binarypath(char *command, char **paths)
{
	char	*test;
	int		i;

	i = -1;
	while (paths[++i])
	{
		test = n_append(paths[i], "/\0");
		test = append(test, command);
		if (access(test, X_OK) == 0)
			return (test);
		free(test);
	}
	return (NULL);
}

void	childone(t_pipex fl_desc, char **av, char **envp, char **paths)
{
	char	*path;
	char	**command;

	close(fl_desc.outfile);
	close(fl_desc.pipefd[0]);

	if (dup2(fl_desc.infile, STDIN_FILENO) == -1)
		perror("Failed\n");
	if (dup2(fl_desc.pipefd[1], STDOUT_FILENO) == -1)
		perror("Failed\n");

	command = ft_split(av[2], ' ');

	if (execve(fl_desc.binary_paths[0], command, envp) == -1)
		perror(strerror(errno));
}

void	childtwo(t_pipex fl_desc, char **av, char **envp, char **paths)
{
	char	**command;
	char	*path;
	char	*buff;

	close(fl_desc.infile);
	close(fl_desc.pipefd[1]);

	dup2(fl_desc.pipefd[0], STDIN_FILENO);
	dup2(fl_desc.outfile, STDOUT_FILENO);

	command = ft_split(av[3], ' ');

	if (execve(fl_desc.binary_paths[1], command, envp) == -1)
		perror(strerror(errno));
}

int	eprint(char *element, char *msg)
{
	write(2, "./pipex: ", 10);
	if (element)
		write(2, element, ft_strlen(element));
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return(11 + ft_strlen(element) + ft_strlen(msg));
}

void	test_cmd(char **av, char **paths, t_pipex pipex)
{
	int		i;
	char	*test;
	char	**cmd;

	i = 2;
	while (i <= 3)
	{
		cmd = ft_split(av[i], ' ');
		test = get_binarypath(cmd[0], paths);
		if (test == NULL)
		{
			free_all(test, cmd);
			exit(eprint(av[i], ": command not found"));
		}
		pipex.binary_paths[i - 2] = ft_strdup(test);
		free_all(test, cmd);
		i++;
	}
	pipex.binary_paths[i - 2] = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		childfd;
	int		child2fd;
	char	**paths;

	if (ac != 5)
		return (eprint("ARGS", ": Not enough arguments"));

	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile == -1)
		return(eprint(av[1], ": No such file or directory"));
	pipex.outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	
	paths = ft_split(get_paths(envp), ':');
	
	pipex.binary_paths = malloc (sizeof(char *) * 3);
	test_cmd(av, paths, pipex);

	if (pipe(pipex.pipefd) == -1)
		return (eprint("PIPE", ": pipe failed"));

	childfd = fork();
	if (childfd == 0)
		childone(pipex, av, envp, paths);
	else
	{
		child2fd = fork();
		if (child2fd == 0)
			childtwo(pipex, av, envp, paths);
	}

	free_all(NULL, paths);
	free_all(NULL, pipex.binary_paths);
	close(pipex.pipefd[1]);
	close(pipex.pipefd[0]);
    waitpid(childfd, NULL, 0);
    waitpid(child2fd, NULL, 0);
	return (0);
}