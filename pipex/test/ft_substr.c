/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:13:14 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 18:03:47 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	if (s)
	{
		if (!len || start > (unsigned int) ft_strlen(s))
			return (ft_strdup(""));
		substr = (char *) malloc ((len + 1) * sizeof(char));
		if (substr)
		{
			i = -1;
			while (++i < (int) len && s[start])
			{
				substr[i] = s[start];
				start++;
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (0);
}
