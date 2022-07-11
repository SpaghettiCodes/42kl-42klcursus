/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:47:21 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/11 18:47:13 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	has_sep(char *content)
{
	int			i;
	static int	lastsaw;

	i = lastsaw;
	while (content[i])
	{
		i++;
		if (content[i] == '\n')
		{
			lastsaw = i;
			return (1);
		}
	}
	lastsaw = i;
	return (0);
}

char	*lineextractor(char *content)
{
	char		*line;
	static int	lastsaw;
	int			i;
	int			len;

	if (!content || content[lastsaw] == '\0')
		return (0);
	i = lastsaw;
	len = 0;
	while (content[i] && content[i] != '\n')
	{
		i++;
		len++;
	}
	if (content[i] == '\n')
	{
		i++;
		len++;
	}
	line = str_substr(content, lastsaw, len);
	lastsaw = i;
	return (line);
}

char	*buff_to_content(char *buff, int fd)
{
	int			check;
	static char	*content;

	while (1)
	{
		check = read(fd, buff, BUFF_SIZE);
		if (!check)
			break ;
		if (check == -1)
		{
			free(buff);
			return (0);
		}
		buff[check] = 0;
		content = str_join(content, buff);
		if (has_sep(content))
			break ;
	}
	free(buff);
	return (content);
}

char	*get_next_line(int fd)
{
	char	*content;
	char	*buff;
	char	*line;

	if (BUFF_SIZE <= 0)
		return (0);
	buff = (char *) malloc (BUFF_SIZE + 1);
	content = buff_to_content(buff, fd);
	if (!content)
		return (0);
	line = lineextractor(content);
	if (!line)
		free(content);
	return (line);
}