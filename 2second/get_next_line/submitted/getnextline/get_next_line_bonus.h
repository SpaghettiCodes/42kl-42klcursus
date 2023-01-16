/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:29:51 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/14 13:36:25 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_List{
	int				fd;
	int				readuntil;
	int				checkuntil;
	char			*contents;
	struct s_List	*next;
}	t_fd_list;

char		*get_next_line(int fd);

// list utils
t_fd_list	*fd_initialize(int fd);
t_fd_list	*fd_search_and_add(int fd, t_fd_list *list);
int			fd_fill_content(int fd, t_fd_list *list, char *buff);
char		*fd_search_line(t_fd_list *list);
void		fd_search_and_destroy(int fd, t_fd_list **list);

// str utils
char		*str_substr(char *str, int start, int len);
int			str_len(char *str);
char		*str_join(char *str1, char *str2);
int			has_sep(t_fd_list *list);

#endif
