// that b german dude algo
// i will understand whats happening here


// eventually

void	draw_low_line(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int dx = n_point->x - o_point->x;
	int	dy = n_point->y - o_point->y;
	int	yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int	D = (2 * dy) - dx;
	int	y = o_point->y;
	int x = o_point->x;
	int height_val;
	while (x <= n_point->x)
	{
		height_val = (((n_point->z - o_point->z) * (x - o_point->x)) / (n_point->x - o_point->x)) + o_point->z;
		placepixel(&mlx->image, x, y, set_color(height_val, MULITIPLIER));
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
		x++;
	}
}

void	draw_high_line(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int dx = n_point->x - o_point->x;
	int	dy = n_point->y - o_point->y;
	int	xi = 1;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int	D = (2 * dy) - dx;
	int	y = o_point->y;
	int x = o_point->x;
	int	height_val;
	while (y <= n_point->y)
	{
		height_val = (((n_point->z - o_point->z) * (x - o_point->x)) / (n_point->x - o_point->x)) + o_point->z;
		placepixel(&mlx->image, x, y, set_color(height_val, MULITIPLIER));
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + 2 * dx;
		y++;
	}
}

void	draw_vertical(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int	x;
	int	y;
	int height_val;

	x = o_point->x;
	y = o_point->y;
	while (y < n_point->y)
	{
		height_val = (((n_point->z - o_point->z) * (y - o_point->y)) / (n_point->y - o_point->y)) + o_point->z;
		placepixel(&mlx->image, x, y, set_color(height_val, MULITIPLIER));
		y++;
	}
}

void	draw_line_handler(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int dy = n_point->y - o_point->y; 
	int	dx = n_point->x - o_point->x;
	
	if (dx == 0)
	{
		draw_vertical(o_point, n_point, mlx);
		return;
	}
	if (dy < 0)
		dy = -dy;
	if (dx < 0)
		dx = -dx;
	if (dy < dx)
	{
		if (o_point->x > n_point->x)
			draw_low_line(n_point, o_point, mlx);
		else
			draw_low_line(o_point, n_point, mlx);
	}
	else
	{
		if (o_point->y > n_point->y)
			draw_high_line(n_point, o_point, mlx);
		else
			draw_high_line(o_point, n_point, mlx);
	}
}

void	apply_transformation(t_coordinates *points, int offset)
{
	t_coordinates *current;

	current = points;
	while (current)
	{
		current->x = transformation_x(current->x, offset, X_LINE_LENGTH);
		current->y = transformation_y(current->y, offset, Y_LINE_LENGTH);
		current = current->next;
	}
}