#ifndef TEST_H
#define TEST_H

#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "ft_split.h"
#include <math.h>
#include <limits.h>

#define X_LINE_LENGTH 50
#define Y_LINE_LENGTH 50
#define MULITIPLIER 20

int	ft_atoi(const char *str);

typedef struct s_coordinates
{
	int	projected_x;
	int	projected_y;
	float	trans_x;
	float	trans_y;
	float	trans_z;
	int	x;
	int	y;
	int	z;
	struct s_coordinates *next;
	struct s_coordinates *beside;
	struct s_coordinates *below;
	struct s_coordinates *debug_link;
	struct s_coordinates *debug_link2;
} t_coordinates;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		length;
	int		width;
}	t_data;

typedef struct	s_mlx
{
	void	*info;
	void	*window;
	t_data	image;
	t_coordinates *points;
	int		length;
	int		width;
} t_mlx;

// recommended = 1600
#define LIGHT_DIS 800
#define TRANS_X 800
#define TRANS_Y 384
#define LINE_SIZE 25
#define Z_MULTI 1

void		project(t_coordinates *coordinate, int degree_x, int degree_y, int degree_z, int transl_x, int	transl_y, int	line_size, int	light_dis, char type);

#endif