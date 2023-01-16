#include "pipex.h"

void	free_double_arr(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

int	free_all(char **item1, char **item2)
{
	if (item1)
		free_double_arr(item1);
	if (item2)
		free_double_arr(item2);
	return (6);
}
