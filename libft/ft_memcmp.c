/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:16 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:39:22 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const char	*s1;
	const char	*s2;
	size_t		i;

	if (str1 && str2 && n)
	{
		s1 = (const char *) str1;
		s2 = (const char *) str2;
		i = 0;
		while (i < n)
		{
			if (s1[i] != s2[i])
				return ((s1[i] - s2[i]));
			i++;
		}
	}
	return (0);
}
