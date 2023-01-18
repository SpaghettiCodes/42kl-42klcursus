/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:11:25 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/17 22:12:10 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	set_color(int plot_y, t_coordinates *o_point,
	t_coordinates *n_point, t_attri attr)
{
	float	z;

	z = calc_z(n_point, o_point, plot_y);
	z *= attr.color_intens;
	if (z > 0)
		return (det_color_p(z, attr));
	else
		return (det_color_n(z, attr));
}

void	color_choice(int *r, int *g, int *b, t_attri attr)
{
	int	temp;

	if (attr.color_type == RG)
		return ;
	else if (attr.color_type == NO)
	{
		*r = 255;
		*g = 255;
		*b = 255;
	}
	else if (attr.color_type == BG)
		swap(b, r);
	else if (attr.color_type == RB)
		swap(g, b);
	else if (attr.color_type == GR)
		swap(r, g);
	else if (attr.color_type == YB)
	{
		temp = *g;
		*g = *r;
		*b = temp;
	}
}

int	det_color_p(int z, t_attri attr)
{
	int	r;
	int	g;
	int	b;
	int	diff;

	diff = 0;
	if (z > 255)
	{
		diff = z - 255;
		z = 255;
	}
	r = 255 - diff;
	if (r < 50)
		r = 50;
	g = 255 - z;
	if (g < 0)
		g = 0;
	b = 255 - z;
	if (b < 0)
		b = 0;
	color_choice(&r, &g, &b, attr);
	return (putcolor(0, r, g, b));
}

int	det_color_n(int z, t_attri attr)
{
	int	r;
	int	g;
	int	b;
	int	diff;

	z *= -1;
	diff = 0;
	if (z > 255)
	{
		diff = z - 255;
		z = 255;
	}
	r = 255 - z;
	if (r < 0)
		r = 0;
	g = 255 - diff;
	if (g < 50)
		g = 50;
	b = 255 - z;
	if (b < 0)
		b = 0;
	color_choice(&r, &g, &b, attr);
	return (putcolor(0, r, g, b));
}
