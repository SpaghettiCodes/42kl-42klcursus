/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:47:16 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/14 13:29:56 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_substr(char *str, int start, int len)
{
	char	*substr;
	int		i;

	i = 0;
	substr = (char *) malloc (len + 1);
	while (i < len)
	{
		substr[i] = str[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*str_join(char *str1, char *str2)
{
	char	*strjoined;
	int		i;
	int		j;

	i = 0;
	j = 0;
	strjoined = (char *) malloc ((str_len(str1)
				+ str_len(str2) + 1) * sizeof(char));
	while (str1 && str1[i])
	{
		strjoined[i] = str1[i];
		i++;
	}
	while (str2 && str2[j])
	{
		strjoined[i] = str2[j];
		i++;
		j++;
	}
	strjoined[i] = '\0';
	free(str1);
	return (strjoined);
}
