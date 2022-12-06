/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:48 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 15:15:29 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split.h"

int	ft_strlen(const char *s)
{
	int	i;
	
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return(i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		slen;

	slen = ft_strlen(s);
	dup = (char *) malloc ((slen + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
