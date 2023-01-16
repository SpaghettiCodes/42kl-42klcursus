#include "checker.h"

void	freedoublechar(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	errorexit(t_pushswap *stacks, char **to_free, int *to_free2)
{
	if (stacks)
		freeall(stacks);
	if (to_free)
		freedoublechar(to_free);
	if (to_free2)
		free(to_free2);
	write(2, "Error\n", 7);
	exit(69);
	return(420);
}