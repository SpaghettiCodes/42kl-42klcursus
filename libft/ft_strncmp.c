/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:13:04 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:13:05 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n){
	size_t	i;

	i = 0;
	while (i < n){
		if (str1[i] != str2[i])
			return ((str1[i] - str2[i]));
		if (str1[i] == '\0' && str2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
