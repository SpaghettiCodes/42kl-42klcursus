#include "fdf.h"

// rotattat is in radian btw
int	rotattat_x(t_coordinates *current, float radian)
{
	float	y;
	float	z;

	y = ( current->trans_coord[Y] * cos(radian)) - (current->trans_coord[Z] * sin(radian));
	z = ( current->trans_coord[Y] * sin(radian)) + (current->trans_coord[Z] * cos(radian));

	current->trans_coord[Y] = y;
	current->trans_coord[Z] = z;
}

int	rotattat_y(t_coordinates *current, float radian)
{
	float	x;
	float	z;
	
	x = (current->trans_coord[X] * cos(radian)) + (current->trans_coord[Z] * sin(radian));
	z = (current->trans_coord[Z] * cos(radian)) - (current->trans_coord[X] * sin(radian));

	current->trans_coord[X] = x;
	current->trans_coord[Z] = z;
}

int	rotattat_z(t_coordinates *current, float radian)
{
	float	x;
	float	y;

	x = (current->trans_coord[X] * cos(radian)) - (current->trans_coord[Y] * sin(radian));
	y = (current->trans_coord[X] * sin(radian)) + (current->trans_coord[Y] * cos(radian));

	current->trans_coord[X] = x;
	current->trans_coord[Y] = y;
}


// apparantly should work
// assumme light source at (0,0,D)
void	perspective_projection(t_coordinates *current, int light_dis)
{
	float	d_Dz;

	d_Dz = light_dis - current->trans_coord[Z];
	if (d_Dz <= 0)
		d_Dz = 1;

	current->projected_coord[X] = ((light_dis * current->trans_coord[X]) / d_Dz);
	current->projected_coord[Y] = ((light_dis * current->trans_coord[Y]) / d_Dz);
}

double	min_light_distance(t_coordinates *coordinates)
{
	t_coordinates	*ret;
	t_coordinates	*current;

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
	t_coordinates	*current;
	t_attri			*attr;

	current = mlx->points;
	attr = &mlx->attributes;
	while (current)
	{
		current->trans_coord[X] = (current->coord[X] - attr->x_mid ) * attr->line_size;
		current->trans_coord[Y] = (current->coord[Y] - attr->y_mid ) * attr->line_size;
		current->trans_coord[Z] = (current->coord[Z] - attr->z_mid ) * attr->line_size * attr->z_multiplier;
		rotattat_x(current, attr->rot[X]);
		rotattat_y(current, attr->rot[Y]);
		rotattat_z(current, attr->rot[Z]);
		if (type == 'o')
		{
			current->projected_coord[X] = current->trans_coord[X];
			current->projected_coord[Y] = current->trans_coord[Y];
		}
		else if (type == 'p')
			perspective_projection(current, attr->light_dis);
		current->projected_coord[X] += attr->x_translation;
		current->projected_coord[Y] += attr->y_translation;
		current = current->next;
	}
}