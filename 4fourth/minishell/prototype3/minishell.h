#ifndef MINISHELL_H
#define MINISHELL_H

#include <termios.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "string_func.h"

typedef unsigned char bool;
#define TRUE 1
#define FALSE 0

#define	STDIN 0
#define	STDOUT 1

// temp
#define SPACE_sym '_'

#define SYMBOL_COUNT 7

// 0000001
#define CMD 0
#define ARG 1
// 0000010
#define VAR_ASSIGN 2
// 0000100
#define VAR_USE 4
// 0001000
#define FILE_PATH 8
// 0010000
#define BUNNY_EAR 16
// 0100000
// if that is 0 - double ears
#define SINGLE 32
// 1000000
#define REDIRECT 64
 
typedef struct s_val
{
	char	*keyword;
	char	*define;

	struct s_val *next;
}	t_val;

typedef struct s_token
{
	char	*string;
	int		token_no;
	int		type;

	struct s_token *next;
}	t_token;

typedef struct s_cmd
{
	int		infd;
	int		outfd;

	// will be freed by the time we r done
	t_token *tokens;
	char	**final_cmd_line;

	struct s_cmd *next;
}	t_cmd;

typedef struct s_cmd_info
{
	int	no_cmd;

	struct s_cmd *cmd;

	t_val *global_var;
	t_val *private_var;
}	t_cmd_info;

#define MAX_SIZE -1

char		*append(char *str1, char *str2);
char		*n_append(char *str1, char *str2);

int			eprint(char *element, char *msg);

int			search_element(char *input, char to_search, size_t start, size_t end);

t_val		*init_val();

t_val		*get_envval(char **envp);
void		fill_val(t_val *current, char *keyword, char *define);
bool		new_variable(char *input, t_val *private_val);

t_token		*init_token(int	token_no);
void		replace_variable(char **cmd, t_val *global_var, t_val *private_val);

char		*token_to_string(t_token *current);
t_val		*search_variable(char *keyword, t_val *var);

void		remove_all_token(t_token **stuff);
void		delete_token_node(t_token **current);
void		delete_specific_token(t_token **main, int index);
void		free_darray(char ***paths);

void		prick();
void		signal_handler(int	signo);
void		restore(void);
int			execute(t_cmd_info *cmd_info);

void		delete_all_var(t_val **var);

#endif