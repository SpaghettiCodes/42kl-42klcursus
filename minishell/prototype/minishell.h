#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "ft_split.h"
#include <sys/types.h>
#include <sys/wait.h>

#define	STDIN 0
#define	STDOUT 1
#define TRUE 1
#define FALSE 0

typedef	char	*str;
typedef	char	bool;

typedef struct s_info
{

	int		in_fd;
	int		out_fd;
	int		pipe_count;

	str		full_input;
	// freeable
	str		*splitted_input;

	// based on splitted_input
	str		command;
	str		*arguments;
	str		command_path;

	bool	path_defined;
} t_info;

typedef struct s_variables
{
	char	*keyword;
	char	*definition; 
	struct	s_variables *next;
} t_variables;

#endif