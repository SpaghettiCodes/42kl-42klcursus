#include "fdf.h"

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
