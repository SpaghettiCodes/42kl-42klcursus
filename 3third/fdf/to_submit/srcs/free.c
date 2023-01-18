/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:13:01 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 22:13:02 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	freeall(char *line, char **coordinates)
{
	int	i;

	if (line)
		free(line);
	i = 0;
	if (coordinates)
	{
		while (coordinates[i])
		{
			free(coordinates[i]);
			i++;
		}
		free(coordinates);
	}
}
