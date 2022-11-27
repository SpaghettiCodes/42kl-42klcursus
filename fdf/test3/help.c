#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <wait.h>

typedef struct	s_image
{
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		length;
	int		width;
} t_image;

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

typedef	struct	s_mlx
{
	void *info;
	void *win;
	t_c *coordinates;
	t_image image;
} t_mlx;

int	putcolor(unsigned char trans, unsigned char r, unsigned char g, unsigned char b)
{
	int	ret;

	ret = trans << 24 | r << 16 | g << 8 | b;
	return (ret);
}

int		set_color(int z, int multiplier)
{
	int	r;
	int	g;
	int	b;
	int	diff;

	if (z < 0)
	{
		z = -z;
		r = 255 - z;
		g = 0;
		b = 0;
		if (r < 100)
			r = 100;
	}
	else if (z >= 0)
	{
		r = 255;
		g = 0 + z;
		if (g > 255)
			g = 255;
		b = 0 + z;
		if (b > 255)
			b = 255;
	}
	return(putcolor(0, r, g, b));

}

int	det_color(int x0, int y0, int z0, int x1, int y1, int z1, int x, int y)
{
	int	height_val;

	if ((x1 - x0))
		height_val = (((z1 - z0) * (x - x0)) / (x1 - x0)) + z1;
	else
		height_val = (((z1 - z0) * (y - y0)) / (y1 - y0)) + z1;
	return(set_color(height_val, 20));
}

void	placepixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	// funny formula to calculate memory offset = (y * line_length + x * (bits_per_pixel / 8));
	if (x >= data->length || x < 0)
		return ;
	else if (y >= data->width || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_low_line(int x0, int y0, int z0, int x1, int y1, int z1, t_mlx *mlx)
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
		placepixel(&mlx->image, x, y, det_color(x0, y0, z0, x1, y1, z1, x, y));
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

void	draw_high_line(int x0, int y0, int z0, int x1, int y1, int z1, t_mlx *mlx)
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
		placepixel(&mlx->image, x, y, det_color(x0, y0, z0, x1, y1, z1, x, y));
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

void	draw_vertical(int x, int y0, int y1, int z0, int z1, t_mlx *mlx)
{
	int	y;
	int height_val;

	y = y0;
	while (y < y1)
	{
		placepixel(&mlx->image, x, y, det_color(x, y0, z0, x, y1, z1, x, y));
		y++;
	}
	printf("Drawn\n");
}

void	draw_line_handler(int x0, int x1, int y0, int y1, int z0, int z1, t_mlx *mlx)
{
	int dy = y1 - y0;
	int	dx = x1 - x0;
	
	if (dx == 0)
	{
		if (y1 > y0)
			draw_vertical(x0, y0, y1, z0, z1, mlx);
		else
			draw_vertical(x0, y1, y0, z1, z0,mlx);
		return;
	}
	if (abs(dy) < abs(dx))
	{
		if (x0 > x1)
			draw_low_line(x1, y1, z1, x0, y0, z0, mlx);
		else
			draw_low_line(x0, y0, z0, x1, y1, z1, mlx);
	}
	else
	{
		if (y0 > y1)
			draw_high_line(x1, y1, z1, x0, y0, z0, mlx);
		else
			draw_high_line(x0, y0, z0, x1, y1, z1, mlx);
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
			draw_line_handler(current->projected_x, current->link1->projected_x, current->projected_y, current->link1->projected_y, current->trans_z, current->link1->trans_z ,mlx);
		}
		if (current->link2)
		{
			printf("Drawing line 2.. ");
			draw_line_handler(current->projected_x, current->link2->projected_x, current->projected_y, current->link2->projected_y, current->trans_z, current->link1->trans_z ,mlx);
		}
		if (current->link3)
		{
			printf("Drawing line 3.. ");
			draw_line_handler(current->projected_x, current->link3->projected_x, current->projected_y, current->link3->projected_y, current->trans_z, current->link1->trans_z ,mlx);
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

	x =  current->trans_x;
	y = ( current->trans_y * cos(radian)) - (current->trans_z * sin(radian));
	z = ( current->trans_y * sin(radian)) + (current->trans_z * cos(radian));

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
}

int	rotattat_y(t_c *current, double radian)
{
	double x;
	double y;
	double z;
	
	x = (current->trans_x * cos(radian)) + (current->trans_z * sin(radian));
	y = current->trans_y;
	z = (current->trans_z * cos(radian)) - (current->trans_x * sin(radian));

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
}

int	rotattat_z(t_c *current, double radian)
{
	double x;
	double y;
	double z;

	x = (current->trans_x * cos(radian)) - (current->trans_y * sin(radian));
	y = (current->trans_x * sin(radian)) + (current->trans_y * cos(radian));
	z = current->trans_z;

	current->trans_x = x;
	current->trans_y = y;
	current->trans_z = z;
}

#define LINE_SIZE 100
#define OFFSET_X 625
#define OFFSET_Y 250

// D = light source Distance btw (0, 0, D)
#include <limits.h>

int	highest_x(t_c *coordinates)
{

}

int	highest_y(t_c *coordinates)
{

}


#define D 1200
void	perspective_projection(t_c *current, int light_dis)
{
	// apparantly should work

	current->projected_x = ((light_dis * current->trans_x) / (light_dis - current->trans_z));
	current->projected_y = ((light_dis * current->trans_y) / (light_dis - current->trans_z));
}

void	project(t_c *coordinate, int degree_x, int degree_y, int degree_z, int	transl_x, int	transl_y, int	line_size, char type)
{
	t_c *current;
	double	midpoint_x = 0.5;
	double	midpoint_y = 0.5;
	double	midpoint_z = 0.5;

	current = coordinate;
	while (current)
	{
		current->trans_x = ((current->x * line_size) - (midpoint_x * line_size));
		current->trans_y = ((current->y * line_size) - (midpoint_x * line_size));
		current->trans_z = ((current->z * line_size) - (midpoint_x * line_size));

		double radian_x = degree_x * (M_PI / 180);
		double radian_y = degree_y * (M_PI / 180);
		double radian_z = degree_z * (M_PI / 180);
	
		rotattat_x(current, radian_x);
		rotattat_y(current, radian_y);
		rotattat_z(current, radian_z);
	
	
		// orthographic
		if (type == 'o')
		{
			current->projected_x = current->trans_x;
			current->projected_y = current->trans_y;
		} // perspective

		else if (type == 'p')
		{
			perspective_projection(current, D);
		}

		current->projected_x += transl_x;
		current->projected_y += transl_y;
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

void	link_struct(t_c *coordinate)
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

int	render_next_frame(void	*stuff)
{
	int	x, y, z;
	int	x_trans, y_trans;
	int	line_size;
	t_mlx *mlx = (t_mlx *)stuff;

	x = 0, y = 0, z = 0;
	x_trans = 500, y_trans = 200;
	line_size = 150;

	while (1)
	{
		mlx->image.img = mlx_new_image(mlx->info, 1600, 720);
		mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bit_per_pixel, &mlx->image.line_length, &mlx->image.endian);
		mlx->image.length = 1600;
		mlx->image.width = 720;
		project(mlx->coordinates, x, y, z, x_trans, y_trans, line_size, 'p');
		fill_image(mlx->coordinates, mlx);
		mlx_put_image_to_window(mlx->info, mlx->win, mlx->image.img, 0, 0);
		mlx_destroy_image(mlx->info, mlx->image.img);
		char *string = "Blue = Below YX axis  Red = Above YX axis  Yellow = On YX Axis  White = Good luck figuring out";
		mlx_string_put(mlx->info, mlx->win, 2, 20, putcolor(0, 255, 255, 255), string);

		x++;
		y++;
		// z++;
		usleep(10000);
		// sleep(10);
	}
}

int main()
{
	t_mlx mlx;
	mlx.info = mlx_init();
	mlx.win = mlx_new_window(mlx.info, 1600, 720, "BANAN ROTATTTET");

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

	mlx.coordinates = arr_to_struct(coordinates, 8, 3);

	t_c *current;
	current = mlx.coordinates;
	// init
	link_struct(mlx.coordinates);

	mlx_loop_hook(mlx.info, render_next_frame, (void *)&mlx);
	mlx_loop(mlx.info);
}