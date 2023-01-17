#include "fdf.h"

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
	{
		if (mlx->attributes.line_size > 0)
			mlx->attributes.line_size -= 0.5;
	}
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
	}
	if (key_press->mse[R_MSE])
	{
		prev_coordx = key_press->rmse_coord[X];
		prev_coordy = key_press->rmse_coord[Y];
		key_press->rmse_diff[X] = (x - prev_coordx);
		key_press->rmse_diff[Y] = (y - prev_coordy);
		key_press->rmse_coord[X] = x;
		key_press->rmse_coord[Y] = y;
	}
}