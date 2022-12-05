#include <mlx.h>
#include <stdio.h>
#include <mlx.h>
#include <stdlib.h>

// include le X11 events (KeyPress, KeyRelease)
#include <X11/X.h>
#include <unistd.h>
#include <math.h>
#include <wait.h>

#define X_CO 0
#define Y_CO 1

#define L_M 0
#define R_M 1

#define W_K 0
#define A_K 1
#define S_K 2
#define D_K 3

#define PRESSED 1
#define RELEASED 0

typedef struct	s_image
{
	void	*img;
	void	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
	int		length;
	int		width;
} t_image;

typedef	struct	s_pressed
{
	// 0 left, 1 right
	int	mouse_pressed[2];
	int	key_pressed[4];
} t_pressed;

typedef	struct	s_mlx
{
	void *info;
	void *win;
	t_image image;
	int	x;
	int	y;

	int max_y;
	int max_x;

	int	mouse1_coord[2];
	int	mouse2_coord[2];

	t_pressed key_press;
} t_mlx;

void	placepixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	// funny formula to calculate memory offset = (y * line_length + x * (bits_per_pixel / 8));
	if (x >= data->length || x < 0)
		return ;
	else if (y >= data->width || y < 0)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	putcolor(unsigned char trans, unsigned char r, unsigned char g, unsigned char b)
{
	int	ret;

	ret = trans << 24 | r << 16 | g << 8 | b;
	return (ret);
}

void	draw_verline(t_mlx	*mlx, int x, int color)
{
	int	y;

	y = 0;
	while (y < mlx->max_y)
	{
		placepixel(&(mlx->image), x, y, color);
		y++;
	}
}

void	draw_horiline(t_mlx	*mlx, int y, int color)
{
	int	x;

	x = 0;
	while (x < mlx->max_x)
	{
		placepixel(&(mlx->image), x, y, color);
		x++;
	}
}

int	fill_image(t_mlx *mlx, int x, int y, int max_y)
{
	draw_verline(mlx, x, putcolor(0, 255, 255, 255));
	draw_verline(mlx, mlx->mouse1_coord[X_CO], putcolor(0, 255, 255, 0));
	draw_verline(mlx, mlx->mouse2_coord[X_CO], putcolor(0, 255, 0, 0));

	draw_horiline(mlx, y, putcolor(0, 255, 255, 255));
	draw_horiline(mlx, mlx->mouse1_coord[Y_CO], putcolor(0, 255, 255, 0));
	draw_horiline(mlx, mlx->mouse2_coord[Y_CO], putcolor(0, 255, 0, 0));
}

// int	fill_image(t_mlx *mlx, int x, int y, int max_y)
// {
// 	placepixel(&(mlx->image), x, y, putcolor(0, 255, 255, 255));
// 	placepixel(&(mlx->image), mlx->mouse1_coord[0], mlx->mouse1_coord[1], putcolor(0, 255, 255, 0));
// 	placepixel(&(mlx->image), mlx->mouse2_coord[0], mlx->mouse2_coord[1], putcolor(0, 255, 0, 0));
// }


int	handle_pressed(int keycode, t_mlx	*mlx)
{
	if (keycode == 65307)
	{
		printf("bye\n");
		mlx_destroy_window(mlx->info, mlx->win);
		mlx->win = NULL;
	}
	else if (keycode == 100)
		mlx->key_press.key_pressed[D_K] = PRESSED;
	else if (keycode == 115)
		mlx->key_press.key_pressed[W_K] = PRESSED;
	else if (keycode == 97)
		mlx->key_press.key_pressed[A_K] = PRESSED;
	else if (keycode == 119)
		mlx->key_press.key_pressed[S_K] = PRESSED;
	printf("Key %d was pressed\n", keycode);
	return (keycode);
}

int	handle_released(int keycode, t_mlx *mlx)
{
	if (keycode == 100)
		mlx->key_press.key_pressed[D_K] = RELEASED;
	else if (keycode == 115)
		mlx->key_press.key_pressed[W_K] = RELEASED;
	else if (keycode == 97)
		mlx->key_press.key_pressed[A_K] = RELEASED;
	else if (keycode == 119)
		mlx->key_press.key_pressed[S_K] = RELEASED;
	printf("Key %d was released\n", keycode);
}

int	mlx_image_init(t_image *image, t_mlx *mlx)
{
	image->img = mlx_new_image(mlx->info, 1600, 720);
	image->addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bit_per_pixel, &mlx->image.line_length, &mlx->image.endian);
	image->length = 1600;
	image->width = 720;
}

void	update(t_mlx *mlx)
{
	if (mlx->key_press.key_pressed[W_K])
		mlx->y += 1;
	if (mlx->key_press.key_pressed[A_K])
		mlx->x -= 1;
	if (mlx->key_press.key_pressed[S_K])
		mlx->y -= 1;
	if (mlx->key_press.key_pressed[D_K])
		mlx->x += 1;
}

int	render_next_frame(void	*arg)
{
	t_mlx *mlx;
	mlx = (t_mlx *)arg;

	update(mlx);
	mlx_image_init(&mlx->image, mlx);
	fill_image(mlx, mlx->x, mlx->y, 720);
	if (mlx->win)
		mlx_put_image_to_window(mlx->info, mlx->win, mlx->image.img, 0, 0);
	mlx_destroy_image(mlx->info, mlx->image.img);
	return (0);
}

int	test(void	*arg)
{
	printf("Test\n");
}

int	mouse_press(int	keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 1)
	{
		mlx->key_press.mouse_pressed[L_M] = PRESSED;
		mlx->mouse1_coord[X_CO] = x;
		mlx->mouse1_coord[Y_CO] = y;
	}
	else if (keycode == 3)
	{
		mlx->key_press.mouse_pressed[R_M] = PRESSED;
		mlx->mouse2_coord[X_CO] = x;
		mlx->mouse2_coord[Y_CO] = y;
	}
	printf("Mouse pressed at %d, %d, key = %d\n", x, y, keycode);
}

int	mouse_released(int keycode, int x, int y, t_mlx *mlx)
{
	if (keycode == 1)
	{
		mlx->key_press.mouse_pressed[L_M] = RELEASED;
		mlx->mouse1_coord[X_CO] = x;
		mlx->mouse1_coord[Y_CO] = y;
	}
	else if (keycode == 3)
	{
		mlx->key_press.mouse_pressed[R_M] = RELEASED;
		mlx->mouse2_coord[X_CO] = x;
		mlx->mouse2_coord[Y_CO] = y;
	}
	printf("Mouse released at %d, %d, key = %d\n", x, y, keycode);
}

int	mouse_movement(int x, int y, t_mlx *mlx)
{
	if (mlx->key_press.mouse_pressed[L_M])
	{
		mlx->mouse1_coord[X_CO] = x;
		mlx->mouse1_coord[Y_CO] = y;
		printf("mouse moved to %d %d while pressing left click\n", x, y); 
	}
	if (mlx->key_press.mouse_pressed[R_M])
	{
		mlx->mouse2_coord[X_CO] = x;
		mlx->mouse2_coord[Y_CO] = y;
		printf("mouse moved to %d %d while pressing right click\n", x, y); 
	}
}

int	win_resize(int width, int height, t_mlx *mlx)
{
	printf("new window size %d, %d\n", width, height);
}

int	wow_hookers(t_mlx *mlx)
{
	// wow no idea what does mask do
	mlx_hook(mlx->win, KeyPress, KeyPressMask, handle_pressed, mlx);
	mlx_hook(mlx->win, KeyRelease, KeyReleaseMask, handle_released, mlx);

	mlx_hook(mlx->win, ButtonPress, ButtonPressMask, mouse_press, mlx);
	mlx_hook(mlx->win, MotionNotify, ButtonMotionMask, mouse_movement, mlx);
	mlx_hook(mlx->win, ButtonRelease, ButtonReleaseMask, mouse_released, mlx);
}

int main()
{
	t_mlx mlx;

	mlx.info = mlx_init();
	mlx.win = mlx_new_window(mlx.info, 1600, 720, "hooking callibration");
	
	mlx.max_y = 720;
	mlx.max_x = 1600;

	mlx.x = 100;
	mlx.y = 100;

	mlx.key_press.key_pressed[W_K] = RELEASED;
	mlx.key_press.key_pressed[A_K] = RELEASED;
	mlx.key_press.key_pressed[S_K] = RELEASED;
	mlx.key_press.key_pressed[D_K] = RELEASED;
	// only handles releasing the key (wtf)
	// mlx_key_hook(mlx.win, handle_input, &mlx);
	wow_hookers(&mlx);

	mlx_loop_hook(mlx.info, render_next_frame, (void *)&mlx);
	mlx_loop(mlx.info);

	// this runs after there is no more window
	mlx_destroy_display(mlx.info);
	free(mlx.info);
	return (0);
}