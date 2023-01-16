/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:47:21 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/17 18:49:46 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(t_properties *flag, char c)
{
	if (c == '-')
	{
		flag->place_space = 1;
		flag->l_aligned = 1;
	}
	else if (c == '+')
	{
		flag->place_space_front = 0;
		flag->sign = 1;
	}
	else if (c == ' ')
	{
		if (!flag->sign)
			flag->place_space_front = 1;
	}
	else if (c == '0')
		flag->place_zero = 1;
	else if (c == '#')
		flag->prefix = 1;
	else
		return (0);
	return (1);
}

int	check_width(t_properties *flag, char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
	{
		if (!flag->place_zero)
			flag->place_space = 1;
		if (c == '*')
			flag->width = -2;
	}
	else
		return (0);
	return (1);
}

int	check_preci(t_properties *flag, char *format)
{
	int	i;

	i = 0;
	flag->place_space = 1;
	flag->place_zero = 0;
	if (format[i] == '*' && ++i)
		flag->preci = -2;
	else
	{
		flag->preci = ft_atoi(&format[i]);
		while ((format[i] >= '0' && format[i] <= '9'))
			i++;
	}
	return (i);
}
