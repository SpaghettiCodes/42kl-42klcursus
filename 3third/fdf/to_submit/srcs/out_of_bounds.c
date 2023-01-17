#include "fdf.h"

int	out_of_bounds(int x, int y, t_data img)
{
	if (x >= 0 && x < img.length)
		if (y >= 0 && y < img.width)
			return (0);
	return (1);
}

int	out_of_bounds2(t_coordinates *coord, t_data img)
{
	int	x;
	int	y;

	x = coord->projected_coord[X];
	y = coord->projected_coord[Y];
	if (x >= 0 && x < img.length)
		if (y >= 0 && y < img.width)
			return (0);
	return (1);
}