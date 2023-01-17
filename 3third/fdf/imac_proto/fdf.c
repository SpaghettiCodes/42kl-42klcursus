#include "fdf.h"

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
	current->coord[X] = x;
	current->coord[Y] = y;
	current->coord[Z] = z;
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
	if (mlx->key_press.kbrd[W_KEY])
		mlx->attributes.y_translation += 1;
	if (mlx->key_press.kbrd[A_KEY])
		mlx->attributes.x_translation -= 1;
	if (mlx->key_press.kbrd[S_KEY])
		mlx->attributes.y_translation -= 1;
	if (mlx->key_press.kbrd[D_KEY])
		mlx->attributes.x_translation += 1;
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

void	init_attri(t_mlx mlx, t_attri *attr, t_coordinates *coordinate)
{
	attr->light_dis = LIGHT_DIS;
	attr->rot[X] = 0;
	attr->rot[Y] = 0;
	attr->rot[Z] = 0;
	attr->line_size = LINE_SIZE;
	attr->x_translation = mlx.length / 2;
	attr->y_translation = mlx.width / 2;
	attr->x_mid = highest_x(coordinate) / 2;
	attr->y_mid = highest_y(coordinate) / 2;
	attr->z_mid = 0;
	attr->z_multiplier = Z_MULTI;
	attr->color_intens = MULITIPLIER;
	attr->type = 'o';
	attr->color_type = RG;
}

void	init_keys(t_keypress *key_press)
{
	int	i;

	i = -1;
	while (++i < 4)
		key_press->kbrd[i] = RELEASED;
	key_press->mse[L_MSE] = RELEASED;
	key_press->mse[R_MSE] = RELEASED;
	key_press->lmse_diff[X] = 0;
	key_press->lmse_diff[Y] = 0;
	key_press->rmse_diff[X] = 0;
	key_press->rmse_diff[Y] = 0;
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
		return(write(2, "plz gibe nem\n", 14));
	read_file_fd = open(av[1], O_RDWR);
	if (read_file_fd == -1)
		return(write(2, "no exists file\n", 16));
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