/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:24 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 14:57:05 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;
	char	*d;

	d = (char *) dest;
	i = 0;
	while (i < count)
		d[i++] = c;
	return (dest);
}
