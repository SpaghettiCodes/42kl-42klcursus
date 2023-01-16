/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:13:12 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 11:09:02 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, char const *set)
{
	int	i;

	i = -1;
	while (set[++i] != '\0')
		if (set[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		begin;
	int		size;
	int		end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	begin = -1;
	size = ft_strlen(s1);
	end = size;
	while (ft_inset(s1[++begin], set) == 1)
		size--;
	if (begin != end)
	{
		while (ft_inset(s1[--end], set) == 1)
			size--;
		trimmed = ft_substr(s1, begin, size);
	}
	else
		trimmed = ft_strdup("");
	if (trimmed)
		return (trimmed);
	return (0);
}
