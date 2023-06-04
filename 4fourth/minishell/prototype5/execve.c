#include "minishell.h"

char	*get_binarypath(char *command, t_val *global_var)
{
	char	*test;
	char	**paths;
	int		i;

	i = -1;
	if (!command[0])
		return (NULL);
	if (search_character(command, '/', 0, -1) != -1)
		return (access(command, X_OK) ? NULL : ft_strdup(command));
	paths = ft_split(&search_variable("PATH", global_var)->theline[5], ':');
	while (paths[++i])
	{
		test = n_append(paths[i], "/\0");
		test = append(test, command);
		if (access(test, X_OK) == 0)
		{
			free_darray(paths);
			return (test);
		}
		free(test);
	}
	free_darray(paths);
	return (NULL);
}

unsigned int	count_val(t_val *in)
{
	unsigned int	ret;

	ret = 0;
	while (in)
	{
		++ret;
		in = in->next;
	}
	return (ret);
}

char	**variable_to_darray(t_val *in)
{
	char		**ret;
	unsigned int	i;
	
	i = 0;
	ret = malloc (sizeof(char *) * (count_val(in) + 1));
	while (in)
	{
		ret[i] = ft_strdup(in->theline);
		++i;
		in = in->next;
	}
	ret[i] = 0;
	return (ret);
}

int	run_execve(t_cmd *cmd, t_val *global_var)
{
	char	*path;
	char	**env;

	if (!cmd->final_cmd_line)
		exit(420);
	if (!cmd->final_cmd_line[0])
		exit(69);
	path = get_binarypath(cmd->final_cmd_line[0], global_var);
	env = variable_to_darray(global_var);
	if (!path)
		exit(eprint(cmd->final_cmd_line[0], "command does not exist"));
	if (execve(path, &cmd->final_cmd_line[0], env) == -1)
		perror(strerror(errno));
}

int	builtin(t_cmd	*cmd_info, t_cmd_info	*shell_info)
{
	if (!ft_strcmp(cmd_info->final_cmd_line[0], "echo"))
		return (echo(cmd_info->final_cmd_line, shell_info));
	else if (!ft_strcmp(cmd_info->final_cmd_line[0], "cd"))
		return (change_dir(cmd_info->final_cmd_line, shell_info));
	else if (!ft_strcmp(cmd_info->final_cmd_line[0], "pwd"))
		return (pwd(shell_info));
	else if (!ft_strcmp(cmd_info->final_cmd_line[0], "export"))
		return (export(cmd_info->final_cmd_line, shell_info));
	else if (!ft_strcmp(cmd_info->final_cmd_line[0], "unset"))
		return (unset_variables(cmd_info->final_cmd_line, &shell_info->global_var));
	else if (!ft_strcmp(cmd_info->final_cmd_line[0], "env"))
		return (list_env(shell_info->global_var));
	else if (!ft_strcmp(cmd_info->final_cmd_line[0], "exit"))
		return (clean_exit(shell_info));
	else
		return (1);
}

void	ignore_allsignal()
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	update_last_exit(int last_exit, t_cmd_info *cmd_info)
{
	cmd_info->last_exit = last_exit;
}

void	fork_error()
{
	perror(strerror(errno));
	write(2, "forked failed\n", 14);
	exit (-1);
}

void	execute_child(t_cmd *cmd, t_cmd_info *cmd_info)
{
	dup2(cmd->infd, STDIN);
	dup2(cmd->outfd, STDOUT);

	if (!builtin(cmd, cmd_info))
	{
		close(cmd->infd);
		close(cmd->outfd);
		clean_exit(cmd_info);
	}
	run_execve(cmd, cmd_info->global_var);
	exit (126);
}

int	fork_you(int no_cmd, int close_this, t_cmd *cmd, t_cmd_info *cmd_info)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		fork_error();
	else if (!pid)
	{
		if (!(no_cmd == cmd_info->no_cmd - 1))
			close(close_this);
		execute_child(cmd, cmd_info);
	}
	else
		return (0);
}

void	wait_for_children(t_cmd_info *cmd_info)
{
	int	exit_status;
	int	i;

	i = 0;
	while (i < cmd_info->no_cmd)
	{
		waitpid(-1, &exit_status, 0);
		update_last_exit(exit_status, cmd_info);
		++i;
	}
}

void	do_piping_and_send_child(t_cmd *cmd, t_cmd_info *cmd_info)
{
	int	pipe_holder[2];
	int	prev_pipe;
	int	command_launched;

	command_launched = 0;
	while (cmd)
	{
		if (command_launched)
			cmd->infd = prev_pipe;
		if (!(command_launched == cmd_info->no_cmd - 1))
		{
			pipe(pipe_holder);
			cmd->outfd = pipe_holder[1];
		}
		if (!fork_you(command_launched, pipe_holder[0], cmd, cmd_info))
		{
			if (command_launched)
				close(prev_pipe);
			if (!(command_launched == cmd_info->no_cmd - 1))
			{
				close(pipe_holder[1]);
				prev_pipe = pipe_holder[0];
			}
		}
		++command_launched;
		cmd = cmd->next;
	}
	wait_for_children(cmd_info);
}

// test code will reformat everything later
int	execute(t_cmd_info *cmd_info)
{
	int		exit_status;
	int		pid;
	t_cmd	*cmd;

	pid = 0;
	cmd = cmd_info->cmd;
	if (cmd_info->no_cmd == 1)
	{
		if (builtin(cmd, cmd_info))
		{
			pid = fork();
			if (pid == 0)
				exit (run_execve(cmd, cmd_info->global_var));
			else
			{
				ignore_allsignal();
				waitpid(pid, &exit_status, 0);
				update_last_exit(exit_status, cmd_info);
			}
		}
		else
			printf("built-in successfully launched\n");
	}
	else
		do_piping_and_send_child(cmd, cmd_info);
}