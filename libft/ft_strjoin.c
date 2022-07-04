/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:52 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:33:07 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		s1len;
	int		s2len;

	if (!s1 && !s2)
		return (0);
	s1len = ft_strlen((char *) s1);
	s2len = ft_strlen((char *) s2);
	joined = (char *) malloc ((s1len + s2len + 1) * sizeof(char));
	if (!joined)
		return (0);
	ft_strlcpy(joined, s1, (s1len + 1));
	ft_strlcpy((joined + s1len), s2, (s2len + 1));
	return (joined);
}
