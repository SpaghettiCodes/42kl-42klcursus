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

/* 
** pipes = 0 - read, 1 - write
*/

typedef	struct s_pipex{
	int		infile;
	int		outfile; 
	int		*pipe_read;
	int		*pipe_write;
	int		debug_1;
	int		debug_2;
	char	*limiter;
	int		total;
} t_pipex;

// child stuff
// close every other fd to prevent errors
void	close_every_other_fd(t_pipex *pipex, int skip);

// stuff needs to be done if is a child
void	child(t_pipex pipex, char *command, char **envp, int index);

// bonus
// fill in the 1st pipe with content from STDIN
void	fill_in_pipe(int in_file, int out_fd, char *limiter);

// make multiple pipes (max 502 FIX THIS)
void	make_pipes(t_pipex *fd_list, int count);

// here_doc bonus
void	here_doc(t_pipex *fd_list, char **av, int ac);

// normal
int		get_fd(t_pipex *fd_list, char **av, int ac);

// utils
// your average string compare
int	ft_strcmp(char *str1, char *str2);

// your average string compare but str2 ends at '\n' instead
int	ft_strcmp_nl(char *str1, char *str2);

// determine all valid paths to run the command for execve
// append str2 at the back of str1, frees str1
char	*append(char *str1, char *str2);

// finds str2 in str1, returns pointer to the first location str2 was found
int		find_in_string(char *str1, char *str2);

// get all valid paths for the binary source file (extracting the PATH: from envp)
char	*get_paths(char **envp);

// gets and test all paths to find the correct files (using access());
char	*get_binarypath(char **envp, char *command, t_pipex fl_desc);

#endif