/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:13:07 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 15:31:38 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	firstseen;
	int	foundword;

	i = -1;
	if (little[0] == '\0')
		return ((char *) big);
	while (big[++i] != '\0' && i < (int)len)
	{
		if (big[i] == little[0])
		{
			foundword = 1;
			firstseen = i;
			if (ft_strlen(little) == 1)
				return ((char *) &big[firstseen]);
			j = 0;
			while (big[++i] == little[++j] && i < (int)len && ++foundword)
				if (little[j + 1] == '\0' && foundword == ft_strlen(little))
					return ((char *) &big[firstseen]);
			i = firstseen;
		}
	}
	return (0);
}
