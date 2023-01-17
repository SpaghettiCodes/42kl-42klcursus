#include "fdf.h"

t_coordinates *fill_node(t_coordinates *current, int x, int y, int z)
{
	current->coord[X] = x;
	current->coord[Y] = y;
	current->coord[Z] = z;
}

t_coordinates	*process_line(char **coordinates, int y, t_coordinates *point, int *index)
{
	int				x;
	t_coordinates	*current;

	x = 0;
	current = point;
	if (y)
	{
		current->next = init();
		current = current->next;
	}
	while (coordinates[x])
	{
		fill_node(current, x, y, ft_atoi(coordinates[x]));
		++(*index);
		if (coordinates[x + 1])
		{
			current->next = init();
			current = current->next;
		}
		++x;
	}
	return (current);
}

t_coordinates *get_points(int	read_file_fd)
{
	char	*line;
	char	**coordinates;
	int		x;
	int		y;
	int		index;
	t_coordinates *ret;
	t_coordinates *current;

	ret = init();
	current = ret;
	y = 0;
	index = 0;
	while (1)
	{
		line = get_next_line(read_file_fd);
		if (!line)
			break;
		coordinates = ft_split(line, ' ');
		current = process_line(coordinates, y, current, &index);
		freeall(line, coordinates);
		y++;
	}
	printf("Got all points = %d\n", index);
	return (ret);
}
