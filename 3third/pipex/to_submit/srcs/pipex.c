/* ************************************************************************** */

#include "pipex.h"
#include <stdarg.h>

char	*get_paths(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strfind(envp[i], "PATH\0"))
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

int	fork_child(t_pipex pipex)
{
	int	first_childpid;

	first_childpid = fork();
	if (first_childpid == -1)
	{
		free_all(NULL, pipex.path);
		return (eprint("FORK", "fork failed"));
	}
	else if (first_childpid == 0)
		child(pipex, 0, pipex.outfile);
	else 
	{
		free_all(NULL, pipex.path);
		waitpid(first_childpid, NULL, 0);
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		h_d[2];

	if (ac < 5)
		return (eprint("ARG", "not enough arguments"));
	pipex.envp = envp;
	if (ft_strfind (av[1], "here_doc"))
	{
		if (pipe(h_d) == -1)
			return (eprint("PIPE", "pipe failed"));
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
	pipex.path = ft_split((get_paths(envp)), ':');
	return (fork_child(pipex));
}