/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:50:39 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 12:50:43 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_split.h"
# include "get_next_line.h"
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex{
	int		infile;
	int		outfile;
	int		cmd_num;
	char	**cmd;
	char	**envp;
	char	**path;
}	t_pipex;

void	fill_in_pipe(int in_file, int out_fd, char *limiter);
void	here_doc(t_pipex *fd_list, char **av, int ac, int p[2]);
void	get_fd(t_pipex *fd_list, char **av, int ac);

int		ft_strfind(char *str1, char *str2);
int		ft_strcmp_nl(char *str1, char *str2);
char	*append(char *str1, char *str2);
char	*n_append(char *str1, char *str2);
int		eprint(char *element, char *msg);
int		execute_command(char **path, char *cmd, char **envp);
void	child(t_pipex pipex, int index, int in);
char	*get_binarypath(char *command, char **paths);

int		free_all(char **item1, char **item2);

#endif