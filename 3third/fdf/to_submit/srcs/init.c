/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:14:43 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 22:15:06 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

t_coordinates	*init(void)
{
	t_coordinates	*ret;

	ret = (t_coordinates *) malloc (sizeof(t_coordinates));
	ret->next = NULL;
	ret->below = NULL;
	return (ret);
}
