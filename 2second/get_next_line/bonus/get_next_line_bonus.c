#include "get_next_line_bonus.h"

t_fd_list *fd_initialize(int fd)
{
	t_fd_list	*list;

	list = (t_fd_list *) malloc (sizeof(t_fd_list));

	list->fd = fd;
	list->next = NULL;
	list->checkuntil = 0;
	list->contents = NULL;
	list->readuntil = 0;
	return (list);
}

t_fd_list	*fd_search_and_add(int fd, t_fd_list *list)
{
	t_fd_list	*current;

	current = list;
	while (1)
	{
		if (current->fd == fd)
			return (current);
		if (!current->next)
			break ;
		current = current->next;
	}
	current->next = fd_initialize(fd);
	return (current->next);
}

int	fd_fill_content(int fd, t_fd_list *list, char *buff)
{
	int		check;

	while (1)
	{
		check = read(fd, buff, BUFFER_SIZE);
		if (!check)
		{
			free(buff);
			return (0);
		}
		if (check == -1)
		{
			free(buff);
			return (-1);
		}
		buff[check] = 0;
		list->contents = str_join(list->contents, buff);
		if (has_sep(list))
		{
			free(buff);
			return (1);
		}
	}
}

char *fd_search_line(t_fd_list *list)
{
	char	*line;
	int		i;
	int		len;

	if (!list->contents || list->contents[list->readuntil] == '\0')
		return (0);
	i = list->readuntil;
	len = 0;
	while (list->contents[i] && list->contents[i] != '\n')
	{
		++len;
		++i;
	}
	if (list->contents[i] == '\n')
	{
		++i;
		++len;
	}
	line = str_substr(list->contents, list->readuntil, len);
	list->readuntil = i;
	return (line);
}

char *get_next_line(int fd)
{
	static t_fd_list	*list;
	t_fd_list			*current;
	char				*buff;
	char				*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	if (!list)
	{
		list = fd_initialize(fd);
		current = list;
	}
	else
		current = fd_search_and_add(fd, list);
	buff = (char *) malloc (BUFFER_SIZE + 1);
	if (fd_fill_content(fd, current, buff) == -1)
	{
		fd_search_and_destroy(fd, &list);
		return (0);
	}
	line = fd_search_line(current);
	if (!line)
		fd_search_and_destroy(fd, &list);
	return (line);
}
