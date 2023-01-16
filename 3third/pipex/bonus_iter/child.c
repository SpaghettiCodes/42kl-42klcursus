#include "pipex.h"

/* 
** executes the command 
** exits automatically if success, returns 0 if an error occured
*/
int	execute_command(char **path, char *cmd, char **envp)
{
	char	**command;
	char	*cmd_path;
	char	*buff;

	command = ft_split(cmd, ' ');
	cmd_path = get_binarypath(command[0], path);
	if (!cmd_path)
	{
		eprint(command[0], "command not found");
		free_all(NULL, command);
		free_all(NULL, path);
		return (1);
	}
	if (execve(cmd_path, command, envp) == -1)
		perror(strerror(errno));
	return (0);
}

/* child process -- child process will create more child process to run all commands
** in = the STDIN of the child process
** child process will create the next pipe required for the next child process 
*/
void	child(t_pipex pipex, int index, int in, int out)
{
	dup2(out, STDOUT_FILENO);
	close(out);
	dup2(in, STDIN_FILENO);
	close(in);
	if (execute_command(pipex.path, pipex.cmd[index], pipex.envp))
		return ;
}
