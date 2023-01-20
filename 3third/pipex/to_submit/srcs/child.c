/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:05:57 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/21 00:38:36 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_error(char **binary_path, char *asp, char *msg)
{
	free_double_arr(binary_path);
	return (eprint(asp, msg));
}

int	exe_cmd(char *cmd_path, char *cmd, char **envp)
{
	char	**command;

	if (!cmd_path)
		return (1);
	command = ft_split(cmd, ' ');
	if (command)
	{
		if (execve(cmd_path, command, envp) == -1)
			perror(strerror(errno));
	}
	else
		eprint("ft_split", "split failed");
	free(cmd_path);
	free_double_arr(command);
	return (1);
}

void	next_child(t_pipex pipex, int *next_pipe, int index)
{
	int	next_childfd;

	next_childfd = fork();
	if (!next_childfd)
	{
		child(pipex, index, next_pipe[1]);
		exit (1);
	}
	else if (next_childfd == -1)
		exit(child_error(pipex.binary_paths, "fork", "fork failed"));
	else
		close(next_pipe[1]);
}

void	child(t_pipex pipex, int index, int out)
{
	char	*binary_paths;
	int		next_pipe[2];

	++index;
	if (dup2(out, STDOUT_FILENO) == -1)
		exit(child_error(pipex.binary_paths, "dup2", "output redirection failed"));
	close(out);
	if (pipex.cmd_num - index)
	{
		if (pipe(next_pipe) == -1)
			exit(child_error(pipex.binary_paths, "Pipe", "Something Went Wrong"));
		if (dup2(next_pipe[0], STDIN_FILENO) == -1)
			exit(child_error(pipex.binary_paths, "dup2", "input redirection failed"));
		close(next_pipe[0]);
		next_child(pipex, next_pipe, index);
	}
	else
	{
		if (dup2(pipex.infile, STDIN_FILENO) == -1)
			exit(child_error(pipex.binary_paths, "dup2", "input redirection failed"));
		close(pipex.infile);
	}
	binary_paths = ft_strdup(pipex.binary_paths[pipex.cmd_num - index]);
	free_double_arr(pipex.binary_paths);
	if (exe_cmd(binary_paths, pipex.cmd[pipex.cmd_num - index], pipex.envp))
		exit(1);
}
