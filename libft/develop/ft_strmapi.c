/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:13:02 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/06 11:08:45 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		slen;
	char	*mapped;
	int		i;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	mapped = (char *) malloc ((slen + 1) * sizeof(char));
	if (!mapped)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		mapped[i] = f(i, s[i]);
	mapped[i] = '\0';
	return (mapped);
}
