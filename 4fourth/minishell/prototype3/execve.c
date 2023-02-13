#include "minishell.h"

char	*get_binarypath(char *command, t_val *global_var)
{
	char	*test;
	char	**paths;
	int		i;

	i = -1;
	paths = ft_split(search_variable("PATH", global_var)->define, ':');
	while (paths[++i])
	{
		test = n_append(paths[i], "/\0");
		test = append(test, command);
		if (access(test, X_OK) == 0)
		{
			printf("Found path %s\n", test);
			free_darray(&paths);
			return (test);
		}
		free(test);
	}
	free_darray(&paths);
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
	ret = malloc (sizeof(char *) * count_val(in));
	while (in)
	{
		ret[i] = n_append(in->keyword, "=");
		ret[i] = append(ret[i], in->define);
		++i;
		in = in->next;
	}
	return (ret);
}

int	run_execve(t_cmd *cmd, t_val *global_var)
{
	char	*path;
	char	**env;
	// dup2(cmd_info.in_fd, STDIN);
	// dup2(cmd_info.out_fd, STDOUT);

	if (!cmd->final_cmd_line[0])
		exit(69);
	printf("getting paths\n");
	path = get_binarypath(cmd->final_cmd_line[0], global_var);
	printf("path = %s\n", path);
	
	if (!cmd->final_cmd_line[1])
		printf("no cmd line\n");
	else
		printf("cmd line = %s\n", cmd->final_cmd_line[1]);
	
	printf("getting env\n");
	env = variable_to_darray(global_var);
	
	printf("env = %s\n", env[0]);

	printf("executing\n");
	if ( execve(path, &cmd->final_cmd_line[1], env) == -1 )
		perror(strerror(errno));
}

// test code will reformat everything later
int	execute(t_cmd_info *cmd_info)
{
	int		pid;
	t_cmd	*cmd;

	pid = 0;
	cmd = cmd_info->cmd;
	while (cmd)
	{
		pid = fork();
		if (pid == -1)
		{
			perror(strerror(errno));
			write(2, "forked failed\n", 14);
			return (1);
		}
		else if (!pid)
		{
			printf("in child\n");
			run_execve(cmd, cmd_info->global_var);
			exit(1);
		}
		else
			cmd = cmd->next;
	}
}