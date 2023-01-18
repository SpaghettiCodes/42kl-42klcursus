/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_buffer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:18:16 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 22:18:41 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**z_buffer(t_mlx mlx)
{
	int	**ret;
	int	x;
	int	y;

	ret = malloc (sizeof(int *) * mlx.length);
	x = 0;
	while (x < mlx.length)
	{
		ret[x] = malloc (sizeof(int) * mlx.width);
		x++;
	}
	return (ret);
}

void	freebuffer(int **tab, t_mlx mlx)
{
	int	x;

	x = 0;
	while (x < mlx.length)
	{
		free(tab[x]);
		x++;
	}
	free(tab);
}

void	set(int **tab, t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < mlx->length)
	{
		y = 0;
		while (y < mlx->width)
		{
			tab[x][y] = INT_MIN;
			y++;
		}
		x++;
	}
}