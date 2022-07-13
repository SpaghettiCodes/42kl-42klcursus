#include "get_next_line_bonus.h"

char	*str_substr(char *str, int start, int len)
{
	char	*substr;
	int		i;

	i = 0;
	substr = (char *) malloc (len + 1);
	while (i < len)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

int	str_len(char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
	while(str[len])
		len++;
	return (len);
}

char *str_join(char *str1, char *str2)
{
	char	*strjoined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strjoined = (char *) malloc ((str_len(str1) + str_len(str2) + 1) * sizeof(char));
	while (str1 && str1[i])
	{
		strjoined[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		strjoined[i] = str2[j];
		i++;
		j++;
	}
	strjoined[i] = '\0';
	free(str1);
	return (strjoined);
}

void	fd_search_and_destroy(int fd, t_fd_list **list)
{
	t_fd_list	*current;
	t_fd_list	*prev;
	t_fd_list	*temp;

	current = *list;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
			break ;
		prev = current;
		current = current->next;
	}
    if (!current)
        return ;
	temp = current->next;
	if (current->contents)
		free(current->contents);
	free(current);
	current = temp;
	if (prev)
		prev->next = current;
    else
        *list = current;
}

int	has_sep(t_fd_list *list)
{
	int			i;

	i = list->checkuntil;
	while (list->contents[i])
	{
		i++;
		if (list->contents[i] == '\n')
		{
			list->checkuntil = i;
			return (1);
		}
	}
	list->checkuntil = i;
	return (0);
}
