/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:13:07 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:13:08 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len){
	int	i;
	int	j;
	int firstseen;

	i = -1;
	if (len) {
		if (little[0] == '\0')
			return ((char *) big);
		while (big[++i] != '\0' && i < (int) len){
			if (big[i] == little[0]){
				firstseen = i;
				j = 0;
				while (big[++i] == little[++j]){
					if (little[j+1] == '\0')
						return ((char *) &big[firstseen]);
				}
				i = firstseen + 1;
			}
		}
	}
	return (0);
}
