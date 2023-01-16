#include "pipex.h"

int	eprint(char *element, char *msg)
{
	write(2, "pipex: ", 8);
	if (element)
		write(2, element, ft_strlen(element));
	write(2, ": ", 2);
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return(11 + ft_strlen(element) + ft_strlen(msg));
}

int	test_cmd(t_pipex *pipex, char **paths)
{
	int		i;
	char	*test;
	char	**cmd;

	i = 0; 
	while (i < pipex->cmd_num)
	{
		cmd = ft_split(pipex->cmd[i], ' ');
		test = get_binarypath(cmd[0], paths);
		if (!test)
		{
			free_all(NULL, cmd);
			free_all(NULL, pipex->binary_paths);
			eprint(pipex->cmd[i], "command not found");
			return(0);
		}
		pipex->binary_paths[i] = ft_strdup(test);
		pipex->binary_paths[i + 1] = 0;
		free_all(test, cmd);
		i++;
	}
	return (1);
}