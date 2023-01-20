/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:27 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/21 00:32:31 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		free_double_arr(pipex.binary_paths);
		return (eprint("FORK", "fork failed"));
	}
	else if (first_childpid == 0)
		child(pipex, 0, pipex.outfile);
	else
	{
		free_double_arr(pipex.binary_paths);
		waitpid(first_childpid, NULL, 0);
	}
	return (0);
}

char	**set_paths(char **envp)
{
	char	*path_var;
	char	**ret;

	path_var = get_paths(envp);
	if (!path_var)
	{
		eprint("PATH", "Who the hell unsetted path???");
		return (NULL);
	}
	ret = ft_split(path_var, ':');
	if (!ret)
	{
		eprint("ft_split", "split failed");
		return (NULL);
	}
	return (ret);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	int		h_d[2];

	if (ac < 5)
		return (eprint("ARG", "not enough arguments"));
	pipex.envp = envp;
	pipex.path = set_paths(envp);
	if (!pipex.path)
		return (20);
	if (ft_strfind(av[1], "here_doc"))
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
	parse_path(&pipex);
	free_double_arr(pipex.path);
	return (fork_child(pipex));
}
