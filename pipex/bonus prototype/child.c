#include "pipex.h"

void	close_every_other_fd(t_pipex *pipex, int	skip)
{
	int	i;

	i = -1;
	while (++i < pipex->total)
	{
		if (i == skip)
			continue;
		close(pipex->pipe_read[i]);
		close(pipex->pipe_write[i]);
	}
}

void	child(t_pipex pipex, char *command, char **envp, int index)
{
	char	**command_splitted;
	char	*path;
	char	*buff;

	close_every_other_fd(&pipex, index);
	dup2(pipex.pipe_read[index], STDIN_FILENO);
	dup2(pipex.pipe_write[index], STDOUT_FILENO);

	command_splitted = ft_split(command, ' ');
	path = get_binarypath(envp, command_splitted[0], pipex);
	debug_print(pipex.debug_1, "PATH: %s\n", path);
	if (path)
	{
		if (execve(path, command_splitted, envp) == -1)
			perror(strerror(errno));
	}
	else
		write(2, "\nError: Command Doesn't Exists\n", 32);
	exit(69);
}