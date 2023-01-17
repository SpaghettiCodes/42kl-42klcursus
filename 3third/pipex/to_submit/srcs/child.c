/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:05:57 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 11:30:15 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_error(char **path, char *asp, char *msg)
{
	free_all(NULL, path);
	return (eprint(asp, msg));
}

int	execute_command(char **path, char *cmd, char **envp)
{
	char	**command;
	char	*cmd_path;

	command = ft_split(cmd, ' ');
	if (command)
	{
		cmd_path = get_binarypath(command[0], path);
		free_all(NULL, path);
		path = NULL;
		if (!cmd_path)
			eprint(command[0], "command not found");
		else if (execve(cmd_path, command, envp) == -1)
			perror(strerror(errno));
	}
	else
		eprint("ft_split", "split failed");
	free_all(command, path);
	return (1);
}

void	next_child(t_pipex pipex, int *next_pipe, int index)
{
	int	next_childfd;

	next_childfd = fork();
	if (!next_childfd)
		child(pipex, index, next_pipe[1]);
	else if (next_childfd == -1)
	{
		free_all(NULL, pipex.path);
		exit(eprint("fork", "fork failed"));
	}
	else
		close(next_pipe[1]);
}

void	child(t_pipex pipex, int index, int out)
{
	int	next_pipe[2];

	index++;
	dup2(out, STDOUT_FILENO);
	close(out);
	if (pipex.cmd_num - index)
	{
		if (pipe(next_pipe) == -1)
			exit(child_error(pipex.path, "Pipe", "Something Went Wrong"));
		if (dup2(next_pipe[0], STDIN_FILENO) == -1)
			exit(child_error(pipex.path, "dup2",
					"input output redirection failed"));
		close(next_pipe[0]);
		next_child(pipex, next_pipe, index);
	}
	else
	{
		if (dup2(pipex.infile, STDIN_FILENO) == -1)
			exit(child_error(pipex.path, "dup2",
					"input output redirection failed"));
		close(pipex.infile);
	}
	if (execute_command(pipex.path,
			pipex.cmd[pipex.cmd_num - index], pipex.envp))
		exit(1);
}
