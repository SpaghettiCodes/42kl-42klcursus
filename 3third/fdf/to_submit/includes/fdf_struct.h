/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:13:58 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:14:00 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCT_H
# define FDF_STRUCT_H

# include "fdf_const.h"

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

#endif