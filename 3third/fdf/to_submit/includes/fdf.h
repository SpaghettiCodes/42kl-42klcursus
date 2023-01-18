/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:54 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:20:21 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_split.h"
# include <math.h>
# include <limits.h>

# define X_LINE_LENGTH 50
# define Y_LINE_LENGTH 50
# define MULITIPLIER 5

# define X 0
# define Y 1
# define Z 2

# define L_MSE 0
# define R_MSE 1

# define W_KEY 0
# define A_KEY 1
# define S_KEY 2
# define D_KEY 3

# define PRESSED 1
# define RELEASED 0

# define LENGTH 1980
# define WIDTH 980

// key codes
enum {
	W_CODE = 1,
	A_CODE = 0,
	S_CODE = 13,
	D_CODE = 2,
	O_CODE = 31,
	P_CODE = 35,
	C_CODE = 8,
	LEFT_CODE = 123,
	RIGHT_CODE = 124,
	R_CODE = 15,
	ESC_CODE = 53,
	UP_CODE = 126,
	DOWN_CODE = 125
};

// x_event numbers
enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// color codes
enum {
	NO = 0,
	RG = 1,
	BG = 2,
	RB = 3,
	GR = 4,
	YB = 5
};

typedef struct s_coordinates
{
	int						coord[3];
	int						projected_coord[2];
	float					trans_coord[3];
	struct s_coordinates	*beside;
	struct s_coordinates	*below;
	struct s_coordinates	*next;
}	t_coordinates;

typedef struct s_attri {
	double	rot[3];
	int		x_translation;
	int		y_translation;

	float	line_size;
	int		light_dis;

	float	x_mid;
	float	y_mid;
	float	z_mid;

	float	z_multiplier;
	float	z_diff;
	char	type;

	float	color_intens;
	int		color_type;
}	t_attri;

# define SENS 0.05

typedef struct s_keypress {
	int		mse[2];
	int		kbrd[4];
	int		lmse_coord[2];
	float	lmse_diff[2];
	int		rmse_coord[2];
	float	rmse_diff[2];
}	t_keypress;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		length;
	int		width;
	int		**z_buff;
}	t_data;

typedef struct s_mlx {
	void			*info;
	void			*window;
	t_data			image;
	t_coordinates	*points;
	t_attri			attributes;
	t_keypress		key_press;
	int				length;
	int				width;
	int				**z_buff;
}	t_mlx;

typedef struct s_lineutils
{
	int	dx;
	int	dy;
	int	diff;
	int	x;
	int	y;
	int	yi;
	int	xi;
}	t_lineutils;

// recommended = 1600
# define LIGHT_DIS 800
# define TRANS_X 800
# define TRANS_Y 384
# define LINE_SIZE 25
# define Z_MULTI 1

// get file contents
t_coordinates	*get_points(int read_file_fd);

// atoi
int				ft_atoi(const char *str);

// link points
t_coordinates	*find_adjacent(t_coordinates *points,
					int x, int y, char option);
void			link_below(t_coordinates *points);

// find values
int				highest_x(t_coordinates *coordinates);
int				highest_y(t_coordinates *coordinates);
int				highest_z(t_coordinates *coordinates);
int				lowest_z(t_coordinates *coordinates);

// hookers
void			hook_me_up(t_mlx *mlx);
void			hook_values(t_mlx *mlx);

// key_pressed
int				handle_pressed2(int keycode, t_mlx *mlx);
int				handle_pressed(int keycode, t_mlx *mlx);
int				handle_released(int keycode, t_keypress *key_press);

// mouse
int				mouse_press(int keycode, int x, int y, t_mlx *mlx);
int				mouse_released(int keycode, int x, int y,
					t_keypress *key_press);
int				mouse_movement(int x, int y,
					t_keypress *key_press);

// colors
void			color_choice(int *r, int *g, int *b, t_attri attr);
int				putcolor(unsigned char trans, unsigned char r,
					unsigned char g, unsigned char b);
int				set_color(int plot_y, t_coordinates *o_point,
					t_coordinates *n_point, t_attri attr);
int				det_color_p(int z, t_attri attr);
int				det_color_n(int z, t_attri attr);

// rotation
void			rotate_x(t_coordinates *current, float radian);
void			rotate_y(t_coordinates *current, float radian);
void			rotate_z(t_coordinates *current, float radian);

// out of bounds checker
int				out_of_bounds(int x, int y, t_data img);
int				out_of_bounds2(t_coordinates *coord, t_data img);

// init
void			init_attri(t_mlx mlx, t_attri *attr, t_coordinates *coordinate);
void			init_keys(t_keypress *key_press);
t_coordinates	*init(void);

// free
void			freeall(char *line, char **coordinates);
void			freebuffer(int **tab, t_mlx mlx);
void			free_coordinate(t_coordinates **stuff);

// z calculators
int				calc_z(t_coordinates *n_point,
					t_coordinates *o_point, int plot_y);
int				trans_z_calc(t_coordinates *n_point,
					t_coordinates *o_point, int plot_y);

// z_buffer functions
int				**z_buffer(t_mlx mlx);
void			freebuffer(int **tab, t_mlx mlx);
void			set(int **tab, t_mlx *mlx);
int				check_z_buff(t_data *data, int x, int y, int z);

// fill image
void			placepixel(t_data *data, int x, int y, int color);
void			fill_image(t_mlx *mlx, t_coordinates *points);
void			project(t_mlx *mlx, char type);

// bersenham line algo
void			next_ll(t_lineutils *line);
void			next_hl(t_lineutils *line);
void			draw_low_line(t_coordinates *o_point,
					t_coordinates *n_point, t_mlx *mlx);
void			draw_high_line(t_coordinates *o_point,
					t_coordinates *n_point, t_mlx *mlx);
void			draw_vertical(t_coordinates *o_point,
					t_coordinates *n_point, t_mlx *mlx);
void			draw_line_handler(t_coordinates *o_point,
					t_coordinates *n_point, t_mlx *mlx);

// bersenham utisl
void			draw_vertical(t_coordinates *o_point,
					t_coordinates *n_point, t_mlx *mlx);
void			vertical_line_handler(t_coordinates *o_point,
					t_coordinates *n_point, t_mlx *mlx);

// bersenham vertical line drawer
void			set_lineutils(t_lineutils *line,
					t_coordinates *n_point, t_coordinates *o_point);
void			next_ll(t_lineutils *line);
void			next_hl(t_lineutils *line);

void			reset_rot(t_mlx *mlx);

void			color_type(t_mlx *mlx);

// clean exit
int				clean_exit(t_mlx *mlx);

#endif