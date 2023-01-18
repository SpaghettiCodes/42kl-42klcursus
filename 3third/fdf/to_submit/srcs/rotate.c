/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:16:14 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 22:16:37 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// rotattat is in radian btw
int	rotate_x(t_coordinates *current, float radian)
{
	float	y;
	float	z;

	y = (current->trans_coord[Y] * cos(radian))
		- (current->trans_coord[Z] * sin(radian));
	z = (current->trans_coord[Y] * sin(radian))
		+ (current->trans_coord[Z] * cos(radian));

	current->trans_coord[Y] = y;
	current->trans_coord[Z] = z;
}

int	rotate_y(t_coordinates *current, float radian)
{
	float	x;
	float	z;
	
	x = (current->trans_coord[X] * cos(radian))
		+ (current->trans_coord[Z] * sin(radian));
	z = (current->trans_coord[Z] * cos(radian))
		- (current->trans_coord[X] * sin(radian));

	current->trans_coord[X] = x;
	current->trans_coord[Z] = z;
}

int	rotate_z(t_coordinates *current, float radian)
{
	float	x;
	float	y;

	x = (current->trans_coord[X] * cos(radian))
		- (current->trans_coord[Y] * sin(radian));
	y = (current->trans_coord[X] * sin(radian))
		+ (current->trans_coord[Y] * cos(radian));

	current->trans_coord[X] = x;
	current->trans_coord[Y] = y;
}
