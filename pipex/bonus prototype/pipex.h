#ifndef PIPEX_H
#define PIPEX_H

#include "ft_split.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include "get_next_line.h"

typedef	struct s_pipex{
	int		infile;
	int		outfile; 
	int		pipefd[2]; // 0 - read, 1 - write
	int		debug_1;
	int		debug_2;
	char	*limiter;
} t_pipex;

#endif