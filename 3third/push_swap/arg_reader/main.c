#include "ft_split.h"
#include <stdio.h>

int	ft_atoi(const char *str);

typedef struct windows
{
	int	*tab;
	int tabsize;
} windows;

int		count_elem(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		++i;
	return (i);
}

void	realloc_tab(windows *stuff, int new_size, char **new_stuff)
{
	int	*new;
	int i;
	int	j;

	i = 0;
	new = malloc (sizeof(int) * new_size);
	if (stuff->tab)
	{
		while (i < stuff->tabsize)
		{
			new[i] = stuff->tab[i];
			++i;
		}
	}
	j = 0;
	while (new_stuff[j])
	{
		new[i] = ft_atoi(new_stuff[j]);
		++i;
		++j;
	}
	if (stuff->tab)
		free(stuff->tab);
	stuff->tab = new;
	stuff->tabsize = new_size;
}

void	freeall(char **temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		++i;
	}
	free(temp);
}

void	cry(windows *stuff, int ac, char **av)
{
	char **temp;
	int	i;

	i = 1;

	while (i < ac)
	{
		temp = ft_split(av[i], ' ');
		realloc_tab(stuff, (count_elem(temp) + stuff->tabsize), temp);
		freeall(temp);
		++i;
	}
}

int main(int ac, char **av)
{
	windows *stuff;

	if (ac < 2)
		return (6);

	stuff = malloc(sizeof(windows));
	stuff->tab = NULL;
	stuff->tabsize = 0;

	cry(stuff, ac, av);

	for (int i = 0; i < stuff->tabsize; i++)
		printf("%d ", stuff->tab[i]);
	printf("\n");

	free(stuff->tab);
	free(stuff);
	return (0);
}