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

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c == 32) || (c >= 9 && c <= 13));
}

static int	overflow(int result, int neg, char nextnum)
{
	if (result <= 214748364)
	{
		if (result == 214748364)
			if ((nextnum <= '7' && neg == 1) || (nextnum <= '8' && neg == -1))
				return (1);
		else
			return (1);
	}
	if (neg == -1)
		return (0);
	else // if (neg == 1)
		return (-1);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	negative;
	int	i;
	int	overflowed;

	i = 0;
	result = 0;
	negative = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		negative = -1;
	else if (str[i] == '+' && ++i){};
	while (str[i] >= '0' && str[i] <= '9')
	{
		overflowed = overflow(result, negative, str[i]);
		if (overflowed == 1)
		{
			result = (result * 10) + (str[i] - '0');
			i++;
		}
		else
			return (overflowed);
	}
	return (result * negative);
}
