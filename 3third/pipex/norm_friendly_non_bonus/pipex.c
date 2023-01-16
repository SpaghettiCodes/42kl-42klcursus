#include "pipex.h"
#include <stdarg.h>
#include <sys/types.h> 
#include <sys/wait.h> 

int	fork_child(t_pipex pipex, char **av, char **envp, char **paths)
{
	int	childfd;
	int	child2fd;

	childfd = fork();
	if (childfd == 0)
		childone(pipex, av, envp, paths);
	else if (childfd == -1)
		return (eprint("fork", ": fork failed"));
	else
	{
		close(pipex.pipefd[1]);
		waitpid(childfd, NULL, 0);
		child2fd = fork();
		if (child2fd == 0)
			childtwo(pipex, av, envp, paths);
		else if (child2fd == -1)
			return (eprint("fork", ": fork failed"));
		else
		{
			close(pipex.pipefd[0]);
			waitpid(child2fd, NULL, 0);
		}
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	pipex;
	char	**paths;

	if (ac != 5)
		return (eprint("ARGS", ": Not enough arguments"));
	pipex.infile = open(av[1], O_RDONLY);
	if ( pipex.infile == -1)
		return(eprint(av[1], ": No such file or directory"));
	pipex.outfile = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if ( pipe(pipex.pipefd) == -1 )
		return (eprint("PIPE", ": pipe failed"));
	paths = ft_split(get_paths(envp), ':');
	fork_child(pipex, av, envp, paths);
	free_all(NULL, paths);
	close(pipex.pipefd[1]);
	close(pipex.pipefd[0]);
	return (0);
}