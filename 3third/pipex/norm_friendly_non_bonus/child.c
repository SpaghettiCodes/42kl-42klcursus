#include "pipex.h"

void	childone(t_pipex fl_desc, char **av, char **envp, char **paths)
{
	char	*path;
	char	**command;

	close(fl_desc.outfile);
	close(fl_desc.pipefd[0]);
	if (dup2(fl_desc.infile, STDIN_FILENO) == -1 || 
			dup2(fl_desc.pipefd[1], STDOUT_FILENO) == -1)
	{
		free_all(NULL, paths);
		exit (eprint("dup2", ": input output redirection failed"));
	}
	command = ft_split(av[2], ' ');
	path = get_binarypath(command[0], paths);
	free_all(NULL, paths);
	if (!path)
	{
		eprint(command[0], ": command not found");
		free_all(NULL, command);
	}
	else if (execve(path, command, envp) == -1)
	{
		perror(strerror(errno));
		free_all(path, command);
	}
	exit(3);
}

void	childtwo(t_pipex fl_desc, char **av, char **envp, char **paths)
{
	char	**command;
	char	*path;

	close(fl_desc.infile);
	if (dup2(fl_desc.pipefd[0], STDIN_FILENO) == -1 || 
			dup2(fl_desc.outfile, STDOUT_FILENO) == -1)
	{
		free_all(NULL, paths);
		exit (eprint("dup2", "input output redirection failed"));
	}
	command = ft_split(av[3], ' ');
	path = get_binarypath(command[0], paths);
	free_all(NULL, paths);
	if (!path)
	{
		eprint(command[0], ": command not found");
		free_all(NULL, command);
	}
	else if (execve(path, command, envp) == -1)
	{
		perror(strerror(errno));
		free_all(path, command);
	}
	exit(3);
}