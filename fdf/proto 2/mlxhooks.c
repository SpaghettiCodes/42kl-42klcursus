#include "test.h"

int	handle_pressed(int keycode, t_mlx	*mlx)
{
	if (keycode == 65307)
	{
		printf("bye\n");
		mlx_destroy_window(mlx->info, mlx->window);
		mlx->window = NULL;
	}
	else if (keycode == 100)
		mlx->key_press.kbrd[D_KEY] = PRESSED;
	else if (keycode == 115)
		mlx->key_press.kbrd[W_KEY] = PRESSED;
	else if (keycode == 97)
		mlx->key_press.kbrd[A_KEY] = PRESSED;
	else if (keycode == 119)
		mlx->key_press.kbrd[S_KEY] = PRESSED;
	else if (keycode == 112)
	{
		printf("Prespective mode!\n");
		mlx->attributes.type = 'p';
	}
	else if (keycode == 111)
	{
		printf("Orthographic mode!\n");
		mlx->attributes.type = 'o';
	}
	else if (keycode == 65362)
		mlx->attributes.z_multiplier += 0.005;
	else if (keycode == 65364)
		mlx->attributes.z_multiplier -= 0.005;
	else
		printf("Key %d was pressed\n", keycode);
	return (keycode);
}

int	handle_released(int keycode, t_keypress *key_press)
{
	if (keycode == 100)
		key_press->kbrd[D_KEY] = RELEASED;
	else if (keycode == 115)
		key_press->kbrd[W_KEY] = RELEASED;
	else if (keycode == 97)
		key_press->kbrd[A_KEY] = RELEASED;
	else if (keycode == 119)
		key_press->kbrd[S_KEY] = RELEASED;
	else;
		// printf("Key %d was released\n", keycode);
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
		mlx->attributes.line_size += 0.2;
	else if (keycode == 5)
		mlx->attributes.line_size -= 0.2;
	// printf("Mouse pressed at %d, %d, key = %d\n", x, y, keycode);
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

		key_press->lmse_diff[X] = x - prev_coordx;
		key_press->lmse_diff[Y] = y - prev_coordy;

		key_press->lmse_coord[X] = x;
		key_press->lmse_coord[Y] = y;
		// printf("mouse moved to %d %d while pressing left click\n", x, y); 
		// printf("mouse changed (%f, %f)\n", key_press->lmse_diff[X], key_press->lmse_diff[Y]);
	}
	if (key_press->mse[R_MSE])
	{
		prev_coordx = key_press->rmse_coord[X];
		prev_coordy = key_press->rmse_coord[Y];

		key_press->rmse_diff[X] = x - prev_coordx;
		key_press->rmse_diff[Y] = y - prev_coordy;

		key_press->rmse_coord[X] = x;
		key_press->rmse_coord[Y] = y;
		// printf("mouse moved to %d %d while pressing right click\n", x, y); 
	}
}

int	hook_me_up(t_mlx *mlx)
{
	mlx_hook(mlx->window, KeyPress, KeyPressMask, handle_pressed, mlx);
	mlx_hook(mlx->window, KeyRelease, KeyReleaseMask, handle_released, &mlx->key_press);

	mlx_hook(mlx->window, ButtonPress, ButtonPressMask, mouse_press, mlx);
	mlx_hook(mlx->window, MotionNotify, ButtonMotionMask, mouse_movement, &mlx->key_press);
	mlx_hook(mlx->window, ButtonRelease, ButtonReleaseMask, mouse_released, &mlx->key_press);
}