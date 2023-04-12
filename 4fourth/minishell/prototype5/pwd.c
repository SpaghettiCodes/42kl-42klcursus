#include "minishell.h"

int	pwd(t_cmd_info *cmd_main)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	write(1, pwd, ft_strlen(pwd));
	write(1, "\n", 1);
	cmd_main->last_exit = 0;
	return (0);
}