#include "test.h"

void	reset(t_mlx *mlx)
{
	mlx->attributes.rot[X] = 0;
	mlx->attributes.rot[Y] = 0;
	mlx->attributes.rot[Z] = 0;
}

void	color(t_mlx *mlx)
{
	mlx->attributes.color_type++;
	if (mlx->attributes.color_type >= 6)
		mlx->attributes.color_type = 0;
}

int	handle_pressed(int keycode, t_mlx	*mlx)
{
	if (keycode == ESC_CODE)
	{
		printf("Exit Window\n");
		mlx_destroy_window(mlx->info, mlx->window);
		mlx->window = NULL;
		freebuffer(mlx->z_buff, *mlx);
		// this does not exists in mac mlx
		// mlx_destroy_display(mlx.info);
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
	else if (keycode == P_CODE)
	{
		printf("Prespective mode!\n");
		mlx->attributes.type = 'p';
	}
	else if (keycode == O_CODE)
	{
		printf("Orthographic mode!\n");
		mlx->attributes.type = 'o';
	}
	else if (keycode == UP_CODE)
		mlx->attributes.z_multiplier += 0.005;
	else if (keycode == DOWN_CODE)
		mlx->attributes.z_multiplier -= 0.005;
	else if (keycode == 65361)
		mlx->attributes.color_intens += 0.5;
	else if (keycode == 65363)
		mlx->attributes.color_intens -= 0.5;
	else if (keycode == 114)
		reset(mlx);
	else if (keycode == 99)
		color(mlx);
	else
		printf("Key %d was pressed\n", keycode);
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
	else;
		// printf("Key %d was released\n", keycode);
	return (keycode);
}

int	mouse_press(int	keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 1)
	{
		mlx->key_press.mse[L_MSE] = PRESSED;
		mlx->key_press.lmse_coord[X] = x;
		mlx->key_press.lmse_coord[Y] = y;
	}
	else if (keycode == 3)
	{
		mlx->key_press.mse[R_MSE] = PRESSED;
		mlx->key_press.rmse_coord[X] = x;
		mlx->key_press.rmse_coord[Y] = y;
	}
	else if (keycode == 4)
		mlx->attributes.line_size += 0.5;
	else if (keycode == 5)
		mlx->attributes.line_size -= 0.5;
	// printf("Mouse pressed at %d, %d, key = %d\n", x, y, keycode);
	return (keycode);
}

int	mouse_released(int keycode, int x, int y, t_keypress *key_press)
{
	if (keycode == 1)
	{
		key_press->mse[L_MSE] = RELEASED;
		key_press->lmse_diff[X] = 0;
		key_press->lmse_diff[Y] = 0;
	}
	else if (keycode == 3)
	{
		key_press->mse[R_MSE] = RELEASED;
		key_press->rmse_diff[X] = 0;
		key_press->rmse_diff[Y] = 0;
	}
	return (keycode);
	// printf("Mouse released at %d, %d, key = %d\n", x, y, keycode);
}

int	mouse_movement(int x, int y, t_keypress *key_press)
{
	int	prev_coordx;
	int	prev_coordy;

	if (key_press->mse[L_MSE])
	{
		prev_coordx = key_press->lmse_coord[X];
		prev_coordy = key_press->lmse_coord[Y];

		key_press->lmse_diff[X] = (x - prev_coordx) * 0.1;
		key_press->lmse_diff[Y] = (y - prev_coordy) * 0.1;

		key_press->lmse_coord[X] = x;
		key_press->lmse_coord[Y] = y;
		// printf("mouse moved to %d %d while pressing left click\n", x, y); 
		// printf("mouse changed (%f, %f)\n", key_press->lmse_diff[X], key_press->lmse_diff[Y]);
	}
	if (key_press->mse[R_MSE])
	{
		prev_coordx = key_press->rmse_coord[X];
		prev_coordy = key_press->rmse_coord[Y];

		key_press->rmse_diff[X] = (x - prev_coordx);
		key_press->rmse_diff[Y] = (y - prev_coordy);

		key_press->rmse_coord[X] = x;
		key_press->rmse_coord[Y] = y;
		// printf("mouse moved to %d %d while pressing right click\n", x, y); 
	}
}

enum{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

int	hook_me_up(t_mlx *mlx)
{
	mlx_hook(mlx->window, ON_KEYDOWN, 0, handle_pressed, mlx);
	mlx_hook(mlx->window, ON_KEYUP, 0, handle_released, &mlx->key_press);

	mlx_hook(mlx->window, ON_MOUSEDOWN, 0, mouse_press, mlx);
	mlx_hook(mlx->window, ON_MOUSEMOVE, 0, mouse_movement, &mlx->key_press);
	mlx_hook(mlx->window, ON_MOUSEUP, 0, mouse_released, &mlx->key_press);
}
