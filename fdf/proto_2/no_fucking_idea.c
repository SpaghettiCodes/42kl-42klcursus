#include "test.h"

// rotattat is in radian btw
int	rotattat_x(t_coordinates *current, float radian)
{
	float x;
	float y;
	float z;

	x =  current->trans_coord[X];
	y = ( current->trans_coord[Y] * cos(radian)) - (current->trans_coord[Z] * sin(radian));
	z = ( current->trans_coord[Y] * sin(radian)) + (current->trans_coord[Z] * cos(radian));

	current->trans_coord[X] = x;
	current->trans_coord[Y] = y;
	current->trans_coord[Z] = z;
}

int	rotattat_y(t_coordinates *current, float radian)
{
	float x;
	float y;
	float z;
	
	x = (current->trans_coord[X] * cos(radian)) + (current->trans_coord[Z] * sin(radian));
	y = current->trans_coord[Y];
	z = (current->trans_coord[Z] * cos(radian)) - (current->trans_coord[X] * sin(radian));

	current->trans_coord[X] = x;
	current->trans_coord[Y] = y;
	current->trans_coord[Z] = z;
}

int	rotattat_z(t_coordinates *current, float radian)
{
	float x;
	float y;
	float z;

	x = (current->trans_coord[X] * cos(radian)) - (current->trans_coord[Y] * sin(radian));
	y = (current->trans_coord[X] * sin(radian)) + (current->trans_coord[Y] * cos(radian));
	z = current->trans_coord[Z];

	current->trans_coord[X] = x;
	current->trans_coord[Y] = y;
	current->trans_coord[Z] = z;
}

void	perspective_projection(t_coordinates *current, int light_dis)
{
	float	d_Dz;
	// apparantly should work
	// assumme light source at (0,0,D)

	d_Dz = light_dis - current->trans_coord[Z];
	// this garbage worked LMAO
	if (d_Dz <= 0)
		d_Dz = 1;

	current->projected_coord[X] = ((light_dis * current->trans_coord[X]) / d_Dz);
	current->projected_coord[Y] = ((light_dis * current->trans_coord[Y]) / d_Dz);
}

double	min_light_distance(t_coordinates *coordinates)
{
	t_coordinates *ret;
	t_coordinates *current;

	ret = coordinates;
	current = coordinates;

	while (current)
	{
		if (ret->trans_coord[Z] < current->trans_coord[Z])
			ret = current;
		current = current->next;
	}
	return(ret->trans_coord[2]);
}

void	project(t_mlx *mlx, char type)
{
	t_coordinates *current;
	t_attri	*attr;
	float radian_x, radian_y, radian_z;

	current = mlx->points;
	attr = &mlx->attributes;
	while (current)
	{
		current->trans_coord[X] = (current->coord[X] - attr->x_mid ) * attr->line_size;
		current->trans_coord[Y] = (current->coord[Y] - attr->y_mid ) * attr->line_size;
		current->trans_coord[Z] = (current->coord[Z] - attr->z_mid ) * attr->line_size * attr->z_multiplier;

		radian_x = attr->rot[X] * (M_PI / 180);
		radian_y = attr->rot[Y] * (M_PI / 180);
		radian_z = attr->rot[Z] * (M_PI / 180);
	
		rotattat_x(current, radian_x);
		rotattat_y(current, radian_y);
		rotattat_z(current, radian_z);

		// orthographic
		if (type == 'o')
		{
			current->projected_coord[X] = current->trans_coord[X];
			current->projected_coord[Y] = current->trans_coord[Y];
		} // perspective
		else if (type == 'p')
			perspective_projection(current, attr->light_dis);

		current->projected_coord[X] += attr->x_translation;
		current->projected_coord[Y] += attr->y_translation;

		current = current->next;
	}

	// printf("Minimum Light Distance = %f\n", min_light_distance(coordinate));
}