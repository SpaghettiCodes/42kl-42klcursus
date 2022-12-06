#ifndef TEST_H
#define TEST_H

#include <mlx.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "ft_split.h"
#include <math.h>
#include <limits.h>
#include <X11/X.h>

#define X_LINE_LENGTH 50
#define Y_LINE_LENGTH 50
#define MULITIPLIER 20

int	ft_atoi(const char *str);

#define X 0
#define Y 1
#define Z 2

#define L_MSE 0
#define R_MSE 1

#define W_KEY 0
#define A_KEY 1
#define S_KEY 2
#define D_KEY 3

#define PRESSED 1
#define RELEASED 0

typedef struct s_coordinates
{
	// 0 = x, 1 = y
	int		projected_coord[2];
	// 0 = x, 1 = y, 2 = z
	float	trans_coord[3];
	// 0 = x, 1 = y, 2 = z
	int		coord[3];

	struct s_coordinates *beside;
	struct s_coordinates *below;

	struct s_coordinates *debug_link;
	struct s_coordinates *debug_link2;

	struct s_coordinates *next;
} t_coordinates;

typedef	struct	s_attri {
	// 0 = x rotation, 1 = y rotation, 2 = z rotation
	double	rot[3];

	int	x_translation;
	int	y_translation;
	
	int	line_size;
	// D = light source Distance btw (0, 0, D)
	int	light_dis;

	float	x_mid;
	float	y_mid;
	float	z_mid;

	float	z_multiplier;
	float	z_diff;
	char	type;
} t_attri;

#define SENS 0.05

typedef	struct	s_keypress {
	int		mse[2];
	int		kbrd[4];
	int		lmse_coord[2];
	float	lmse_diff[2];
	int		rmse_coord[2];
	float	rmse_diff[2];
} t_keypress;

typedef struct	s_img {
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
	void			*info;
	void			*window;
	t_data			image;
	t_coordinates	*points;
	t_attri			attributes;
	t_keypress		key_press;
	int				length;
	int				width;
} t_mlx;

// recommended = 1600
#define LIGHT_DIS 800
#define TRANS_X 800
#define TRANS_Y 384
#define LINE_SIZE 25
#define Z_MULTI 1
void		project(t_mlx *mlx, char type);
int		highest_x(t_coordinates *coordinates);
int		highest_y(t_coordinates *coordinates);
int		highest_z(t_coordinates *coordinates);
int		lowest_z(t_coordinates *coordinates);
int		hook_me_up(t_mlx *mlx);

#endif