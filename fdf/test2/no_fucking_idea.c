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

void	perspective_projection(t_coordinates *current, int light_dis, int coord_2[3])
{
	// apparantly should work
	// assumme light source at (0,0,D)

	current->projected_coord[X] = ((light_dis * coord_2[X]) / (light_dis - coord_2[Z]));
	current->projected_coord[Y] = ((light_dis * coord_2[Y]) / (light_dis - coord_2[Z]));
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
	int coord_2[3];

	current = mlx->points;
	attr = &mlx->attributes;
	while (current)
	{
		float radian_x = attr->rot[X] * (M_PI / 180);
		float radian_y = attr->rot[Y] * (M_PI / 180);
		float radian_z = attr->rot[Z] * (M_PI / 180);
	
		rotattat_x(current, radian_x);
		rotattat_y(current, radian_y);
		rotattat_z(current, radian_z);

		// orthographic
		coord_2[X] = current->trans_coord[X] * attr->line_size;
		coord_2[Y] = current->trans_coord[Y] * attr->line_size;
		coord_2[Z] = current->trans_coord[Z] * attr->line_size;
		if (type == 'o')
		{
			current->projected_coord[X] = coord_2[X];
			current->projected_coord[Y] = coord_2[Y];
		} // perspective
		else if (type == 'p')
			perspective_projection(current, attr->light_dis, coord_2);

		current->projected_coord[X] += attr->x_translation;
		current->projected_coord[Y] += attr->y_translation;

		current = current->next;
	}

	// printf("Minimum Light Distance = %f\n", min_light_distance(coordinate));
}