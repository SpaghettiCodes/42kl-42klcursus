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

void	close_and_repipe(int *pfd, int *usedcount)
{
	close(pfd[0]);
	close(pfd[1]);
	pipe(pfd);
	*usedcount = 0;
}

void	closetwo(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	determine_pipes(t_pipex pipex, int i, int *pfd, int *pfd2)
{
	int in;

	if (i == 0)
		child(pipex, i, pipex.infile, pfd[1]);
	else if (i == (pipex.cmd_num - 1))
	{
		closetwo(pfd[1], pfd2[1]);
		in = pfd2[0];
		if (i % 2)
			in = pfd[0];
		child(pipex, i, in, pipex.outfile);
	}
	else
	{
		if (i % 2)
		{
			closetwo(pfd2[0], pfd[1]);
			child(pipex, i, pfd[0], pfd2[1]);
		}
		else
		{
			closetwo(pfd[0], pfd2[1]);
			child(pipex, i, pfd2[0], pfd[1]);
		}
	}
}

void	forkchilds(t_pipex pipex)
{
	int i = 0, usedp1 = 0, usedp2 = 0, childpid;
	int	pfd[2];
	int	pfd2[2];
	pipe(pfd);
	pipe(pfd2);
	while (i < pipex.cmd_num)
	{
		childpid = fork();
		if (!childpid)
			determine_pipes(pipex, i, pfd, pfd2);
		else
		{
			if (i != 0)
				usedp2++;
			usedp1++;
			if (usedp1 == 2)
				close_and_repipe(pfd, &usedp1);
			if (usedp2 == 2)
				close_and_repipe(pfd2, &usedp2);
			waitpid(childpid, 0, 0);
			i++;
		}
	}
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

	forkchilds(pipex);
	free_all(NULL, pipex.path);
	printf("done\n");
	return (0);
}