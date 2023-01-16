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

// returns a MALLOCED substring that starts at "start" and with the length of "len"
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

// returns a MALLOCED substring that starts at "start" and stops at "end"
char	*ft_substr2(char const *s, unsigned int start, unsigned int end)
{
	char	*substr;
	int		i;

	if (s)
	{
		i = 0;
		if (start > end || start > (unsigned int) ft_strlen(s))
			return (ft_strdup(""));
		substr = (char *) malloc (((end - start) + 1 + 1) * sizeof(char));
		if (substr)
		{
			while (start <= end && s[start])
			{
				substr[i] = s[start];
				start++;
				i++;
			}
			substr[i] = '\0';
			return (substr);
		}
	}
	return (0);
}
