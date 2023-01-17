/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:47:19 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 13:20:50 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char		*get_next_line(int fd, int error);

char		*str_substr(char *str, int start, int len);
int			str_len(char *str);
char		*str_join(char *str1, char *str2);

int			has_sep(char *content);
char		*lineextractor(char *content);
char		*buff_to_content(char *buff, int fd, char *content);
char		*skip(char *content);

#endif
