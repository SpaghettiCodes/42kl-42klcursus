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

typedef struct s_cmd_info
{
	// both of em are freeable
	str		fulL_cmd;
	str		*splitted_cmd;

	// not freeable, based on splitted_cmd
	str		cmd;
	// not freeable, based on splitted_cmd
	str		*arg;
	// freeable
	str		command_path;

	bool	path_defined;
}	t_cmd_info;

typedef struct s_info
{

	int		in_fd;
	int		out_fd;
	// cmd count = pipe_count
	int		pipe_count;

	t_cmd_info	*cmd_info;
} t_info;

typedef struct s_variables
{
	char	*keyword;
	char	*definition; 
	struct	s_variables *next;
} t_variables;

#endif