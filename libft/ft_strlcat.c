/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:31:29 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:31:49 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;
	int		j;

	destlen = ft_strlen(dest);
	srclen = ft_strlen((char *) src);
	if (size == 0 || (destlen > size))
		return (srclen + size);
	j = 0;
	i = destlen;
	while (i < (size - 1) || src[j] == '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}
