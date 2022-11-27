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

void	make_pipes(t_pipex *fd_list, int count)
{
	int	i;
	int	ehe[2];

	fd_list->pipe_read = malloc (sizeof(int) * (count + 1));
	fd_list->pipe_write = malloc (sizeof(int) * (count + 1));
	fd_list->pipe_read[0] = fd_list->infile;
	i = 1;
	while (i <= count)
	{
		if (pipe(ehe) == -1)
		{
			printf("Max Pipe Allowed Reached\n");
			exit(1024);
		}
		fd_list->pipe_read[i] = ehe[0];
		fd_list->pipe_write[i - 1] = ehe[1]; 
		i++;
	}
	fd_list->pipe_write[i - 1] = fd_list->outfile;
	fd_list->total = i;
}

void	here_doc(t_pipex *fd_list, char **av, int ac)
{
	fd_list->infile = 0;
	fd_list->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	make_pipes(fd_list, (ac - 3) - 1);
	fill_in_pipe(STDIN_FILENO, fd_list->pipe_write[0], av[2]);
}

int	get_fd(t_pipex *fd_list, char **av, int ac)
{
	fd_list->infile = open(av[1], O_RDONLY);
	if (fd_list->infile == -1)
		return (0);
	fd_list->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	make_pipes(fd_list, (ac - 3) - 1);
	return (1);
}
