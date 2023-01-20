/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:47:15 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/21 00:33:07 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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

typedef struct s_pipex{
	int		infile;
	int		outfile;
	int		cmd_num;
	char	**cmd;
	char	**envp;
	char	**path;
	char	**binary_paths;
}	t_pipex;

void	fill_in_pipe(int in_file, int out_fd, char *limiter);
void	here_doc(t_pipex *fd_list, char **av, int ac, int p[2]);
void	get_fd(t_pipex *fd_list, char **av, int ac);

int		ft_strfind(char *str1, char *str2);
int		ft_strcmp_nl(char *str1, char *str2);
char	*append(char *str1, char *str2);
char	*n_append(char *str1, char *str2);
int		eprint(char *element, char *msg);
void	child(t_pipex pipex, int index, int in);
void	parse_path(t_pipex *data);

void	free_double_arr(char **to_free);

#endif