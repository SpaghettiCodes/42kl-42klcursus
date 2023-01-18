/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:16:02 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 22:16:03 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	hook_values(t_mlx *mlx)
{
	mlx->attributes.y_translation += mlx->key_press.kbrd[W_KEY];
	mlx->attributes.x_translation -= mlx->key_press.kbrd[A_KEY];
	mlx->attributes.y_translation -= mlx->key_press.kbrd[S_KEY];
	mlx->attributes.x_translation += mlx->key_press.kbrd[D_KEY];
	mlx->attributes.rot[X] += mlx->key_press.lmse_diff[Y] * SENS * -1;
	mlx->attributes.rot[Y] += mlx->key_press.lmse_diff[X] * SENS;
	mlx->attributes.rot[Z] += mlx->key_press.rmse_diff[X] * SENS;
}

void	reset_rot(t_mlx *mlx)
{
	mlx->attributes.rot[X] = 0;
	mlx->attributes.rot[Y] = 0;
	mlx->attributes.rot[Z] = 0;
}

void	color_type(t_mlx *mlx)
{
	++mlx->attributes.color_type;
	if (mlx->attributes.color_type >= 6)
		mlx->attributes.color_type = 0;
}

int	hook_me_up(t_mlx *mlx)
{
	mlx_hook(mlx->window, ON_KEYDOWN, 0, handle_pressed, mlx);
	mlx_hook(mlx->window, ON_KEYUP, 0, handle_released, &mlx->key_press);
	mlx_hook(mlx->window, ON_MOUSEDOWN, 0, mouse_press, mlx);
	mlx_hook(mlx->window, ON_MOUSEMOVE, 0, mouse_movement, &mlx->key_press);
	mlx_hook(mlx->window, ON_MOUSEUP, 0, mouse_released, &mlx->key_press);
}
