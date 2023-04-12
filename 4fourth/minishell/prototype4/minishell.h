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
#define EXE_NAME "/test"

#define SYMBOL_COUNT 8

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
	// MAY OR MAY NOT BE FRREABLE, SEE ALLOCED
	char	*theline;

	// rest is fine
	bool	alloced:1;
	int		equalloc;

	struct s_val *next;
}	t_val;

typedef struct s_token
{
	// freeable
	char	*string;

	// rest is fine
	int		token_no;
	int		type;

	struct s_token *next;
}	t_token;

typedef struct s_cmd
{
	// damn im lazy to do pipes :((((
	int		infd;
	int		outfd;

	// will be freed by the time we r done
	t_token *tokens;
	// this gotta free
	char	**final_cmd_line;

	bool	redir:1;
	struct s_cmd *next;
}	t_cmd;

typedef struct s_cmd_info
{
	int				no_cmd;

	// ofc this is freeable
	struct s_cmd	*cmd;

	// DO NOT FREE THIS 2
	t_val			*global_var;
	t_val			*private_var;
	// amogus
	int				last_exit;
}	t_cmd_info;

#define MAX_SIZE -1

int			ft_atoi(const char *str);
char		*ft_itoa(int n);

char		*append(char *str1, char *str2);
char		*n_append(char *str1, char *str2);

int			eprint(char *element, char *msg);

int			search_character(char *input, char to_search, size_t start, size_t end);

t_val		*init_val();

t_val		*get_envval(char **envp);

void		fill_val(t_val *current, bool is_alloc, char *string, int equalloc);

bool		new_variable(char *input, t_val *local_var, t_val *global_var, bool alloc);

t_token		*init_token(int	token_no);
void		replace_variable(char **cmd, t_cmd_info *minishell);

char		*token_to_string(t_token *current);
t_val		*search_variable(char *keyword, t_val *var);

void		symbol_b_gone();
void		new_line();
void		restore(void);
int			execute(t_cmd_info *cmd_info);

int			ft_strncmp(char *haystack, char *needle, int word_len);
int			ft_strcmp(char *str1, char *str2);
void		free_current_val(t_val *current);

char		**variable_to_darray(t_val *in);

// be free my child
void		remove_all_token(t_token **stuff);
void		delete_token_node(t_token **current);
void		delete_all_var(t_val **var);
void		free_darray(char **paths);
void		free_cmd(t_cmd **cmd);
void		free_cmd_info(t_cmd_info *info);

void		shell_signal();

t_val		*add_back_variable(t_val *local_var);

unsigned int	count_arg(char **arg);

int			export(char	**arg, t_cmd_info *shell_info);
int			change_dir(char	**arg, t_cmd_info *shell_info);
int			echo(char **arg, t_cmd_info *shell_info);
int			pwd(t_cmd_info *cmd_main);
int			clean_exit(t_cmd_info *to_free_2);
#endif