#include "fdf.h"

void	freeall(char *line, char **coordinates)
{
	int	i;

	if (line)
		free(line);
	i = 0;
	if (coordinates)
	{
		while (coordinates[i])
		{
			free(coordinates[i]);
			i++;
		}
		free(coordinates);
	}
}
