/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:06:57 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 12:54:24 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	calc_z(t_coordinates *n_point, t_coordinates *o_point, int plot_y)
{
	int	z;

	if (n_point && n_point->projected_coord[Y] - o_point->projected_coord[Y])
		z = (((n_point->coord[Z] - o_point->coord[Z])
					* (plot_y - o_point->projected_coord[Y]))
				/ (n_point->projected_coord[Y] - o_point->projected_coord[Y]))
			+ o_point->coord[Z];
	else
		z = o_point->coord[Z];
	return (z);
}

int	putcolor(unsigned char trans, unsigned char r,
		unsigned char g, unsigned char b)
{
	int	ret;

	ret = trans << 24 | r << 16 | g << 8 | b;
	return (ret);
}

// epic interpolation
int	trans_z_calc(t_coordinates *n_point, t_coordinates *o_point, int plot_y)
{
	int	z;

	if (n_point && n_point->projected_coord[Y] - o_point->projected_coord[Y])
		z = (((n_point->trans_coord[Z] - o_point->trans_coord[Z])
					* (plot_y - o_point->projected_coord[Y]))
				/ (n_point->projected_coord[Y] - o_point->projected_coord[Y]))
			+ o_point->trans_coord[Z];
	else
		z = o_point->trans_coord[Z];
	return (z);
}

// funny formula to calculate memory offset
// (y * line_length + x * (bits_per_pixel / 8));
void	placepixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (out_of_bounds(x, y, *data))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_image(t_mlx *mlx, t_coordinates *points)
{
	t_coordinates	*current;
	int				i;

	i = 1;
	current = points;
	set(mlx->z_buff, mlx);
	while (current)
	{
		if (current->beside)
			draw_line_handler(current, current->next, mlx);
		if (current->below)
			draw_line_handler(current, current->below, mlx);
		current = current->next;
	}
}
