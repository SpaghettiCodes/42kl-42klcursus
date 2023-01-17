#include "fdf.h"

t_coordinates *fill_node(t_coordinates *current, int x, int y, int z)
{
	current->coord[X] = x;
	current->coord[Y] = y;
	current->coord[Z] = z;
}

t_coordinates	*process_line(char *line, int y, t_coordinates *point, int *total)
{
	int				x;
	char			**coordinates;
	t_coordinates	*current;

	x = 0;
	current = point;
	coordinates = ft_split(line, ' ');
	if (y)
	{
		current->next = init();
		current = current->next;
	}
	while (coordinates[x])
	{
		fill_node(current, x, y, ft_atoi(coordinates[x]));
		++(*total);
		if (coordinates[x + 1])
		{
			current->next = init();
			current = current->next;
		}
		++x;
	}
	freeall(NULL, coordinates);
	return (current);
}

t_coordinates *get_points(int read_file_fd)
{
	char	*line;
	int		y;
	int		total;
	t_coordinates *ret;
	t_coordinates *current;

	ret = init();
	current = ret;
	y = 0;
	total = 0;
	while (1)
	{
		line = get_next_line(read_file_fd);
		if (!line)
			break;
		current = process_line(line, y, current, &total);
		freeall(line, NULL);
		y++;
	}
	printf("Got all points = %d\n", total);
	return (ret);
}
