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
	int			len;

	if (!content || content[0] == '\0')
		return (0);
	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	if (content[len] == '\n')
		len++;
	line = str_substr(content, 0, len);
	return (line);
}

char	*skip(char *content)
{
	int		i;
	int		j;
	char	*skip;

	if (!content || content[0] == '\0')
		return (0);
	i = 0;
	while (content[i] && content[i] != '\n')
		i++;
	if (content[i] == '\n')
		i++;
	skip = (char *) malloc (str_len(&content[i]) + 1);
	j = 0;
	while (content[i])
		skip[j++] = content[i++];
	skip[j] = 0;
	free(content);
	return (skip);
}

char	*buff_to_content(char *buff, int fd, char *content)
{
	int			check;

	while (1)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (!check)
			break ;
		if (check == -1)
			break ;
		buff[check] = 0;
		content = str_join(content, buff);
		if (has_sep(content))
			break ;
	}
	free(buff);
	return (content) ;
}

char	*get_next_line(int fd)
{
	static char	*content;
	char		*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buff = (char *) malloc (BUFFER_SIZE + 1);
	content = buff_to_content(buff, fd, content);
	if (!content)
		return (0);
	line = lineextractor(content);
	if (!line)
	{
		free(content);
		return (line);
	}
	content = skip(content);
	return (line);
}
