/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:58 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 15:13:06 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		srclen;
	size_t	z;

	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize)
	{
		z = 0;
		while (z < (dstsize - 1) && src[z] != '\0')
		{
			dst[z] = src[z];
			z++;
		}
		dst[z] = '\0';
	}
	return (srclen);
}
