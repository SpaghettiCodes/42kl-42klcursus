#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "string_func.h"

typedef unsigned char bool;
# define	TRUE 1
# define	FALSE 0

# define	STDIN 0
# define	STDOUT 1

// temp
# define SPACE_sym '_'
# define EXE_NAME "/test"

# define SYMBOL_COUNT 9

// 0000001
# define CMD 0
# define ARG 1
// 0000010
# define VAR_ASSIGN 2
// 0000100
# define VAR_USE 4
// 0001000
# define FILE_PATH 8
// 0010000
# define BUNNY_EAR 16
// 0100000
// if that is 0 - double ears
# define SINGLE 32
// 1000000
# define REDIRECT 64
 
# define ENV 1
# define SELF 0
typedef struct s_val
{
	// MAY OR MAY NOT BE FRREABLE, SEE ALLOCED
	char	*theline;

	// rest is fine
	bool	type:1;
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

// woohooo another day another structure
typedef struct s_redir
{
	int				no;
	int				type;
	char			*file_name;

	struct s_redir	*next;
}	t_redir;

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
	t_redir	*redir_info;

	struct s_cmd *next;
}	t_cmd;

typedef struct s_cmd_info
{
	int				no_cmd;

	// ofc this is freeable
	struct s_cmd	*cmd;

	// DO NOT FREE THIS 2
	t_val			*global_var;
	// amogus
	int				last_exit;
}	t_cmd_info;

# define IN_DEF 1
# define OUT_DEF 2
# define HEREDOC 3
# define OUT_APP 4

# define MAX_SIZE -1

int			eprint(char *element, char *msg);

int			search_character(char *input, char to_search, size_t start, size_t end);

t_val		*init_val();

t_val		*get_envval(char **envp);

t_val		*add_back_variable(t_val **variables);
void		fill_val(t_val *current, bool is_alloc, char *string, int equalloc);
void		replace_val(t_val *current, char *string, int equalloc);

bool		new_variable(char *input, t_val **global_var, bool alloc);

t_token		*init_token(int	token_no);
void		replace_variable(char **cmd, t_cmd_info *minishell);

char		*token_to_string(t_token *current);
t_val		*search_variable(char *keyword, t_val *var);

void		symbol_b_gone();
void		new_line();
int			execute(t_cmd_info *cmd_info);
int			partoftoken(char x);

char		**variable_to_darray(t_val *in);

// be free my child
void		remove_all_token(t_token **stuff);
void		delete_token_node(t_token **current);
void		delete_all_var(t_val **var);
void		free_darray(char **paths);
void		free_cmd(t_cmd **cmd);
void		free_cmd_info(t_cmd_info *info);
void		free_val_content(t_val *current);

// void		shell_signal();

// builtins
int			export(char	**arg, t_cmd_info *shell_info);
int			change_dir(char	**arg, t_cmd_info *shell_info);
int			echo(char **arg, t_cmd_info *shell_info);
int			pwd(t_cmd_info *cmd_main);
int			clean_exit(t_cmd_info *to_free_2);
int			list_env(t_val *variables);
int			unset_variables(char **arg, t_val **var);

// utils
unsigned int	count_arg(char **arg);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*append(char *str1, char *str2);
char			*n_append(char *str1, char *str2);
int				ft_strncmp(char *haystack, char *needle, int word_len);
int				ft_strcmp(char *str1, char *str2);

#endif