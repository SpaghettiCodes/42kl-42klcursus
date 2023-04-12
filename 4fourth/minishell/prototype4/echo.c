#include "minishell.h"

void	echo_place(char *string)
{
	write(1, string, ft_strlen(string));
}

int	parameters(char **arg)
{
	int	i;

	i = 1; 
	while (arg[i] && !ft_strcmp(arg[i], "-n"))
		++i;
	return (i);
}

int	echo(char **arg, t_cmd_info *shell_info)
{
	int	i;
	int	nl;

	nl = parameters(arg);
	i = nl;
	while (arg[i])
	{
		echo_place(arg[i]);
		if (arg[i + 1])
			write(1, " ", 1);
		++i;
	}
	write(1, "\n", !nl);
	shell_info->last_exit = 0;
	return (0);
}