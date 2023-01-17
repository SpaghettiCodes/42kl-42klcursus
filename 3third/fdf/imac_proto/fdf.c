#include "fdf.h"

// FORMULA TO CALCULATE THE COLOR FOR LINES
//		plot_z = (((n_point->z - o_point->z) * (plot_x - o_point->x)) 
//									/
//			(n_point->x - o_point->x)) + o_point->z;
int	get_length()
{
	return (1900);
}

int	get_width()
{
	return (980);
}

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

int	hook_values(t_mlx *mlx)
{
	mlx->attributes.y_translation += mlx->key_press.kbrd[W_KEY];
	mlx->attributes.x_translation -= mlx->key_press.kbrd[A_KEY];
	mlx->attributes.y_translation -= mlx->key_press.kbrd[S_KEY];
	mlx->attributes.x_translation += mlx->key_press.kbrd[D_KEY];
	mlx->attributes.rot[X] += mlx->key_press.lmse_diff[Y] * SENS * -1;
	mlx->attributes.rot[Y] += mlx->key_press.lmse_diff[X] * SENS;
	mlx->attributes.rot[Z] += mlx->key_press.rmse_diff[X] * SENS;
}

int		**z_buffer(t_mlx mlx)
{
	int	**ret;
	int	x;
	int	y;

	ret = malloc (sizeof(int *) * mlx.length);
	x = 0;
	while (x < mlx.length)
	{
		ret[x] = malloc (sizeof(int) * mlx.width);
		x++;
	}
	return (ret);
}

void	freebuffer(int **tab, t_mlx mlx)
{
	int	x;

	x = 0;
	while (x < mlx.length)
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

int	render_next_frame(t_mlx *mlx)
{
	hook_values(mlx);
	mlx->image.img = mlx_new_image(mlx->info, mlx->length, mlx->width);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bits_per_pixel, &mlx->image.line_length, &mlx->image.endian);
	mlx->image.length = mlx->length;
	mlx->image.width = mlx->width;
	mlx->image.z_buff = mlx->z_buff;
	project(mlx, mlx->attributes.type);
	fill_image(mlx, mlx->points);
	if (mlx->window)
		mlx_put_image_to_window(mlx->info, mlx->window, mlx->image.img, 0, 0);
	mlx_destroy_image(mlx->info, mlx->image.img);
}

void	free_coordinate(t_coordinates **stuff)
{
	t_coordinates	*current;
	t_coordinates	*temp;

	current = *(stuff);
	while (current)
	{
		temp = current->next;
		current->beside = NULL;
		current->below = NULL;
		free(current);
		current = temp;
	}
}

int main(int ac, char **av)
{
	t_mlx	mlx;
	int		read_file_fd;

	if (ac != 2)
		return (write(2, "plz gibe nem\n", 14));
	read_file_fd = open(av[1], O_RDWR);
	if (read_file_fd == -1)
		return (write(2, "no exists file\n", 16));
	write(1, "Getting points..\n", 17);
	mlx.points = get_points(read_file_fd);
	write(1, "Linking points...\n", 18);
	link_below(mlx.points);
	mlx.length = get_length();
	mlx.width = get_width();
	mlx.info = mlx_init();
	mlx.window = mlx_new_window(mlx.info, mlx.length, mlx.width, "Look At These Points");
	mlx.z_buff = z_buffer(mlx);
	init_attri(mlx, &mlx.attributes, mlx.points);
	init_keys(&mlx.key_press);
	hook_me_up(&mlx);
	mlx_loop_hook(mlx.info, render_next_frame, (void *)&mlx);
	mlx_loop(mlx.info);
}