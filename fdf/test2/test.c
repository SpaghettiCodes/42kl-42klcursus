#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "ft_split.h"

#define LINE_LENGTH 50

int	ft_atoi(const char *str);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct	s_mlx
{
	void	*info;
	void	*window;
	t_data	image;
	int		length;
	int		width;
} t_mlx;

typedef struct s_coordinates
{
	int	x;
	int	y;
	int	z;
	struct s_coordinates *next;
} t_coordinates;

void	placepixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	// funny formula to calculate memory offset = (y * line_length + x * (bits_per_pixel / 8));
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

	ret = malloc(sizeof(ret));
	ret->next = NULL;
	return (ret);
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
		while (coordinates[x])
		{
			current->x = x;
			current->y = y;
			current->z = ft_atoi(coordinates[x]);
			current->next = init();
			printf("Set Coordinate = (%d, %d, %d)\n", current->x, current->y, current->z);
			current = current->next;
			x++;
		}
		free(line);
		free(coordinates);
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

int		set_color(t_coordinates *points, int multiplier)
{
	int	r;
	int	g;

	r = 255;
	g = 0 + (points->z * multiplier);
	if (g >= 255)	
		g = 255;
	return (putcolor(0, r, g, 0));
}

void	fill_image(t_mlx *mlx, t_coordinates *points)
{
	t_coordinates	*current;
	int	i;
	
	i = 1;
	current = points;
	while (current->next)
	{
		placepixel(&(mlx->image), transformation_x(current->x, 50, LINE_LENGTH), transformation_y(current->y, 50, LINE_LENGTH), set_color(current, 20));
		printf("Placed point no %d at coordinate (%d, %d)\n", i, current->x, current->y);
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

int main(int ac, char **av)
{
	t_mlx	mlx;
	t_coordinates	*points;
	int		read_file_fd;

	read_file_fd = open(av[1], O_RDONLY);
	points = get_points(read_file_fd);
	mlx.length = get_length();
	mlx.width = get_width();
	mlx.info = mlx_init();
	mlx.window = mlx_new_window(mlx.info, mlx.length, mlx.width, "Look At These Points");
	mlx.image.img = mlx_new_image(mlx.info, mlx.length, mlx.width);
	mlx.image.addr = mlx_get_data_addr(mlx.image.img, &mlx.image.bits_per_pixel, &mlx.image.line_length, &mlx.image.endian);
	fill_image(&mlx, points);
	mlx_put_image_to_window(mlx.info, mlx.window, mlx.image.img, 0, 0);
	mlx_loop(mlx.info);
}