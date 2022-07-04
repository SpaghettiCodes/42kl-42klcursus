/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:21 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:12:22 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n){
	int			i;
	size_t		srclen;
	char		*d;
	const char	*s;

	if (n && dest && src){
		d = (char *) dest;
		s = (const char *) src;
		srclen = (size_t) ft_strlen((char *) src);
		if (n > srclen)
			i = (int) srclen - 1;
		else
			i = (int) n - 1;
		while (i >= 0){
			d[i] = s[i];
			i--;
		}
	}
	return (dest);
}

