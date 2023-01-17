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

int	hook_me_up(t_mlx *mlx)
{
	mlx_hook(mlx->window, ON_KEYDOWN, 0, handle_pressed, mlx);
	mlx_hook(mlx->window, ON_KEYUP, 0, handle_released, &mlx->key_press);
	mlx_hook(mlx->window, ON_MOUSEDOWN, 0, mouse_press, mlx);
	mlx_hook(mlx->window, ON_MOUSEMOVE, 0, mouse_movement, &mlx->key_press);
	mlx_hook(mlx->window, ON_MOUSEUP, 0, mouse_released, &mlx->key_press);
}
