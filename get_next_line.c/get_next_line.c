#include "get_next_line.h"

int	has_sep(char *content)
{
	int	i;

	i = -1;
	while (content[++i])
		if (content[i] == '\n')
			return (1);

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

char *get_next_line(int fd)
{
	static char		*content;
	char			*buff;
	char			*line;
	int				check;

	if (!fd || BUFF_SIZE <= 0)
		return (0);
	buff = (char *) malloc (BUFF_SIZE + 1);
	while (1)
	{
		check = read(fd, buff, BUFF_SIZE);
		if (!check)
			break ;
		if (check == -1)
			break ;
		buff[check] = 0;
		content = str_join(content, buff);
		if (has_sep(content))
			break ;
	}
	line = lineextractor(content);
	return (line);
}
