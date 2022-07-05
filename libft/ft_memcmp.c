/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:16 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/05 11:23:01 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	if (str1 && str2 && n)
	{
		s1 = (unsigned char *)str1;
		s2 = (unsigned char *)str2;
		i = 0;
		while (i < n)
		{
			if (s1[i] > s2[i])
				return (1);
			if (s1[i] < s2[i])
				return (-1);
			i++;
		}
	}
	return (0);
}
