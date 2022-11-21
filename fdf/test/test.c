#include <stdio.h>
#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// for colors, there are 8 bits (1 bytes) each to represent trgb
// a integer is 4 bytes
// therefore, we can combine all 4 using unsigned char pointers (1 bytes) to get the integer value
int		color_set(unsigned char trans, unsigned char r, unsigned char g, unsigned char b)
{
	// unsigned char = 1 bytes 0 <= x <= 255
	unsigned char	comb[4];
	int	*ret;

	// TTTT
	comb[0] = b;
	// RRRR
	comb[1] = g;
	// GGGG
	comb[2] = r;
	// BBBB
	comb[3] = trans;
	// an integer pointer is set to point to the start of this unsigned char array
	// ret -> TTTTRRRRGGGGBBBB
	ret = (int *)&comb[0];
	// we then dereference the point to get the integer value
	return (*ret);
	// still not sure how this shit is allowed tbh
}

void	place_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	// funny formula to calculate memory offset = (y * line_length + x * (bits_per_pixel / 8));
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// alternate between red, green and blue
void	setcolor(int *r, int *g, int *b, int *reddone, int *greendone, int *bluedone)
{
	if (!(*reddone))
	{
		*r = *r + 10;
		if (*r >= 255)
		{
			*r = 0;
			*reddone = 1;
			*greendone = 2;
		}
	}
	if (*greendone == 2)
	{
		*g = *g + 10;
		if (*g >= 255)
		{
			*g = 0;
			*greendone = 1;
			*bluedone = 2;
		}
	}
	if (*bluedone == 2)
	{
		*b = *b + 10;
		if (*b >= 255)
		{
			*b = 0;
			*bluedone = 1;
			*reddone = 0;
		}
	}
}

void	set_gradient(int *r, int *g, int *b)
{
	*r = *r + 1;
	*g = *g + 1;
	if (*r >= 255 && *g >= 255)
	{
		*r = 0;
		*g = 0;
		*b = 0;
	}
}

int main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init(); // initalize mlx (establish connection to the correct graphical system)
	mlx_win = mlx_new_window(mlx, 1600, 768, "look at this"); // return a pointer to the window

	// writing pixels to an image
	// mlx_pixel_put is very slow as tries to push pixel instantly to the windo
	

	// therefore, we buffer all of our pixels to a image, which is then pushed to the window
	// think of image as a paint file, we draw where our pixels wanna be first, then only we paste it on the window
	// to initiate an image, we have to pass a few pointers which will have important variables
	
	// image width and length should be equal to the resolution of window
	img.img = mlx_new_image(mlx, 1600, 768); // initialize image

	// now we have to write pixels to this image
	// but first, we have to get the memory address of this img
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// mlx will set bits per pixel, line length and endian 

	// however, bits arent aligned, line length differs from actual window width
	// calculate memory offset using the line length set by mlx_get_data_addr

	// now we can place pixel onto the image (use place_pixel(img, x, y, color))
	for (int i = 0, r = 0, g = 0, b = 0, rd = 0, gd = 0, bd = 0; i < 1600; i++)
	{
		setcolor(&r, &g, &b, &rd, &gd, &bd);
		for (int j = 0; j < 768; j++)
		{
			place_pixel(&img, i, j, color_set(0, r, g, b));
		}
	}

	// then we can push this image to the window
	// x and y should be the upper left corner of the image
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx); // initiate window rendering
	// also handles mlx_hook functions (you will see later1)
	// should always be the last one;
}