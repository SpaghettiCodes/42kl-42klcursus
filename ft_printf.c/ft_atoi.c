/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:10:53 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/05 11:04:00 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_jankyatoi(char c)
{
	return ((c <= '9' && c >= '0') || c == '+' || c == '-' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	result;
	int	negative;
	int	i;
	int	overflowed;

	i = 0;
	result = 0;
	while (ft_jankyatoi(str[i]))
	{
		if (str[i] <= '9' && str[i] >= '0')
			result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}
