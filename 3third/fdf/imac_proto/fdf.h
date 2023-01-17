#ifndef TEST_H
#define TEST_H

#include "./mlx/mlx.h"
#include <fcntl.h>
#include "get_next_line.h"
#include "ft_split.h"
#include <math.h>
#include <limits.h>

#define X_LINE_LENGTH 50
#define Y_LINE_LENGTH 50
#define MULITIPLIER 5

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

enum {
	W_CODE = 13,
	A_CODE = 0,
	S_CODE = 1,
	D_CODE = 2,
	O_CODE = 31,
	P_CODE = 35,
	ESC_CODE = 53,
	UP_CODE = 126,
	DOWN_CODE = 125,
};

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

typedef struct s_coordinates
{
	int						coord[3];
	int						projected_coord[2];
	float					trans_coord[3];
	struct s_coordinates	*beside;
	struct s_coordinates	*below;
	struct s_coordinates	*next;
} t_coordinates;

#define NO 0
#define RG 1
#define BG 2
#define RB 3
#define GR 4
#define YB 5

typedef	struct	s_attri {
	// 0 = x rotation, 1 = y rotation, 2 = z rotation
	double	rot[3];

	int	x_translation;
	int	y_translation;
	
	float	line_size;
	// D = light source Distance btw (0, 0, D)
	int	light_dis;

	float	x_mid;
	float	y_mid;
	float	z_mid;

	float	z_multiplier;
	float	z_diff;
	char	type;

	float	color_intens;
	int		color_type;
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
	int		**z_buff;
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
	int				**z_buff;
} t_mlx;

typedef struct s_lineutils
{
	int	dx;
	int	dy;
	int	D;
	int	x;
	int	y;
	int	yi;
	int xi;
} t_lineutils;

// recommended = 1600
#define LIGHT_DIS 800
#define TRANS_X 800
#define TRANS_Y 384
#define LINE_SIZE 25
#define Z_MULTI 1

void		project(t_mlx *mlx, char type);
int			highest_x(t_coordinates *coordinates);
int			highest_y(t_coordinates *coordinates);
int			highest_z(t_coordinates *coordinates);
int			lowest_z(t_coordinates *coordinates);
int			hook_me_up(t_mlx *mlx);
int			set_color(int plot_y, t_coordinates *o_point, t_coordinates *n_point, t_attri attr);

int			not_valid(int x, int y, t_data img);
void		placepixel(t_data *data, int x, int y, int z, int color);
int			putcolor(unsigned char trans, unsigned char r, unsigned char g, unsigned char b);
int			skipx(int startx, t_data img_prop, t_lineutils *line);
int			skipy(int startx, t_data img_prop, t_lineutils *line);
void		next_ll(t_lineutils *line);
void		next_hl(t_lineutils *line);
void		draw_low_line(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx);
void		draw_high_line(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx);
void		draw_vertical(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx);
void		draw_line_handler(t_coordinates *o_point, t_coordinates *n_point, t_mlx *mlx);
void		fill_image(t_mlx *mlx, t_coordinates *points);
void		freebuffer(int **tab, t_mlx mlx);
void		free_coordinate(t_coordinates **stuff);

// mouse
int			mouse_press(int	keycode, int x, int y, t_mlx *mlx);
int			mouse_released(int keycode, int x, int y, t_keypress *key_press);
int			mouse_movement(int x, int y, t_keypress *key_press);

// colors
void		color_choice(int *r, int *g, int *b, t_attri attr);
int			det_color_p(int z, t_attri attr);
int			det_color_n(int z, t_attri attr);

// rotation
#include "fdf.h"

// rotattat is in radian btw
int			rotate_x(t_coordinates *current, float radian);
int			rotate_y(t_coordinates *current, float radian);
int			rotate_z(t_coordinates *current, float radian);

// out of bounds checker
int			out_of_bounds(int x, int y, t_data img);
int			out_of_bounds2(t_coordinates *coord, t_data img);

// init
void			init_attri(t_mlx mlx, t_attri *attr, t_coordinates *coordinate);
void			init_keys(t_keypress *key_press);
t_coordinates	*init();

#endif