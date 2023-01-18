/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:01:54 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:24:06 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fdf_struct.h"
# include "fdf_const.h"

# include "get_next_line.h"
# include "ft_split.h"

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <limits.h>

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