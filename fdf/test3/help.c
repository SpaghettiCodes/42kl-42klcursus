#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <math.h>

typedef struct	s_image
{
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
} t_image;

typedef	struct	s_mlx
{
	void *info;
	void *win;
	t_image image;
} t_mlx;

typedef	struct	s_c
{
	int	projected_x;
	int	projected_y;
	double	trans_x;
	double	trans_y;
	double	trans_z;
	int	x;
	int	y;
	int	z;
	struct s_c *link1;
	struct s_c *link2;
	struct s_c *link3;
	struct s_c *next;
} t_c;

void	placepixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	// funny formula to calculate memory offset = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_low_line(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
	int dx = x1 - x0;
	int	dy = y1 - y0;
	int	yi = 1;

	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	int	D = (2 * dy) - dx;
	int	y = y0;
	int x = x0;
	while (x <= x1)
	{
		placepixel(&mlx->image, x, y, 0x00FFFFFF);
		if (D > 0)
		{
			y = y + yi;
			D = D + (2 * (dy - dx));
		}
		else
			D = D + 2 * dy;
		x++;
	}
	printf("Drawn\n");
}

void	draw_high_line(int x0, int y0, int x1, int y1, t_mlx *mlx)
{
	int dx = x1 - x0;
	int	dy = y1 - y0;
	int	xi = 1;

	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int	D = (2 * dx) - dy;
	int	y = y0;
	int x = x0;
	while (y <= y1)
	{
		placepixel(&mlx->image, x, y, 0x00FFFFFF);
		if (D > 0)
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else
			D = D + (2 * dx);
		y++;
	}
	printf("Drawn\n");
}

void	draw_vertical(int x, int y0, int y1, t_mlx *mlx)
{
	int	y;
	int height_val;

	y = y0;
	while (y < y1)
	{
		placepixel(&mlx->image, x, y, 0x00FFFFFF);
		y++;
	}
	printf("Drawn\n");
}

void	draw_line_handler(int x0, int x1, int y0, int y1, t_mlx *mlx)
{
	int dy = y1 - y0;
	int	dx = x1 - x0;
	
	if (dx == 0)
	{
		if (y1 > y0)
			draw_vertical(x0, y0, y1, mlx);
		else
			draw_vertical(x0, y1, y0, mlx);
		return;
	}
	if (abs(dy) < abs(dx))
	{
		if (x0 > x1)
			draw_low_line(x1, y1, x0, y0, mlx);
		else
			draw_low_line(x0, y0, x1, y1, mlx);
	}
	else
	{
		if (y0 > y1)
			draw_high_line(x1, y1, x0, y0, mlx);
		else
			draw_high_line(x0, y0, x1, y1, mlx);
	}
}

t_c		*tcinit()
{
	t_c *ret; 

	ret = malloc (sizeof(t_c));
	ret->next = NULL; 
	ret->link1 = NULL;
	ret->link2 = NULL;
	ret->link3 = NULL;
	return (ret);
}

t_c		*arr_to_struct(int coordinates[8][3], int num, int dimen)
{
	t_c *ret; 
	t_c *current;

	ret = tcinit();
	current = ret;

	int	i = 0;
	while (i < num)
	{
		printf("Got a coordinate\n");
		current->x = coordinates[i][0];
		current->y = coordinates[i][1];
		current->z = coordinates[i][2];
		if (i < (num - 1))
		{
			current->next = tcinit();
			current = current->next;
		}
		i++;
	}
	current->next = NULL;
	return (ret);
}

void	fill_image(t_c *points, t_mlx *mlx)
{
	t_c *current;

	current = points;
	while (current)
	{
		placepixel(&mlx->image, current->projected_x, current->projected_y, 0x00FFFFFF);
		printf("Placed point (%d, %d)\n", current->projected_x, current->projected_y);
		if (current->link1)
		{
			printf("Drawing line 1.. ");
			draw_line_handler(current->projected_x, current->link1->projected_x, current->projected_y, current->link1->projected_y, mlx);
		}
		if (current->link2)
		{
			printf("Drawing line 2.. ");
			draw_line_handler(current->projected_x, current->link2->projected_x, current->projected_y, current->link2->projected_y, mlx);
		}
		if (current->link3)
		{
			printf("Drawing line 3.. ");
			draw_line_handler(current->projected_x, current->link3->projected_x, current->projected_y, current->link3->projected_y, mlx);
		}
		printf("DONE!\n");
		current = current->next;
	}
}

// rotattat is in radian btw
int	rotattat_x(t_c *current, double radian)
{
	double x;
	double y;
	double z;
	printf("rotating x\n");

	x = current->trans_x;
	y = current->trans_y;
	z = current->trans_z;

	printf("Before: %f, %f, %f\n", x, y, z);
	x = x;
	y = (y * cos(radian)) - (z * sin(radian));
	z = (y * sin(radian)) + (z * cos(radian));

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
	printf("After: %f, %f, %f\n", x, y, z);
}

int	rotattat_y(t_c *current, double radian)
{
	double x;
	double y;
	double z;
	printf("rotating y\n");

	x = current->trans_x;
	y = current->trans_y;
	z = current->trans_z;

	printf("Before: %f, %f, %f\n", x, y, z);
	x = (x * cos(radian)) + (z * sin(radian));
	y = y;
	z = - (x * sin(radian)) + (z * cos(radian));

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
	printf("After: %f, %f, %f\n", x, y, z);
}

int	rotattat_z(t_c *current, double radian)
{
	double x;
	double y;
	double z;
	printf("rotating y\n");

	x = current->trans_x;
	y = current->trans_y;
	z = current->trans_z;

	printf("Before: %f, %f, %f\n", x, y, z);
	x = (x * cos(radian)) - (y * sin(radian));
	y = (x * sin(radian)) + (y * cos(radian));
	z = z;

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
	printf("After: %f, %f, %f\n", x, y, z);
}

#define LINE_SIZE 150
#define OFFSET_X 625
#define OFFSET_Y 250

// D = light source Distance btw
#include <limits.h>
#define D 1600

void	project(t_c *coordinate)
{
	t_c *current;

	current = coordinate;
	while (current)
	{
		current->trans_x = (double)(current->x * LINE_SIZE);
		current->trans_y = (double)(current->y * LINE_SIZE);
		current->trans_z = (double)(current->z * LINE_SIZE);

		double radian_x = 30 * (M_PI / 180);
		double radian_y = 30 * (M_PI / 180);
		double radian_z = 0 * (M_PI / 180);
		rotattat_x(current, radian_x);
		rotattat_y(current, radian_y);
		rotattat_z(current, radian_z);
		// to refer what the fuck i did here, read your ipad notes;

		current->trans_x += OFFSET_X;
		current->trans_y += OFFSET_Y;

		printf("(%f, %f)\n", current->trans_x, current->trans_y);
		printf("(%d, %d)\n", (int)current->trans_x, (int)current->trans_y);
		// current->projected_x = (D / (D - current->trans_z)) * current->trans_x;
		// current->projected_y = (D / (D - current->trans_z)) * current->trans_y;

		current->projected_x = current->trans_x;
		current->projected_y = current->trans_y;
		current = current->next;
	}
}

t_c	*find(t_c *coordinate, int x, int y, int z)
{
	t_c *current;

	current = coordinate;
	while (current)
	{
		if (current->x == x && current->y == y && current->z == z)
		{
			break;
		}
		current = current->next;
	}
	return (current);
}

void	link(t_c *coordinate)
{
	t_c *current;
	t_c *finder;
	
	printf("linking.. ");

	current = find(coordinate, 0, 0, 0);
	current->link1 = find(coordinate, 1, 0, 0);
	current->link2 = find(coordinate, 0, 0, 1); // up
	current->link3 = find(coordinate, 0, 1, 0);

	current = find(coordinate, 1, 1, 1);
	current->link1 = find(coordinate, 0, 1, 1);
	current->link2 = find(coordinate, 1, 1, 0); // down
	current->link3 = find(coordinate, 1, 0, 1);

	current = find(coordinate, 0, 1, 0);
	current->link1 = find(coordinate, 0, 1, 1); // down
	current->link2 = find(coordinate, 1, 1, 0);

	current = find(coordinate, 1, 0, 1);
	current->link1 = find(coordinate, 1, 0, 0); // down
	current->link2 = find(coordinate, 0, 0, 1);

	current = find(coordinate, 0, 0, 1);
	current->link1 = find(coordinate, 0, 1, 1);

	current = find(coordinate, 1, 1, 0);
	current->link1 = find(coordinate, 1, 0, 0);
	printf("LINKED!\n");
}

int main()
{
	t_mlx mlx;
	t_c	*coordinate;
	mlx.info = mlx_init();
	mlx.win = mlx_new_window(mlx.info, 1600, 720, "BANAN ROTATTTET");
	mlx.image.img = mlx_new_image(mlx.info, 1600, 720);
	mlx.image.addr = mlx_get_data_addr(mlx.image.img, &mlx.image.bit_per_pixel, &mlx.image.line_length, &mlx.image.endian);

	int coordinates[8][3] = {
		{0,0,0},
		{1,0,0},
		{1,1,0},
		{0,1,0},
		{0,0,1},
		{1,0,1},
		{1,1,1},
		{0,1,1}
	};

	coordinate = arr_to_struct(coordinates, 8, 3);

	t_c *current;
	current = coordinate;
	while (current)
	{
		printf("(%d, %d, %d)\n", current->x, current->y, current->z);
		current = current->next;
	}

	link(coordinate);

	project(coordinate);
	
	fill_image(coordinate, &mlx);

	mlx_put_image_to_window(mlx.info, mlx.win, mlx.image.img, 0, 0);
	mlx_loop(mlx.info);
}