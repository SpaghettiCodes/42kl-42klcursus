/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:31 by cshi-xia          #+#    #+#             */
/*   Updated: 2023/01/18 15:01:13 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strfind(char *haystack, char *needle)
{
	int	i;

	i = 0;
	if (!haystack || !needle)
		return (0);
	while (haystack[i] == needle[i])
	{
		if (!needle[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strcmp_nl(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i])
	{
		if (str1[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*append(char *str1, char *str2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	free(str1);
	return (ret);
}

char	*n_append(char *str1, char *str2)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc (ft_strlen(str1) + ft_strlen(str2) + 1);
	i = -1;
	while (str1[++i])
		ret[i] = str1[i];
	j = 0;
	while (str2[j])
	{
		ret[i] = str2[j];
		j++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
