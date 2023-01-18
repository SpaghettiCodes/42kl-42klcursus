/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:15:09 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:12:51 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_pressed2(int keycode, t_mlx *mlx)
{
	if (keycode == P_CODE)
	{
		write(1, "Prespective mode!\n", 18);
		mlx->attributes.type = 'p';
	}
	else if (keycode == O_CODE)
	{
		write(1, "Orthographic mode!\n", 19);
		mlx->attributes.type = 'o';
	}
	else if (keycode == UP_CODE)
		mlx->attributes.z_multiplier += 0.005;
	else if (keycode == DOWN_CODE)
	{
		if (mlx->attributes.z_multiplier > 0)
			mlx->attributes.z_multiplier -= 0.005;
	}
	else if (keycode == LEFT_CODE)
		mlx->attributes.color_intens += 0.5;
	else if (keycode == RIGHT_CODE)
		mlx->attributes.color_intens -= 0.5;
	else
		printf("This button was pressed = %d\n", keycode);
	return (keycode);
}

// this does not exists in mac mlx
// mlx_destroy_display(mlx.info);
int	handle_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_CODE)
		clean_exit(mlx);
	else if (keycode == D_CODE)
		mlx->key_press.kbrd[D_KEY] = PRESSED;
	else if (keycode == W_CODE)
		mlx->key_press.kbrd[W_KEY] = PRESSED;
	else if (keycode == A_CODE)
		mlx->key_press.kbrd[A_KEY] = PRESSED;
	else if (keycode == S_CODE)
		mlx->key_press.kbrd[S_KEY] = PRESSED;
	else if (keycode == R_CODE)
		reset_rot(mlx);
	else if (keycode == C_CODE)
		color_type(mlx);
	else
		return (handle_pressed2(keycode, mlx));
	return (keycode);
}

int	handle_released(int keycode, t_keypress *key_press)
{
	if (keycode == D_CODE)
		key_press->kbrd[D_KEY] = RELEASED;
	else if (keycode == W_CODE)
		key_press->kbrd[W_KEY] = RELEASED;
	else if (keycode == A_CODE)
		key_press->kbrd[A_KEY] = RELEASED;
	else if (keycode == S_CODE)
		key_press->kbrd[S_KEY] = RELEASED;
	return (keycode);
}
