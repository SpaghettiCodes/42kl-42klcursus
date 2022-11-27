#include "test.h"

void	placepixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	// funny formula to calculate memory offset = (y * line_length + x * (bits_per_pixel / 8));
	if (x < 0 || x >= data->length)
		return;
	if (y < 0 || y >= data->width)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	putcolor(unsigned char trans, unsigned char r, unsigned char g, unsigned char b)
{
	int	ret;

	ret = trans << 24 | r << 16 | g << 8 | b;
	return (ret);
}

t_coordinates *init()
{
	t_coordinates *ret;

	ret = (t_coordinates *) malloc ( sizeof( t_coordinates ) );

	ret->next = NULL;
	ret->debug_link = NULL;
	ret->debug_link2 = NULL; 
	ret->below = NULL;
	return (ret);
}

t_coordinates *fill_node(t_coordinates *current, int x, int y, int z)
{
	current->x = x;
	current->y = y;
	current->z = z;
}

void	freeall(char *line, char **coordinates)
{
	int	i;

	if (line)
		free(line);
	i = 0;
	while (coordinates[i])
	{
		free(coordinates[i]);
		i++;
	}
	if (coordinates)
		free(coordinates);
}

t_coordinates *get_points(int	read_file_fd)
{
	char	*line;
	char	**coordinates;
	int		x;
	int		y;
	t_coordinates *ret;
	t_coordinates *current;

	ret = init();
	current = ret;
	y = 0;
	while (1)
	{
		line = get_next_line(read_file_fd);
		if (!line)
			break;
		coordinates = ft_split(line, ' ');
		x = 0;
		if (y)
		{
			current->next = init();
			current = current->next;
		}
		while (coordinates[x])
		{
			fill_node(current, x, y, ft_atoi(coordinates[x]));
			if (coordinates[x + 1])
			{
				current->next = init();
				current = current->next;
			}
			x++;
		}
		freeall(line, coordinates);
		y++;
	}
	return (ret);
}

// offset = translation
// line_len = zoom
int		transformation_x(int x, int offset, int	line_len)
{
	return ((x * line_len) + offset);
}

int		transformation_y(int y, int offset, int	line_len)
{
	return ((y * line_len) + offset);
}

int		set_color(int z, int multiplier)
{
	int	r;
	int	g;
	int	b;
	int	diff;

	diff = 0;
	g = 255 - (z * multiplier);
	if (g < 0)
	{
		diff = diff + (0 - g);
		g = 0;
	}
	b = 255 - (z * multiplier);
	if (b < 0)
	{
		diff = diff + (0 - g);
		b = 0;
	}
	r = 255 - diff;
	if (r < 100)
		r = 100;
	return (putcolor(0, r, g, b));
}

// FORMULA TO CALCULATE THE COLOR FOR LINES
// 		plot_z = (((n_point->z - o_point->z) * (plot_x - o_point->x)) / (n_point->x - o_point->x)) + o_point->z;

// old algo needed double
// guess which son-of-a cuck only allows int
void	draw_low_line(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int dx = n_point->projected_x - o_point->projected_x;
	int	dy = n_point->projected_y - o_point->projected_y;
	int	yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int	D = (2 * dy) - dx;
	int	y = o_point->projected_y;
	int x = o_point->projected_x;
	while (x <= n_point->projected_x)
	{
		placepixel(&mlx->image, x, y, set_color(0, MULITIPLIER));
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
	int dx = n_point->projected_x - o_point->projected_x;
	int	dy = n_point->projected_y - o_point->projected_y;
	int	xi = 1;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int	D = (2 * dy) - dx;
	int	y = o_point->projected_y;
	int x = o_point->projected_x;
	while (y <= n_point->projected_y)
	{
		placepixel(&mlx->image, x, y, set_color(0, MULITIPLIER));
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

	x = o_point->projected_x;
	y = o_point->projected_y;
	while (y < n_point->projected_y)
	{
		placepixel(&mlx->image, x, y, set_color(0, MULITIPLIER));
		y++;
	}
}

void	draw_line_handler(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx)
{
	int dy = n_point->projected_y - o_point->projected_y; 
	int	dx = n_point->projected_x - o_point->projected_x;
	
	if (dx == 0)
	{
		if (n_point->projected_y > o_point->projected_y)
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
		if (o_point->projected_x > n_point->projected_x)
			draw_low_line(n_point, o_point, mlx);
		else
			draw_low_line(o_point, n_point, mlx);
	}
	else
	{
		if (o_point->projected_y > n_point->projected_y)
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
	while (current)
	{
		placepixel(&(mlx->image), current->projected_x, current->projected_y, set_color(0, MULITIPLIER));
		if (current->beside)
			draw_line_handler(current, current->next, mlx);
		if (current->below)
			draw_line_handler(current, current->below, mlx);
		if (current->debug_link)
			draw_line_handler(current, current->debug_link, mlx);
		if (current->debug_link2)
			draw_line_handler(current, current->debug_link2, mlx);
		current = current->next;
		i++;
	}
}

int	get_length()
{
	return (1600);
}

int	get_width()
{
	return (768);
}

t_coordinates	*find(t_coordinates *points, int x, int y)
{
	t_coordinates *current;

	current = points;
	while (current)
	{
		if (current->x == x && current->y == y)
			break;
		current = current->next;
	}
	return (current);
}

void	link_points(t_coordinates *points, int	x_offset, int	y_offset, int debug_link)
{
	t_coordinates *current;
	t_coordinates *finder;

	current = points;
	while (current)
	{
		printf("Linking..\n");
		finder = find(points, (current->x + x_offset), (current->y + y_offset));
		if (!finder)
		{
			current = current->next; 
			continue;
		}
		if (debug_link == 1)
			current->debug_link = finder;
		else
			current->debug_link2 = finder;
		current = current->next;
	}
}

void	link_below(t_coordinates *points)
{
	t_coordinates *current;
	t_coordinates *finder;

	current = points;
	while (current)
	{
		// printf("Linking..\n");
		finder = find(points, current->x, (current->y + 1));
		current->below = finder;
		finder = find(points, (current->x + 1), current->y);
		current->beside = finder;
		current = current->next;
	}
}

// i dont know what the fuck i am doing lmao

int	render_next_frame(void	*stuff)
{
	t_mlx	*mlx;
	mlx = (t_mlx *)stuff;

	int	rot_x, rot_y, rot_z;
	rot_x = 90, rot_y = 0, rot_z = 0;
	int	light_dis;
	light_dis = LIGHT_DIS;
	while (1)
	{
		// initilaize the image
		// printf("Current rot = %d\n", rot_y);
		mlx->image.img = mlx_new_image(mlx->info, mlx->length, mlx->width);
		mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bits_per_pixel, &mlx->image.line_length, &mlx->image.endian);
		mlx->image.length = mlx->length;
		mlx->image.width = mlx->width;

		// project(mlx->points, rot_x, rot_y, rot_z, TRANS_X, TRANS_Y, LINE_SIZE, light_dis, 'o');
		// fill_image(mlx, mlx->points);
		project(mlx->points, rot_x, rot_y, rot_z, TRANS_X, TRANS_Y, LINE_SIZE, light_dis, 'p');
		fill_image(mlx, mlx->points);
		mlx_put_image_to_window(mlx->info, mlx->window, mlx->image.img, 0, 0);
		mlx_destroy_image(mlx->info, mlx->image.img);
		// light_dis -= 2;
		// rot_x++;
		rot_y++;
		// rot_z++;

		// sleep(1);
		usleep(50000);
	}
}

int main(int ac, char **av)
{
	t_mlx	mlx;
	int		read_file_fd;

	if (ac != 2)
	{
		perror("pls gibe name\n");
		return (2);
	}
	// initialize the things. yes.
	read_file_fd = open(av[1], O_RDONLY);
	mlx.points = get_points(read_file_fd);
	link_below(mlx.points);
	// link_points(points, 1, 1, 1);
	// link_points(points, -1, 1, 1);

	// initialize the window
	mlx.length = get_length();
	mlx.width = get_width();
	mlx.info = mlx_init();
	mlx.window = mlx_new_window(mlx.info, mlx.length, mlx.width, "Look At These Points");

	// fill image
	mlx_loop_hook(mlx.info, render_next_frame, (void *)&mlx);
	mlx_loop(mlx.info);
}