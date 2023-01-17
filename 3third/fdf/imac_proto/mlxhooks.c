#include "fdf.h"

void	reset_rot(t_mlx *mlx)
{
	mlx->attributes.rot[X] = 0;
	mlx->attributes.rot[Y] = 0;
	mlx->attributes.rot[Z] = 0;
}

void	color(t_mlx *mlx)
{
	++mlx->attributes.color_type;
	if (mlx->attributes.color_type >= 6)
		mlx->attributes.color_type = 0;
}

// this does not exists in mac mlx
// mlx_destroy_display(mlx.info);

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
	else if (keycode == 65361)
		mlx->attributes.color_intens += 0.5;
	else if (keycode == 65363)
		mlx->attributes.color_intens -= 0.5;
	return (keycode);
}

int	handle_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == ESC_CODE)
	{
		write(1, "Exit Window\n", 13);
		mlx_destroy_window(mlx->info, mlx->window);
		mlx->window = NULL;
		freebuffer(mlx->z_buff, *mlx);
		free(mlx->info);
		free_coordinate(&mlx->points);
		exit(0);
	}
	else if (keycode == D_CODE)
		mlx->key_press.kbrd[D_KEY] = PRESSED;
	else if (keycode == W_CODE)
		mlx->key_press.kbrd[W_KEY] = PRESSED;
	else if (keycode == A_CODE)
		mlx->key_press.kbrd[A_KEY] = PRESSED;
	else if (keycode == S_CODE)
		mlx->key_press.kbrd[S_KEY] = PRESSED;
	else if (keycode == 114)
		reset_rot(mlx);
	else if (keycode == 99)
		color(mlx);
	else
		return (handle_pressed2(keycode, mlx));

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

int	hook_me_up(t_mlx *mlx)
{
	mlx_hook(mlx->window, ON_KEYDOWN, 0, handle_pressed, mlx);
	mlx_hook(mlx->window, ON_KEYUP, 0, handle_released, &mlx->key_press);
	mlx_hook(mlx->window, ON_MOUSEDOWN, 0, mouse_press, mlx);
	mlx_hook(mlx->window, ON_MOUSEMOVE, 0, mouse_movement, &mlx->key_press);
	mlx_hook(mlx->window, ON_MOUSEUP, 0, mouse_released, &mlx->key_press);
}
