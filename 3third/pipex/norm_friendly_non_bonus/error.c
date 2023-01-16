#include "pipex.h"

int	eprint(char *element, char *msg)
{
	write(2, "./pipex: ", 10);
	if (element)
		write(2, element, ft_strlen(element));
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return(11 + ft_strlen(element) + ft_strlen(msg));
}

char	free_all(char *item, char **items)
{
	int	i;

	if (item)
		free(item);
	if (items)
	{
		i = 0;
		while (items[i])
		{
			free(items[i]);
			i++;
		}
		free(items);
	}
}