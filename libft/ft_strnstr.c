/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:13:07 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/05 13:01:25 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	firstseen;
	int	foundword;
	int	littlelen;

	i = -1;
	littlelen = ft_strlen((char *)little);
	if (little[0] == '\0')
		return ((char *) big);
	while (big[++i] != '\0' && i < (int)len)
	{
		if (big[i] == little[0])
		{
			foundword = 0;
			firstseen = i;
			j = 0;
			while (big[++i] == little[++j] && i < (int)len && ++foundword)
				if (little[j + 1] == '\0' && ++foundword == littlelen)
					return ((char *) &big[firstseen]);
			i = firstseen + 1;
		}
	}
	return (0);
}
