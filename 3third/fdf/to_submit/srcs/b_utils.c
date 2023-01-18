/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:10:38 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 12:14:08 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// set values for line utils
void	set_lineutils(t_lineutils *line,
		t_coordinates *n_point, t_coordinates *o_point)
{
	line->dx = n_point->projected_coord[X] - o_point->projected_coord[X];
	line->dy = n_point->projected_coord[Y] - o_point->projected_coord[Y];
	line->xi = 1;
	line->yi = 1;
	line->diff = (2 * line->dy) - line->dx;
	line->x = o_point->projected_coord[X];
	line->y = o_point->projected_coord[Y];
}

// go to the next point (for gentle lines)
void	next_ll(t_lineutils *line)
{
	if (line->diff > 0)
	{
		line->y += line->yi;
		line->diff = line->diff + (2 * (line->dy - line->dx));
	}
	else
		line->diff = line->diff + 2 * line->dy;
	line->x++;
}

// go to the next point (for steep lines)
void	next_hl(t_lineutils *line)
{
	if (line->diff > 0)
	{
		line->x += line->xi;
		line->diff = line->diff + (2 * (line->dx - line->dy));
	}
	else
		line->diff = line->diff + 2 * line->dx;
	line->y++;
}
