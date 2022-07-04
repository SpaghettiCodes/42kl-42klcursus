/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:18 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:12:19 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n){
	size_t		i;
	char		*d;
	const char	*s;

	if (n && dest && src){
		d = (char *) dest;
		s = (const char *) src;
		i = 0;
		while (i < n){
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
