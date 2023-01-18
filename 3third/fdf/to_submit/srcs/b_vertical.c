/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_vertical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:11:32 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 12:23:57 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// draws vertical line
void	draw_vertical(t_coordinates *o_point,
	t_coordinates *n_point, t_mlx *mlx)
{
	int	x;
	int	y;

	if (out_of_bounds2(o_point, mlx->image)
		&& out_of_bounds2(n_point, mlx->image))
		return ;
	x = o_point->projected_coord[X];
	y = o_point->projected_coord[Y];
	while (out_of_bounds(x, y, mlx->image) && y < n_point->projected_coord[Y])
		y++;
	while (!out_of_bounds(x, y, mlx->image) && y < n_point->projected_coord[Y])
	{
		if (check_z_buff(&mlx->image, x, y,
				trans_z_calc(n_point, o_point, y)))
			placepixel(&mlx->image, x, y,
				set_color(y, o_point, n_point, mlx->attributes));
		y++;
	}
}

// swap o and n point if n is higher than o
void	vertical_line_handler(t_coordinates *o_point,
	t_coordinates *n_point, t_mlx *mlx)
{
	if (n_point->projected_coord[Y] > o_point->projected_coord[Y])
		draw_vertical(o_point, n_point, mlx);
	else
		draw_vertical(n_point, o_point, mlx);
}
