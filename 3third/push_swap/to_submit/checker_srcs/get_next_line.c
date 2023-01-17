/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:47:21 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 17:26:31 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	has_sep(char *content)
{
	int			i;

	i = 0;
	while (content[i])
	{
		i++;
		if (content[i] == '\n')
			return (1);
	}
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
	return (content);
}

char	*get_next_line(int fd, int error)
{
	static char	*content[1024];
	char		*buff;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (0);
	if (error)
	{
		if (content[fd])
			free (content[fd]);
		content[fd] = NULL;
		return (NULL);
	}
	buff = (char *) malloc (BUFFER_SIZE + 1);
	content[fd] = buff_to_content(buff, fd, content[fd]);
	if (!content[fd])
		return (0);
	line = lineextractor(content[fd]);
	if (!line)
	{
		free (content[fd]);
		return (line);
	}
	content[fd] = skip(content[fd]);
	return (line);
}
