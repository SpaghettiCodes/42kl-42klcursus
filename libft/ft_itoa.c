/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:11:17 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/05 10:45:39 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoaneg(unsigned int n)
{
	char			*str;
	int				digits;
	unsigned int	n2;

	digits = 1;
	n2 = n;
	while (n2 >= 10)
	{
		n2 /= 10;
		digits++;
	}
	digits++;
	str = (char *) malloc ((digits + 2) * sizeof(int));
	if (!str)
		return (0);
	str[0] = '-';
	str[digits] = '\0';
	while (--digits != 0)
	{
		str[digits] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digits;
	int		n2;

	if (n < 0)
		return (ft_itoaneg((unsigned int)(n * -1)));
	digits = 0;
	n2 = n;
	while (n2 >= 10)
	{
		n2 /= 10;
		digits++;
	}
	digits++;
	str = (char *) malloc ((digits + 1) * sizeof(int));
	if (!str)
		return (0);
	str[digits] = '\0';
	while (--digits != -1)
	{
		str[digits] = (char)((n % 10) + '0');
		n /= 10;
	}
	return (str);
}
