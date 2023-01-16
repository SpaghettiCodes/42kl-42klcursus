#include "pipex.h"

void	eprint_warn_heredoc(char *limiter)
{
	write(2, "\npipex: warning: here-document delimited by end-of-file", 56);
	write(2, " (wanted '", 11);
	write(2, limiter, ft_strlen(limiter));
	write(2, "')\n", 3);
}

void	print_nl(char *stuff)
{
	for (int i = 0; i < ft_strlen(stuff); ++i) {
		if (stuff[i] == '\n')
			write(1, "\\n", 2);
		else
			write(1, &stuff[i], 1);
	}
}

void	fill_in_pipe(int in_file, int out_fd, char *limiter)
{
	char	*line;

	while (1)
	{
		write(in_file, "> ", 2);
		line = get_next_line(in_file);
		print_nl(line);

		if (!line)
		{
			eprint_warn_heredoc(limiter);
			break;
		}
		if (ft_strcmp_nl(line, limiter))
		{
			if (line)
				free(line);
			break;
		}
		if (*line == '\n')
		{
			free(line);
			continue;
		}
		write(out_fd, line, ft_strlen(line));
		free(line);
	}
}

void	here_doc(t_pipex *fd_list, char **av, int ac, int p[2])
{
	fd_list->outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	fill_in_pipe(STDIN_FILENO, p[1], av[2]);
	close(p[1]);
	fd_list->infile = p[0];
}

void	get_fd(t_pipex *fd_list, char **av, int ac)
{
	fd_list->infile = open(av[1], O_RDONLY);
	if (fd_list->infile == -1)
		exit(eprint(av[1], "No such file or directory"));
	fd_list->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
}
