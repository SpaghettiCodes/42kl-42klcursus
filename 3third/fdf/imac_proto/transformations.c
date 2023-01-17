#include "fdf.h"

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
		rotate_x(current, attr->rot[X]);
		rotate_y(current, attr->rot[Y]);
		rotate_z(current, attr->rot[Z]);
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
