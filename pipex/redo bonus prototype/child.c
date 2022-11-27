#include "pipex.h"

/* executes the command 
** exits automatically if success, returns 0 if an error occured
*/
int	execute_command(char *path, char *cmd, char **envp)
{
	char	**command;
	char	*buff;

	command = ft_split(cmd, ' ');
	if (execve(path, command, envp) == -1)
	{
		perror(strerror(errno));
	}
	return (0);
}

/* child process -- child process will create more child process to run all commands
** in = the STDIN of the child process
** child process will create the next pipe required for the next child process 
*/
void	child(t_pipex pipex, int index, int in)
{
	int	next_pipe_or_something[2];

	index++;
	dup2(in, STDIN_FILENO);
	close(in);
	if (index != (pipex.cmd_num - 1))
	{
		if (pipe(next_pipe_or_something) == -1)
			exit(eprint("Pipe", "Ah Shit Something Went Wrong"));
		dup2(next_pipe_or_something[1], STDOUT_FILENO);
		close(next_pipe_or_something[1]);
		if (!fork())
			child(pipex, index, next_pipe_or_something[0]);
		else
			close(next_pipe_or_something[0]);
	}
	else
		dup2(pipex.outfile, STDOUT_FILENO);

	if (!execute_command(pipex.binary_paths[index], pipex.cmd[index], pipex.envp))
		exit(1);
}
