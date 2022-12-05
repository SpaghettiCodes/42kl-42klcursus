#include "pipex.h"

void	fill_in_pipe(int in_file, int out_fd, char *limiter)
{
	char	*line;

	while (1)
	{
		write(in_file, "> ", 2);
		line = get_next_line(in_file);
		if (ft_strcmp_nl(line, limiter))
		{
			if (line)
				free(line);
			break;
		}
		if (!line)
			break;
		write(out_fd, line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(t_pipex *pipex, char **av, int ac, int p[2])
{
	pipex->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	fill_in_pipe(STDIN_FILENO, p[1], av[2]);
	close(p[1]);
	pipex->infile = p[0];
	pipex->cmd = &av[3];
	pipex->cmd_num = ac - 4;
	pipex->binary_paths = malloc (sizeof(char *) * (ac - 3));
}

void	get_fd(t_pipex *pipex, char **av, int ac)
{
	pipex->infile = open(av[1], O_RDONLY);
	if (pipex->infile == -1)
		exit(eprint(av[1], "No such file or directory"));
	pipex->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	pipex->cmd = &av[2];
	pipex->cmd_num = ac - 3;
	pipex->binary_paths = malloc (sizeof(char *) * (ac - 2));
}
