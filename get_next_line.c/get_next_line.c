#include "get_next_line.h"

fd_list *fd_initialize(int fd)
{
	fd_list	*list;

	list = (fd_list *) malloc (sizeof(fd_list));

	list->fd = fd;
	list->next = NULL;
	list->contents = NULL;
	list->readuntil = 0;
	return (list);
}

fd_list	*fd_search_and_add(int fd, fd_list *list)
{
	fd_list	*current;

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

int	fd_fill_content(int fd, fd_list *list, char *buff)
{
	int		check;

	while (1)
	{
		check = read(fd, buff, BUFF_SIZE);
		if (!check || check == -1)
			return (0);
		buff[check] = 0;
		list->contents = str_join(list->contents, buff);
	}
	free(buff);
}

char *fd_search_line(fd_list *list)
{
	char	*line;
	int		i;

	if (list->contents[list->readuntil] == '\0')
		return (0);
	i = list->readuntil;
	while (list->contents[i] && list->contents[i] != '\n')
		i++;
	line = str_substr(list->contents, list->readuntil, ((i - list->readuntil) + 1));
	list->readuntil = ++i;
	return (line);
}

char *get_next_line(int fd)
{
	static fd_list	*list;
	fd_list			*current;
	char			*buff;
	char			*line;

	if (!fd || !BUFF_SIZE)
		return (0);
	if (!list)
	{
		list = fd_initialize(fd);
		current = list;
	}
	else
		current = fd_search_and_add(fd, list);
	buff = (char *) malloc (BUFF_SIZE + 1);
	fd_fill_content(fd, current, buff);
	line = fd_search_line(current);
	return (line);
}
