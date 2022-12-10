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
	int		first_childpid;
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
		pipex.cmd = &av[3];
		pipex.cmd_num = ac - 4;
	}
	else
	{
		get_fd(&pipex, av, ac);
		pipex.cmd = &av[2];
		pipex.cmd_num = ac - 3;
	}
	pipex.ac = (ac - 1) - 1;
	pipex.path = ft_split((get_paths(envp)), ':');
	first_childpid = fork();
	if (first_childpid == 0)
		child(pipex, 0, pipex.outfile);
	free_all(NULL, pipex.path);
	waitpid(first_childpid, NULL, 0);
	printf("done\n");
	return (0);
}