/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpoint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:14:17 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:14:50 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_node(t_coordinates *current, int x, int y, int z)
{
	current->coord[X] = x;
	current->coord[Y] = y;
	current->coord[Z] = z;
}

t_coordinates	*process_line(char *line, int y,
	t_coordinates *point, int *total)
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

void	write_num(unsigned int n)
{
	if (n >= 10)
		write_num(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

t_coordinates	*get_points(int read_file_fd)
{
	char			*line;
	int				y;
	unsigned int	total;
	t_coordinates	*ret;
	t_coordinates	*current;

	ret = init();
	current = ret;
	y = 0;
	total = 0;
	while (1)
	{
		line = get_next_line(read_file_fd);
		if (!line)
			break ;
		current = process_line(line, y, current, &total);
		freeall(line, NULL);
		y++;
	}
	write(1, "Got all points = ", 17);
	write_num(total);
	write(1, "\n", 1);
	return (ret);
}
