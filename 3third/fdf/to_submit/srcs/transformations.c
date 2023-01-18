/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:16:40 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 13:01:52 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// apparantly should work
// assumme light source at (0,0,D)
void	perspective_projection(t_coordinates *current, int light_dis)
{
	float	d_dz;

	d_dz = light_dis - current->trans_coord[Z];
	if (d_dz <= 0)
		d_dz = 1;
	current->projected_coord[X] = (light_dis * current->trans_coord[X]) / d_dz;
	current->projected_coord[Y] = (light_dis * current->trans_coord[Y]) / d_dz;
}

void	set_rot(t_coordinates *current, t_attri *attr)
{
	rotate_x(current, attr->rot[X]);
	rotate_y(current, attr->rot[Y]);
	rotate_z(current, attr->rot[Z]);
}

void	project(t_mlx *mlx, char type)
{
	t_coordinates	*current;
	t_attri			*attr;

	current = mlx->points;
	attr = &mlx->attributes;
	while (current)
	{
		current->trans_coord[X] = (current->coord[X] - attr->x_mid)
			* attr->line_size;
		current->trans_coord[Y] = (current->coord[Y] - attr->y_mid)
			* attr->line_size;
		current->trans_coord[Z] = (current->coord[Z] - attr->z_mid)
			* attr->line_size * attr->z_multiplier;
		set_rot(current, attr);
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
