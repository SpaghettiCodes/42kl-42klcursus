/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bershenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:08:26 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 12:22:47 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_low_line(t_coordinates *o_point,
		t_coordinates *n_point, t_mlx *mlx)
{
	t_lineutils	line;

	if (out_of_bounds2(o_point, mlx->image)
		&& out_of_bounds2(n_point, mlx->image))
		return ;
	set_lineutils(&line, n_point, o_point);
	if (line.dy < 0)
	{
		line.yi = -1;
		line.dy = -line.dy;
	}
	while (out_of_bounds(line.x, line.y, mlx->image)
		&& line.x <= n_point->projected_coord[X])
		next_ll(&line);
	while (!out_of_bounds(line.x, line.y, mlx->image)
		&& line.x <= n_point->projected_coord[X])
	{
		if (check_z_buff(&mlx->image, line.x, line.y,
				trans_z_calc(n_point, o_point, line.y)))
			placepixel(&mlx->image, line.x, line.y,
				set_color(line.y, o_point, n_point, mlx->attributes));
		next_ll(&line);
	}
}

void	draw_high_line(t_coordinates *o_point,
		t_coordinates *n_point, t_mlx *mlx)
{
	t_lineutils	line;

	if (out_of_bounds2(o_point, mlx->image)
		&& out_of_bounds2(n_point, mlx->image))
		return ;
	set_lineutils(&line, n_point, o_point);
	if (line.dx < 0)
	{
		line.xi = -1;
		line.dx = -line.dx;
	}
	while (out_of_bounds(line.x, line.y, mlx->image)
		&& line.y <= n_point->projected_coord[X])
		next_hl(&line);
	while (!out_of_bounds(line.x, line.y, mlx->image)
		&& line.y <= n_point->projected_coord[Y])
	{
		if (check_z_buff(&mlx->image, line.x, line.y,
				trans_z_calc(n_point, o_point, line.y)))
			placepixel(&mlx->image, line.x, line.y,
				set_color(line.y, o_point, n_point, mlx->attributes));
		next_hl(&line);
	}
}

void	slope_handler(t_coordinates *o_point,
	t_coordinates *n_point, t_mlx *mlx)
{
	int	dy;
	int	dx;

	dy = n_point->projected_coord[Y] - o_point->projected_coord[Y];
	dx = n_point->projected_coord[X] - o_point->projected_coord[X];
	if (dy < 0)
		dy = -dy;
	if (dx < 0)
		dx = -dx;
	if (dy < dx)
	{
		if (o_point->projected_coord[X] > n_point->projected_coord[X])
			draw_low_line(n_point, o_point, mlx);
		else
			draw_low_line(o_point, n_point, mlx);
	}
	else
	{
		if (o_point->projected_coord[Y] > n_point->projected_coord[Y])
			draw_high_line(n_point, o_point, mlx);
		else
			draw_high_line(o_point, n_point, mlx);
	}
}

void	draw_line_handler(t_coordinates *o_point,
	t_coordinates *n_point, t_mlx *mlx)
{
	if (!(n_point->projected_coord[X] - o_point->projected_coord[X]))
		vertical_line_handler(o_point, n_point, mlx);
	else
		slope_handler(o_point, n_point, mlx);
}
