#include "pipex.h"
#include <stdarg.h>

// ./pipex infile cmd cmd outfile

int	free_all(char *item, char **items)
{
	int	i;

	if (item)
		free(item);
	if (items)
	{
		i = 0;
		while (items[i])
		{
			free(items[i]);
			i++;
		}
		free(items);
	}
	return (6);
}

// returns the address of the string that contains the paths from envp
char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strcmp(envp[i], "PATH\0"))
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		h_d[2];
	int		index;
	char	**paths;

	if (ac < 5)
		return (eprint("ARG", "not enough arguments"));

	pipex.envp = envp;
	if (ft_strcmp(av[1], "here_doc"))
	{
		pipe(h_d);
		here_doc(&pipex, av, ac, h_d);
	}
	else
		get_fd(&pipex, av, ac);
	paths = ft_split(get_paths(envp), ':');
	if(!test_cmd(&pipex, paths))
		return (free_all(NULL, paths));
	if (!fork())
		child(pipex, -1, pipex.infile);
	else
	{
		index = 0;
		while (index < pipex.cmd_num)
		{
			waitpid(-1, NULL, 0);
			index++;
		}
	}
	free_all(NULL, paths);
	free_all(NULL, pipex.binary_paths);
	return (0);
}