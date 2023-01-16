#ifndef PIPEX_H
#define PIPEX_H

# include "ft_split.h"
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include "get_next_line.h"
# include <sys/types.h> 
# include <sys/wait.h> 

typedef	struct s_pipex{
	int		infile;
	int		outfile;
	int		cmd_num;
	char	**cmd;
	char	**envp; 
	// freeables
	char	**path;
} t_pipex;

void	fill_in_pipe(int in_file, int out_fd, char *limiter);
void	here_doc(t_pipex *fd_list, char **av, int ac, int p[2]);
void	get_fd(t_pipex *fd_list, char **av, int ac);

// compares str1 and str2
int	ft_strcmp(char *str1, char *str2);
// compares str1 and str2, stops comparing str1 at newline
int	ft_strcmp_nl(char *str1, char *str2);
// appends str2 at the back of str1 -- frees str1 and null terminate the appeneded string
char	*append(char *str1, char *str2);
// similar with append BUT does not free str1 and returns a malloced string
char	*n_append(char *str1, char *str2);

// error printing, prints out error msg
int		eprint(char *element, char *msg);
/* 
** test all the command given if they are executable
** also add any valid path into the binary_paths array
*/
int	test_cmd(t_pipex *pipex, char **paths);

/* 
** executes the command 
** exits automatically if success, returns 0 if an error occured
*/
int		execute_command(char **path, char *cmd, char **envp);
/* 
** child process -- child process will create more child process to run all commands
** in = the STDIN of the child process
** child process will create the next pipe required for the next child process 
*/
void	child(t_pipex pipex, int index, int in);

// gets the executable binary file path and returns a malloced string of said pathway
char	*get_binarypath(char *command, char **paths);

int	free_all(char **item1, char **item2);

#endif