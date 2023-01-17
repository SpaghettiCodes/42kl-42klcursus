#include "fdf.h"

int		calc_z(t_coordinates *n_point, t_coordinates *o_point, int plot_y)
{
	int	z;

	if (n_point && n_point->projected_coord[Y] - o_point->projected_coord[Y])
		z = (((n_point->coord[Z] - o_point->coord[Z]) * (plot_y - o_point->projected_coord[Y])) / 
				(n_point->projected_coord[Y] - o_point->projected_coord[Y])) + o_point->coord[Z];
	else
		z = o_point->coord[Z];
	return (z);
}

int		set_color(int plot_y, t_coordinates *o_point, t_coordinates *n_point, t_attri attr)
{
	float z;

	z = calc_z(n_point, o_point, plot_y);
	z *= attr.color_intens;
	if (z > 0)
		return (det_color_p(z, attr));
	else
		return (det_color_n(z, attr));
}

// epic interpolation
int	trans_z_calc(t_coordinates *n_point, t_coordinates *o_point, int plot_y)
{
	int	z;

	if (n_point && n_point->projected_coord[Y] - o_point->projected_coord[Y])
		z =(((n_point->trans_coord[Z] - o_point->trans_coord[Z]) * (plot_y - o_point->projected_coord[Y])) 
				/ (n_point->projected_coord[Y] - o_point->projected_coord[Y])) + o_point->trans_coord[Z];
	else
		z = o_point->trans_coord[Z];
	return (z);
}

// funny formula to calculate memory offset = (y * line_length + x * (bits_per_pixel / 8));
void	placepixel(t_data *data, int x, int y, int z, int color)
{
	char	*dst;

	if (out_of_bounds(x, y, *data))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (data->z_buff[x][y] < z)
		data->z_buff[x][y] = z;
	else
		return ;
	*(unsigned int*)dst = color;
}

int	putcolor(unsigned char trans, unsigned char r, unsigned char g, unsigned char b)
{
	int	ret;

	ret = trans << 24 | r << 16 | g << 8 | b;
	return (ret);
}

void	next_ll(t_lineutils *line)
{
	if (line->D > 0)
	{
		line->y += line->yi;
		line->D = line->D + (2 * (line->dy - line->dx));
	}
	else
		line->D = line->D + 2 * line->dy;
	line->x++;
}

void	next_hl(t_lineutils *line)
{
	if (line->D > 0)
	{
		line->x += line->xi;
		line->D = line->D + (2 * (line->dx - line->dy));
	}
	else
		line->D = line->D + 2 * line->dx;
	line->y++;
}

void	draw_low_line(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	t_lineutils line;

	if (out_of_bounds2(o_point, mlx->image) && out_of_bounds2(n_point, mlx->image))
		return ;
	line.dx = n_point->projected_coord[X] - o_point->projected_coord[X];
	line.dy = n_point->projected_coord[Y] - o_point->projected_coord[Y];
	line.yi = 1;

	if (line.dy < 0)
	{
		line.yi = -1;
		line.dy = -line.dy;
	}
	line.D = (2 * line.dy) - line.dx;
	line.x = o_point->projected_coord[X];
	line.y = o_point->projected_coord[Y];
	while (out_of_bounds(line.x, line.y, mlx->image) && line.x <= n_point->projected_coord[X])
		next_ll(&line);
	while (!out_of_bounds(line.x, line.y, mlx->image) && line.x <= n_point->projected_coord[X])
	{
		placepixel(&mlx->image, line.x, line.y, trans_z_calc(n_point, o_point, line.y), set_color(line.y, o_point, n_point, mlx->attributes));
		next_ll(&line);
	}
}

void	draw_high_line(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	t_lineutils line;

	if (out_of_bounds2(o_point, mlx->image) && out_of_bounds2(n_point, mlx->image))
		return ;
	line.dx = n_point->projected_coord[X] - o_point->projected_coord[X];
	line.dy = n_point->projected_coord[Y] - o_point->projected_coord[Y];
	line.xi = 1;

	if (line.dx < 0)
	{
		line.xi = -1;
		line.dx = -line.dx;
	}
	line.D = (2 * line.dy) - line.dx;
	line.x = o_point->projected_coord[X];
	line.y = o_point->projected_coord[Y];
	while (out_of_bounds(line.x, line.y, mlx->image) && line.y <= n_point->projected_coord[X])
		next_hl(&line);
	while (!out_of_bounds(line.x, line.y, mlx->image) && line.y <= n_point->projected_coord[Y])
	{
		placepixel(&mlx->image, line.x, line.y, trans_z_calc(n_point, o_point, line.y), set_color(line.y, o_point, n_point, mlx->attributes));
		next_hl(&line);
	}
}

void	draw_vertical(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int	x;
	int	y;

	if (out_of_bounds2(o_point, mlx->image) && out_of_bounds2(n_point,  mlx->image))
		return ;
	x = o_point->projected_coord[X];
	y = o_point->projected_coord[Y];
	while (out_of_bounds(x, y, mlx->image) && y < n_point->projected_coord[Y])
		y++;
	while (!out_of_bounds(x, y, mlx->image) && y < n_point->projected_coord[Y])
	{
		placepixel(&mlx->image, x, y, trans_z_calc(n_point, o_point, y), set_color(y, o_point, n_point, mlx->attributes));
		y++;
	}
}

void	draw_line_handler(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int	dy = n_point->projected_coord[Y] - o_point->projected_coord[Y];
	int	dx = n_point->projected_coord[X] - o_point->projected_coord[X];

	if (dx == 0)
	{
		if (n_point->projected_coord[Y] > o_point->projected_coord[Y])
			draw_vertical(o_point, n_point, mlx);
		else
			draw_vertical(n_point, o_point, mlx);
		return;
	}
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

void	fill_image(t_mlx *mlx, t_coordinates *points)
{
	t_coordinates	*current;
	int	i;

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
