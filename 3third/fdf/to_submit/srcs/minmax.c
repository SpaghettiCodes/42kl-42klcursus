/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:15:42 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 12:55:04 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	highest_x(t_coordinates *coordinates)
{
	t_coordinates	*current;

	current = coordinates;
	while (current->beside)
	{
		current = current->beside;
	}
	return (current->coord[X]);
}

int	highest_y(t_coordinates *coordinates)
{
	t_coordinates	*current;

	current = coordinates;
	while (current->below)
	{
		current = current->below;
	}
	return (current->coord[Y]);
}

int	highest_z(t_coordinates *coordinates)
{
	t_coordinates	*ret;
	t_coordinates	*current;

	ret = coordinates;
	current = coordinates;
	while (current)
	{
		if (ret->coord[Z] < current->coord[Z])
		{
			ret = current;
		}
		current = current->next;
	}
	return (ret->coord[Z]);
}

int	lowest_z(t_coordinates *coordinates)
{
	t_coordinates	*ret;
	t_coordinates	*current;

	ret = coordinates;
	current = coordinates;
	while (current)
	{
		if (ret->coord[Z] > current->coord[Z])
		{
			ret = current;
		}
		current = current->next;
	}
	return (ret->coord[Z]);
}
