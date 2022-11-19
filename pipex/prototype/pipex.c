#include "pipex.h"

// ./pipex infile cmd cmd outfile

char *Binary_Path = "/usr/bin/\0";

typedef	struct s_pipex{
	int infile;
	int outfile; 
	int	pipefd[2]; // 0 - read, 1 - write
} t_pipex;

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
	return (ret);
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
	path = append(Binary_Path, command[0]);
	if (access(path, F_OK) != 0)
	{
		perror("Error: command not found\n");
		exit(69);
	}
	if (execve(path, command, envp) == -1)
		perror("Execution Failed\n");
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
	path = append(Binary_Path, command[0]);
	if (access(path, F_OK) != 0)
	{
		perror("Error: command not found\n");
		exit(69);
	}
	if (execve(path, command, envp) == -1)
		perror("Execution Failed\n");
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	fl_desc;
	int	childfd;
	int	child2fd;

	if (ac != 5)
		return (5);
	fl_desc.infile = open(av[1], O_RDONLY);
	if (fl_desc.infile == -1)
		return (1);
	if (access(av[4], F_OK) == 0)
		unlink(av[4]);
	fl_desc.outfile = open(av[4], O_CREAT | O_RDWR, 0777);
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
	printf("Done\n");
	return (0);
}