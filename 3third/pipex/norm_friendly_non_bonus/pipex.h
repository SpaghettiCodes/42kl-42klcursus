#ifndef PIPEX_H
# define PIPEX_H

# include "ft_split.h"
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>

typedef	struct s_pipex{
	int	infile;
	int	outfile; 
	int	pipefd[2]; // 0 - read, 1 - write
}	t_pipex;

// child
void	childone(t_pipex fl_desc, char **av, char **envp, char **paths);
void	childtwo(t_pipex fl_desc, char **av, char **envp, char **paths);

// get envp variable $PATH
char	*get_paths(char **envp);

// finds binary path for command
char	*get_binarypath(char *command, char **paths);

// error handling
int		eprint(char *element, char *msg);
char	free_all(char *item, char **items);

// utils
char	*append(char *str1, char *str2);
// like append but DOES NOT free str1
char	*n_append(char *str1, char *str2);
int		ft_strcmp(char *str1, char *str2);

#endif