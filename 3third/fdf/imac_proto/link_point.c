#include "fdf.h"

// n = next to, b = below
t_coordinates	*find_adjacent(t_coordinates *points, int x, int y, char option)
{
	t_coordinates *current;
	t_coordinates *next;

	current = points;
	next = points->next;
	if (option == 'n')
	{	
		if (next && next->coord[X] == x)
			return (next);
		else
			return (NULL);
	}
	else if (option == 'b')
	{
		while (current)
		{
			if (current->coord[X] == x && current->coord[Y] == y)
				break;
			current = current->next;
		}
	}
	return (current);
}

void	link_below(t_coordinates *points)
{
	t_coordinates *current;
	t_coordinates *finder;

	current = points;
	int	i = 0;
	while (current)
	{
		finder = find_adjacent(current, current->coord[X], (current->coord[Y] + 1), 'b');
		current->below = finder;
		finder = find_adjacent(current, (current->coord[X] + 1), current->coord[Y], 'n');
		current->beside = finder;
		current = current->next;
		i++;
	}
}