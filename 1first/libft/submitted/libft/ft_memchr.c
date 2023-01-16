/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:12 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 17:55:40 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	size_t		i;


	s = (unsigned char *) str;
	i = 0;
	if (n)
	{
		while (i < n)
		{
			if (s[i] == (unsigned char)c)
				return ((void *) &s[i]);
			i++;
		}
	}
	return (0);
}
